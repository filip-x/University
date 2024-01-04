package com.pdp;

import mpi.MPI;

import java.util.ArrayList;
import java.util.List;

public class ComputingWorker {
    private int start;
    private int end;
    private int N;
    private List<Integer> a;
    private List<Integer> b;
    private List<Integer> solution;


    public ComputingWorker(int start, int end, int n, List<Integer> a, List<Integer> b) {
        this.start = start;
        this.end = end;
        N = n;
        this.a = a;
        this.b = b;
        this.solution = new ArrayList<>();
    }

    public void run() {
        for (int k = start; k <= end; k++) {
            int r = 0;
            for (int i = 0; i < N; i++) {
                int kMinusI = (k - i) % N;
                if (kMinusI < 0)
                    kMinusI += N;
                r += a.get(i) * b.get(kMinusI);
            }
            solution.add(r);
        }

        MPI.COMM_WORLD.Send(new Object[]{solution}, 0, 1, MPI.OBJECT, 0, 6);
    }
}
