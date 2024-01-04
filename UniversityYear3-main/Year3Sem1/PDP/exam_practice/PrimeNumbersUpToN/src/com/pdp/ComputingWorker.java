package com.pdp;

import mpi.MPI;

import java.util.ArrayList;
import java.util.List;

public class ComputingWorker {
    private int start;
    private int end;
    private List<Integer> solution;
    private List<Integer> primesToRadicalN;

    public ComputingWorker(int start, int end, List<Integer> primesToRadicalN) {
        this.start = start;
        this.end = end;
        this.solution = new ArrayList<>();
        this.primesToRadicalN = primesToRadicalN;
    }

    public void run() {
        for (int i = start; i <= end; i++) {
            if (isPrime(i)) {
                solution.add(i);
            }
        }

        MPI.COMM_WORLD.Send(new Object[]{solution}, 0, 1, MPI.OBJECT, 0, 4);
    }

    // if we found the prime numbers from [2, ..., number - 1], we can use those to compute
    // for number
    public boolean isPrime(int number) {
        for (int prime : primesToRadicalN) {
            if (prime > number)
                return true;
            if (number % prime == 0)
                return false;
        }
        return true;
    }
}
