package com.pdp;

import mpi.MPI;

import java.util.ArrayList;
import java.util.List;

public class ComputingWorker {
    private int start;
    private int end;
    private int matrixSize;
    private List<List<Integer>> matrix1;
    private List<List<Integer>> matrix2;

    private List<Integer> solution;

    public ComputingWorker(int start, int end, int matrixSize, List<List<Integer>> matrix1, List<List<Integer>> matrix2) {
        this.start = start;
        this.end = end;
        this.matrixSize = matrixSize;
        this.matrix1 = matrix1;
        this.matrix2 = matrix2;
        this.solution = new ArrayList<>();
    }

    public void run() {
        for (int k = start; k <= end; k++) {
            int line = k / matrixSize;
            int col = k % matrixSize;

            int rez = 0;

            for (int i = 0; i < matrixSize; i++) {
                rez += matrix1.get(line).get(i) * matrix2.get(i).get(col);
            }

            solution.add(rez);
        }

        MPI.COMM_WORLD.Send(new Object[]{solution}, 0, 1, MPI.OBJECT, 0, 6);
    }
}
