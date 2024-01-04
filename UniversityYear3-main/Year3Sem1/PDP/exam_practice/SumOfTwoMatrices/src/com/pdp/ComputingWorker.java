package com.pdp;

import mpi.MPI;

import java.util.ArrayList;
import java.util.List;

public class ComputingWorker {
    private int start;
    private int end;
    private int N;
    private List<List<Integer>> matrixA;
    private List<List<Integer>> matrixB;
    private List<Integer> solution;

    public ComputingWorker(int start, int end, int n, List<List<Integer>> matrixA, List<List<Integer>> matrixB) {
        this.start = start;
        this.end = end;
        N = n;
        this.matrixA = matrixA;
        this.matrixB = matrixB;
        this.solution = new ArrayList<>();
    }

    public void run() {
        for (int i = start; i <= end; i++) {
            int line = i / N;
            int col = i % N;

            int rez = this.matrixA.get(line).get(col) + this.matrixB.get(line).get(col);
            solution.add(rez);
        }

        MPI.COMM_WORLD.Send(new Object[]{solution}, 0, 1, MPI.OBJECT, 0, 6);
    }
}
