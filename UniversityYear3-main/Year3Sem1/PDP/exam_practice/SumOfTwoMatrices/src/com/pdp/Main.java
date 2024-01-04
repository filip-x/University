package com.pdp;

import mpi.*;

import java.util.ArrayList;
import java.util.List;

public class Main {
    private static int N = 3;
    private static List<List<Integer>> matrixA = List.of(List.of(1, 2, 3), List.of(4, 5, 6), List.of(7, 8, 9));
    private static List<List<Integer>> matrixB = List.of(List.of(1, 2, 3), List.of(4, 5, 6), List.of(7, 8, 9));

    public static void main(String[] args) {
        MPI.Init(args);

        if (MPI.COMM_WORLD.Rank() == 0) {
            splitWork();
            printSolution();
        }
        else {
            runComputingProcess();
        }

        MPI.Finalize();
    }

    public static void splitWork() {
        int nrsPerThread = N * N / (MPI.COMM_WORLD.Size() - 1);

        for (int i = 0; i < MPI.COMM_WORLD.Size() - 1; i++) {
            int start = i * nrsPerThread;
            int end  = (i + 1) * nrsPerThread - 1;

            if (i == MPI.COMM_WORLD.Size() - 2)
                end = N * N - 1;

            MPI.COMM_WORLD.Send(new int[]{start}, 0, 1, MPI.INT, i + 1, 1);
            MPI.COMM_WORLD.Send(new int[]{end}, 0, 1, MPI.INT, i + 1, 2);
            MPI.COMM_WORLD.Send(new int[]{N}, 0, 1, MPI.INT, i + 1, 3);
            MPI.COMM_WORLD.Send(new Object[]{matrixA}, 0, 1, MPI.OBJECT, i + 1, 4);
            MPI.COMM_WORLD.Send(new Object[]{matrixB}, 0, 1, MPI.OBJECT, i + 1, 5);
        }
    }

    public static void printSolution() {
        List<Integer> solution = new ArrayList<>();

        Object[] partialSolution = new Object[1];

        for (int i = 1; i < MPI.COMM_WORLD.Size(); i++) {
            MPI.COMM_WORLD.Recv(partialSolution, 0, 1, MPI.OBJECT, i, 6);

            solution.addAll((List<Integer>)partialSolution[0]);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(solution.get(i * N + j) + " ");
            }
            System.out.println("");
        }
    }

    public static void runComputingProcess() {
        int[] start = new int[1];
        int[] end = new int[1];
        int[] n = new int[1];
        Object[] matrixA = new Object[1];
        Object[] matrixB = new Object[1];

        MPI.COMM_WORLD.Recv(start, 0, 1, MPI.INT, 0, 1);
        MPI.COMM_WORLD.Recv(end, 0, 1, MPI.INT, 0, 2);
        MPI.COMM_WORLD.Recv(n, 0, 1, MPI.INT, 0, 3);
        MPI.COMM_WORLD.Recv(matrixA, 0, 1, MPI.OBJECT, 0, 4);
        MPI.COMM_WORLD.Recv(matrixB, 0, 1, MPI.OBJECT, 0, 5);

        ComputingWorker worker = new ComputingWorker(start[0], end[0], n[0], (List<List<Integer>>)matrixA[0],
                (List<List<Integer>>)matrixB[0]);
        worker.run();
    }
}
