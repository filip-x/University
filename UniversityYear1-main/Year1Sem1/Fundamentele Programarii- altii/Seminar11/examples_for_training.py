#for i:= 1 to n^2:
#    for j:= 1 to 1000000000: # constant time, maybe a week , but still 1 
#        print(x)


#n = len(l) l...iter...
#T(n)=$(sum from i=1 to n) log(base 3) to n = n log(base 3) to n
def f2(l):
    sum=0
    for el in l:
        j=len(l)
        while j>1:
            sum+=el*j
            j=j//3
    return sum 

#T(n)= 1, n<=1 
#      2T(n/2)+n,n>1 (memorypy)
#T(n) = 2T(n/2)+n=2[2T(n/4)+n/2]+n
#T(n) = 2^2 T(n/2^2)+n+n
# 2^k = n     1        k 
# T(n) = n + nlog(2)n
# T(n) in O(nlogn)
# V2 : n+log(2) n 
def sumR(l):
    if l==[]:
        return 0
    if len(l)==1:
        return l[0]
    m=len(l)/2
    return sumR(l[:m])+sumR(l[m:])
