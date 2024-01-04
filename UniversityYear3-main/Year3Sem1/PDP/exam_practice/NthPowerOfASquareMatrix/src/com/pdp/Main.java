package com.pdp;

import mpi.*;

import java.util.ArrayList;
import java.util.List;

public class Main {
    private static int N = 5;
    private static List<List<Integer>> MATRIX_A = List.of(List.of(1, 2, 3), List.of(4, 5, 6), List.of(7, 8, 9));
    private static List<List<Integer>> SOLUTION = new ArrayList<>(MATRIX_A);
    private static int MATRIX_SIZE = 3;

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
        int nrPerThreads = MATRIX_SIZE * MATRIX_SIZE / (MPI.COMM_WORLD.Size() - 1);

        Object[] partialSolution = new Object[1];

        for (int k = 2; k <= N; k++) {
            for (int i = 0; i < MPI.COMM_WORLD.Size() - 1; i++) {
                int start = i * nrPerThreads;
                int end = (i + 1) * nrPerThreads - 1;

                if (i == MPI.COMM_WORLD.Size() - 2)
                    end = MATRIX_SIZE * MATRIX_SIZE - 1;

                MPI.COMM_WORLD.Send(new int[]{start}, 0, 1, MPI.INT, i + 1, 1);
                MPI.COMM_WORLD.Send(new int[]{end}, 0, 1, MPI.INT, i + 1, 2);
                MPI.COMM_WORLD.Send(new int[]{MATRIX_SIZE}, 0, 1, MPI.INT, i + 1, 3);
                MPI.COMM_WORLD.Send(new Object[]{MATRIX_A}, 0, 1, MPI.OBJECT, i + 1, 4);
                MPI.COMM_WORLD.Send(new Object[]{SOLUTION}, 0, 1, MPI.OBJECT, i + 1, 5);
            }

            SOLUTION = constructEmptyMatrixOfSizeN(MATRIX_SIZE);

            for (int i = 1; i < MPI.COMM_WORLD.Size(); i++) {
                MPI.COMM_WORLD.Recv(partialSolution, 0, 1, MPI.OBJECT, i, 6);

                addPartialSolutionToMatrix(i, nrPerThreads, (List<Integer>)partialSolution[0]);
            }
        }
    }

    public static void addPartialSolutionToMatrix(int index, int nrPerThreads, List<Integer> partialSolution) {
        int current = (index - 1) * nrPerThreads;

        for (int elem : partialSolution) {
            int line = current / MATRIX_SIZE;
            int col = current % MATRIX_SIZE;

            List<Integer> lineInMatrix = SOLUTION.get(line);
            lineInMatrix.set(col, elem);

            SOLUTION.set(line, lineInMatrix);

            current++;
        }
    }

    public static List<List<Integer>> constructEmptyMatrixOfSizeN(int N) {
        List<List<Integer>> matrix = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            List<Integer> line = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                line.add(0);
            }
            matrix.add(line);
        }

        return matrix;
    }

    public static void printSolution() {
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0;  j < MATRIX_SIZE; j++){
                System.out.print(SOLUTION.get(i).get(j) + " ");
            }
            System.out.println("");
        }
    }

    public static void runComputingProcess() {
        int[] start = new int[1];
        int[] end = new int[1];
        int[] matrixSize = new int[1];
        Object[] matrixA = new Object[1];
        Object[] matrixB = new Object[1];

        for (int i = 2; i <= N; i++) {
            MPI.COMM_WORLD.Recv(start, 0, 1, MPI.INT, 0, 1);
            MPI.COMM_WORLD.Recv(end, 0, 1, MPI.INT, 0, 2);
            MPI.COMM_WORLD.Recv(matrixSize, 0, 1, MPI.INT, 0, 3);
            MPI.COMM_WORLD.Recv(matrixA, 0, 1, MPI.OBJECT, 0, 4);
            MPI.COMM_WORLD.Recv(matrixB, 0, 1, MPI.OBJECT, 0, 5);

            ComputingWorker worker = new ComputingWorker(start[0], end[0], matrixSize[0], (List<List<Integer>>) matrixA[0],
                    (List<List<Integer>>) matrixB[0]);

            worker.run();
        }
    }
}
