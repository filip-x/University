HTTP/1.1 200 OK
Date: Wed, 17 Nov 2021 07:16:48 GMT
Server: Apache
Last-Modified: Sun, 10 Dec 2017 20:18:34 GMT
ETag: "7c4716-2067-560021f3f5a80"
Accept-Ranges: bytes
Content-Length: 8295
Vary: Accept-Encoding,User-Agent
Content-Type: text/plain

#include <iostream>
#include <mpi.h>
#include <vector>
#include <time.h>
#include <stdint.h>
#include <math.h>

using namespace std;

// The program computes the product of two matrices, A and B by using Canon's algorithms.
// The matrices must be square, NxN, matrices.
// The cumputing nodes (processes) are also arranged in a square, compSize x compSize,
// and N must be a multiple of compSize.
// The node 0 has the initial matrices, and distributes sub-matrices of size chunkSize x chunkSize,
// where chumkSize = N / compSize, to each node.
// Next, the algorithm performs compSize rounds, in each round each node performs a multiplication of
// two matrices of size chumkSize x chunkSize, and then it passes the chunk of A to the left and the chunk of B upwards.
// After the last round, the node 0 collects the result.


void doWork(size_t chunkSize, vector<int>& a, vector<int>& b, vector<int>& c,
    size_t me, size_t compSize)
{
    c.resize(a.size(), 0);
    size_t const me_i = me / compSize;
    size_t const me_j = me % compSize;

    size_t iter = 0;
    while(true) {
        std::cout << me << ":Computing\n";
        for (size_t i=0 ; i<chunkSize ; ++i){
            for (size_t j=0 ; j<chunkSize ; ++j){
                for(size_t k=0 ; k<chunkSize ; ++k){
                    c[chunkSize*i+j] += a[chunkSize*i+k]*b[chunkSize*k+j];
                }
            }
        }

        ++iter;
        if(iter == compSize) return;
        
        std::cout << me << ":Exchanging A on line\n";
        MPI_Status status;
        vector<int> tmp;
        if(me_j == 0){
            tmp.resize(a.size());
            MPI_Recv(tmp.data(), a.size(), MPI_INT,
                me_i*compSize+(compSize-1), 4, MPI_COMM_WORLD, &status);
            MPI_Ssend(a.data(), a.size(), MPI_INT,
                me_i*compSize+1, 4, MPI_COMM_WORLD);
            a = tmp;
        } else {
            MPI_Ssend(a.data(), a.size(), MPI_INT,
                me_i*compSize+((me_j+1)%compSize), 4, MPI_COMM_WORLD);
            MPI_Recv(a.data(), a.size(), MPI_INT,
                me_i*compSize+(me_j+compSize-1)%compSize, 4, MPI_COMM_WORLD, &status);
        }

        std::cout << me << ":Exchanging B on column\n";
        if(me_i == 0){
            tmp.resize(b.size());
            MPI_Recv(tmp.data(), b.size(), MPI_INT,
                (compSize-1)*compSize+me_j, 5, MPI_COMM_WORLD, &status);
            MPI_Ssend(b.data(), b.size(), MPI_INT,
                ((me_i+1)%compSize)*compSize+me_j, 5, MPI_COMM_WORLD);
            b = tmp;
        } else {
            MPI_Ssend(b.data(), b.size(), MPI_INT,
                ((me_i+1)%compSize)*compSize+me_j, 5, MPI_COMM_WORLD);
            MPI_Recv(b.data(), b.size(), MPI_INT,
                ((me_i+compSize-1)%compSize)*compSize+me_j, 5, MPI_COMM_WORLD, &status);
        }
    }
}

