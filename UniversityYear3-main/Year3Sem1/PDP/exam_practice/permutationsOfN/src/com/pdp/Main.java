package com.pdp;

import mpi.*;

public class Main {
    public static Integer N = 10;

    public static void main(String[] args) {
	// write your code here
        MPI.Init(args);

        int rankOfTheProcess = MPI.COMM_WORLD.Rank();

        if (rankOfTheProcess == 0) {
            splitWork();
            awaitAnswers();
        }
        else
            runComputingProcess();

        MPI.Finalize();
    }

    public static void splitWork() {
        int numbersPerThread = N / (MPI.COMM_WORLD.Size() - 1);

        for (int i = 0; i < MPI.COMM_WORLD.Size() - 1; i++) {
            int startProcess = i * numbersPerThread + 1;
            int endProcess = (i + 1) * numbersPerThread;

            if (i == MPI.COMM_WORLD.Size() - 2)
                endProcess = N;
            MPI.COMM_WORLD.Send(new int[]{startProcess}, 0, 1, MPI.INT, i + 1, 1);
            MPI.COMM_WORLD.Send(new int[]{endProcess}, 0, 1, MPI.INT, i + 1, 2);
            MPI.COMM_WORLD.Send(new int[]{N}, 0, 1, MPI.INT, i + 1, 3);
        }
    }

    public static void awaitAnswers() {
        int totalPermutations = 0;

        for (int i = 1; i < MPI.COMM_WORLD.Size(); i++) {
            int[] permutationsReceived = new int[1];

            MPI.COMM_WORLD.Recv(permutationsReceived, 0, 1, MPI.INT, i, 4);

            totalPermutations += permutationsReceived[0];
        }

        System.out.println("The permutations generated are " + totalPermutations);
    }

    public static void runComputingProcess() {
        int[] startIndex = new int[1];
        int[] endIndex = new int[1];
        int[] n = new int[1];
        MPI.COMM_WORLD.Recv(startIndex, 0, 1, MPI.INT, 0, 1);
        MPI.COMM_WORLD.Recv(endIndex, 0, 1, MPI.INT, 0, 2);
        MPI.COMM_WORLD.Recv(n, 0, 1, MPI.INT, 0, 3);

        BacktrackingWorker worker = new BacktrackingWorker(startIndex[0], endIndex[0], n[0]);
        worker.run();

    }
}
