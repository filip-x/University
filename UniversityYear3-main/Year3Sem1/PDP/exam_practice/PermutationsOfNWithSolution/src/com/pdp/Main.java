package com.pdp;

import mpi.*;

import java.util.ArrayList;
import java.util.List;

public class Main {
    private static Integer N = 10;

    public static void main(String[] args) {
        MPI.Init(args);

        if (MPI.COMM_WORLD.Rank() == 0) {
            computePrimesToRadicalN();
            splitWork();
            printSolution();
        }
        else {
            runComputingProcess();
        }

        MPI.Finalize();
    }

    public static void splitWork() {
        int nrPerThreads = N / ( MPI.COMM_WORLD.Size() - 1);

        for (int i = 0; i < MPI.COMM_WORLD.Size() - 1; i++) {
            int start = i * nrPerThreads + 1;
            int end = (i + 1) * nrPerThreads;

            if (i == MPI.COMM_WORLD.Size() - 2)
                end = N;

            MPI.COMM_WORLD.Send(new int[]{start}, 0, 1, MPI.INT, i + 1, 1);
            MPI.COMM_WORLD.Send(new int[]{end}, 0, 1, MPI.INT, i + 1, 2);
            MPI.COMM_WORLD.Send(new int[]{N}, 0, 1, MPI.INT, i + 1, 3);
        }
    }

    public static void printSolution() {
        List<Integer> solution = new ArrayList<>();

        for (int i = 1; i < MPI.COMM_WORLD.Size(); i++) {
            Object[] sol = new Object[1];


            MPI.COMM_WORLD.Recv(sol, 0, 1, MPI.OBJECT, i, 4);

            if (((List<Integer>)sol[0]).size() > 0 && solution.size() == 0) {
                solution = (List<Integer>)sol[0];
            }
        }

        System.out.println("The solution is " + solution);
    }

    public static void runComputingProcess() {
        int[] start = new int[1];
        int[] end = new int[1];
        int[] n = new int[1];

        MPI.COMM_WORLD.Recv(start, 0, 1, MPI.INT, 0, 1);
        MPI.COMM_WORLD.Recv(end, 0, 1, MPI.INT, 0, 2);
        MPI.COMM_WORLD.Recv(n, 0, 1, MPI.INT, 0, 3);

        BacktrackingWorker worker = new BacktrackingWorker(start[0], end[0], n[0]);
        worker.run();
    }
}
