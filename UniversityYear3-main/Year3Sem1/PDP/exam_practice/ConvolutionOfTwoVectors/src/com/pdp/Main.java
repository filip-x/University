package com.pdp;

import mpi.*;

import java.util.ArrayList;
import java.util.List;

public class Main {
    private static Integer N = 10;
    private static List<Integer> A = List.of(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    private static List<Integer> B = List.of(10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

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
        int nrPerThreads = N / (MPI.COMM_WORLD.Size() - 1);

        for (int i = 0; i < MPI.COMM_WORLD.Size() - 1; i++) {
            int start = i * nrPerThreads;
            int end = (i + 1) * nrPerThreads - 1;

            if (i == MPI.COMM_WORLD.Size() - 2) {
                end = N - 1;
            }

            MPI.COMM_WORLD.Send(new int[]{start}, 0, 1, MPI.INT, i + 1, 1);
            MPI.COMM_WORLD.Send(new int[]{end}, 0, 1, MPI.INT, i + 1, 2);
            MPI.COMM_WORLD.Send(new int[]{N}, 0, 1, MPI.INT, i + 1, 3);
            MPI.COMM_WORLD.Send(new Object[]{A}, 0, 1, MPI.OBJECT, i + 1, 4);
            MPI.COMM_WORLD.Send(new Object[]{B}, 0, 1, MPI.OBJECT, i + 1, 5);
        }
    }

    public static void printSolution() {
        List<Integer> solution = new ArrayList<>();
        Object[] sol = new Object[1];

        for (int i = 1; i < MPI.COMM_WORLD.Size(); i++) {
            MPI.COMM_WORLD.Recv(sol, 0, 1, MPI.OBJECT, i, 6);

            solution.addAll((List<Integer>)sol[0]);
        }

        System.out.println("The solution is: " + solution);
    }

    public static void runComputingProcess() {
        int[] start = new int[1];
        int[] end = new int[1];
        int[] n = new int[1];
        Object[] a = new Object[1];
        Object[] b = new Object[1];
        MPI.COMM_WORLD.Recv(start, 0, 1, MPI.INT, 0, 1);
        MPI.COMM_WORLD.Recv(end, 0, 1, MPI.INT, 0, 2);
        MPI.COMM_WORLD.Recv(n, 0, 1, MPI.INT, 0, 3);
        MPI.COMM_WORLD.Recv(a, 0, 1, MPI.OBJECT, 0, 4);
        MPI.COMM_WORLD.Recv(b, 0, 1, MPI.OBJECT, 0, 5);

        ComputingWorker worker = new ComputingWorker(start[0], end[0], n[0], (List<Integer>) a[0], (List<Integer>) b[0]);

        worker.run();
    }
}