/// @brief Top function for the root process.
//
// It distributes chunks to all other processes, then it performs the computation rounds corresponding to the
// upper-left sub-matrix of the result, and finally it reads the chunks from the other nodes
void initialWorker(size_t n, vector<int> const& a, vector<int> const& b, vector<int>& c, size_t compSize)
{
    vector<int> aa;
    vector<int> bb;
    vector<int> cc;
    size_t const chunkSize = n / compSize;
    std::cout << "Nr workers=" << compSize << "*" << compSize << "\n";
    // distribute to children
    vector<int> tmpa;
    vector<int> tmpb;
    tmpa.resize(chunkSize*chunkSize);
    tmpb.resize(chunkSize*chunkSize);
    for(size_t ic = 0 ; ic < compSize ; ++ic) {
        for(size_t jc = 0 ; jc < compSize ; ++jc) {
            // node at coordinates (ic,jc) receives the sub-matrix at coordinates (ic, jc+ic) from A and (ic+jc, jc) from B
            for(size_t i=0 ; i<chunkSize ; ++i){
                for(size_t j=0 ; j<chunkSize ; ++j){
                    tmpa[i*chunkSize+j] = a[(ic*chunkSize+i)*n + (((jc+ic)%compSize)*chunkSize+j)];
                    tmpb[i*chunkSize+j] = b[(((ic+jc)%compSize)*chunkSize+i)*n + (jc*chunkSize+j)];
                }
            }
            if(ic!=0 || jc!=0){
                std::cout << "Sending initial data to " << ic << "x" << jc << "\n";
                MPI_Send(tmpa.data(), chunkSize*chunkSize, MPI_INT, ic*compSize+jc, 1, MPI_COMM_WORLD);
                MPI_Send(tmpb.data(), chunkSize*chunkSize, MPI_INT, ic*compSize+jc, 2, MPI_COMM_WORLD);
            } else {
                aa = tmpa;
                bb = tmpb;
            }
        }
    }
    // local computation
    doWork(chunkSize, aa, bb, cc, 0, compSize);
    // receive from children
    MPI_Status status;
    for(size_t ic = 0 ; ic < compSize ; ++ic) {
        for(size_t jc = 0 ; jc < compSize ; ++jc) {
            if(ic!=0 || jc!=0){
                std::cout << "Receiving final data from (" << ic << ", " << jc << ")\n";
                MPI_Recv(tmpa.data(), chunkSize*chunkSize, MPI_INT, ic*compSize+jc, 3, MPI_COMM_WORLD, &status);
            } else {
                tmpa = cc;
            }
            for(size_t i=0 ; i<chunkSize ; ++i){
                for(size_t j=0 ; j<chunkSize ; ++j){
                    c[(ic*chunkSize+i)*n + (jc*chunkSize+j)] = tmpa[i*chunkSize+j];
                }
            }
        }
    }
}

// A function that determines the parent of the current process (the process that
// will give the part to be sorted. It also determines the size of the part to be sorted
// and executes the sorting (receives the data, calls mergeSortRec() to do the actual work,
// and finally sends back the result.
void worker(size_t n, size_t me, size_t compSize)
{
    int chunkSize = n / compSize;
    vector<int> aa;
    vector<int> bb;
    vector<int> cc;
    
    // receive the initial data from the parent
    aa.resize(chunkSize*chunkSize);
    bb.resize(chunkSize*chunkSize);
    MPI_Status status;
    std::cout << me << ":Receiving initial data\n";
    MPI_Recv(aa.data(), chunkSize*chunkSize, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
    MPI_Recv(bb.data(), chunkSize*chunkSize, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);

    // do the local work
    cc.resize(chunkSize*chunkSize, 0);
    doWork(chunkSize, aa, bb, cc, me, compSize);
    
    // send back the result to the parent
    std::cout << me << ":Sending final data\n";
    MPI_Ssend(cc.data(), chunkSize*chunkSize, MPI_INT, 0, 3, MPI_COMM_WORLD);
}

void generate(vector<int>& matr, size_t n)
{
    matr.reserve(n*n);
    for(size_t i=0 ; i<n*n ; ++i) {
        //matr.push_back(rand());
        matr.push_back(i/n + i%n);
    }
}

int getCompSize(int nrProcs)
{
    int r = (int)sqrt(nrProcs);
    if( (r+1)*(r+1) <= nrProcs ) return r+1;
    return r;
}

int main(int argc, char** argv)
{
    MPI_Init(0, 0);
    int me;
    int nrProcs;
    MPI_Comm_size(MPI_COMM_WORLD, &nrProcs);
    MPI_Comm_rank(MPI_COMM_WORLD, &me);

    unsigned n;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    if(argc != 2 || 1!=sscanf(argv[1], "%u", &n) ){
        fprintf(stderr, "usage: matrix-mpi <n>\n");
        return 1;
    }
    int compSize = getCompSize(nrProcs);
    nrProcs = compSize*compSize;
    if(n % compSize != 0){
        fprintf(stderr, "Wrong number of processes\n");
        return 1;
    }

    if(me == 0) {
        generate(a, n);
        generate(b, n);
        c.reserve(n*n);
        std::cout << "generated\n";
    }
    
    struct timespec beginTime;
    clock_gettime(CLOCK_REALTIME, &beginTime);
    
    if(me == 0) {
        initialWorker(n, a, b, c, compSize);
    } else if(me < nrProcs) {
        worker(n, me, compSize);
    }
    
    struct timespec endTime;
    clock_gettime(CLOCK_REALTIME, &endTime);
    int64_t const elapsedNs = (int64_t(endTime.tv_sec) - int64_t(beginTime.tv_sec))*1000000000LL
        + int64_t(endTime.tv_nsec) - int64_t(beginTime.tv_nsec);

    cout << "Elapsed time=" <<  (elapsedNs/1000000) <<"ms\n";
    if(me == 0) {
        bool ok = true;
        for(size_t i=0 ; i<n ; ++i){
            for(size_t j=0 ; j<n ; ++j){
                int tmp = 0;
                for(size_t k=0 ; k<n ; ++k) {
                    tmp += a[i*n+k]*b[k*n+j];
                }
                if(tmp != c[i*n+j]) ok=false;
            }
        }
        cout << (ok ? "Ok\n" : "WRONG\n");
    }
    
    MPI_Finalize();
}
                                                                                                                                                        