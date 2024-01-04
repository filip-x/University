package com.pdp;

import mpi.*;

public class Main {
    private static int N = 10;
    private static int K = 5;

    public static void main(String[] args) {
        MPI.Init(args);

        if (MPI.COMM_WORLD.Rank() == 0) {
            splitWork();
            waitAnswers();
        }
        else {
            runComputingProcess();
        }

        MPI.Finalize();
    }

    public static void splitWork() {
        int nrPerThreads = N / (MPI.COMM_WORLD.Size() - 1);

        // we parse with i from 0, so we can split the work, but we split the work for process i + 1
        for (int i = 0; i < MPI.COMM_WORLD.Size() - 1; i++) {
            int start = i * nrPerThreads + 1;
            int end = (i + 1) * nrPerThreads;

            if (i == MPI.COMM_WORLD.Size() - 2) {
                end = N;
            }

            MPI.COMM_WORLD.Send(new int[]{start}, 0, 1, MPI.INT, i + 1, 1);
            MPI.COMM_WORLD.Send(new int[]{end}, 0, 1, MPI.INT, i + 1, 2);
            MPI.COMM_WORLD.Send(new int[]{N}, 0, 1, MPI.INT, i + 1, 3);
            MPI.COMM_WORLD.Send(new int[]{K}, 0, 1, MPI.INT, i + 1, 4);
        }
    }

    public static void waitAnswers() {
        int totalPermutationsOfK = 0;

        for (int i = 1; i < MPI.COMM_WORLD.Size(); i++) {
            int[] permutations = new int[1];

            MPI.COMM_WORLD.Recv(permutations, 0, 1, MPI.INT, i, 5);

            totalPermutationsOfK += permutations[0];
        }

        System.out.println("The permutations of K are: " + totalPermutationsOfK);
    }

    public static void runComputingProcess() {
        int[] start = new int[1];
        int[] end = new int[1];
        int[] n = new int[1];
        int[] k = new int[1];

        MPI.COMM_WORLD.Recv(start, 0, 1, MPI.INT, 0, 1);
        MPI.COMM_WORLD.Recv(end, 0, 1, MPI.INT, 0, 2);
        MPI.COMM_WORLD.Recv(n, 0, 1, MPI.INT, 0, 3);
        MPI.COMM_WORLD.Recv(k, 0, 1, MPI.INT, 0, 4);

        BacktrackingWorker worker = new BacktrackingWorker(start[0], end[0], n[0], k[0]);
        worker.run();
    }
}
