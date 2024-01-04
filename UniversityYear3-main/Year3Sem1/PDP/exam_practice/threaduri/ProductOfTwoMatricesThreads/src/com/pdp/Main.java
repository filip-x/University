package com.pdp;

import java.util.ArrayList;
import java.util.List;

public class Main {
    private static final int MATRIX_SIZE = 3;
    private static final int NR_THREADS = 4;
    private static final List<List<Integer>> MATRIX_A = List.of(List.of(1, 2, 3), List.of(4, 5, 6), List.of(7, 8, 9));
    private static final List<List<Integer>> MATRIX_B = List.of(List.of(9, 8, 7), List.of(6, 5, 4), List.of(3, 2, 1));
    private static List<List<Integer>> result;

    private static List<Thread> threads;
    private static List<WorkerThread> workers;

    public static void main(String[] args) {
        splitWork();
        waitForThreads();
        getSolutionsFromThreads();
        printSolution();
    }

    public static void splitWork() {
        int nrOfCells = MATRIX_SIZE * MATRIX_SIZE;
        int cellsPerThreads = nrOfCells / NR_THREADS;

        workers = new ArrayList<>();
        threads = new ArrayList<>();

        for (int i = 0; i < NR_THREADS; i++) {
            int startInterval = i * cellsPerThreads;
            int endInterval = (i + 1) * cellsPerThreads - 1;

            if (i == NR_THREADS - 1)
                endInterval = nrOfCells - 1;

            WorkerThread worker = new WorkerThread(MATRIX_SIZE, MATRIX_A, MATRIX_B, startInterval, endInterval);
            workers.add(worker);

            Thread thread = new Thread(worker);
            threads.add(thread);

            thread.start();
        }
    }

    public static void waitForThreads() {
        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException ex) {
                System.out.println(ex.getMessage());
            }
        }
    }

    public static void getSolutionsFromThreads() {
        result = Util.initializeMatrixWithZero(MATRIX_SIZE);

        for (WorkerThread worker : workers) {
            List<List<Integer>> partialSolution = worker.getSolution();
            result = Util.addMatrices(result, partialSolution);
        }
    }

    public static void printSolution() {
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                System.out.print(result.get(i).get(j) + " ");
            }
            System.out.println("");
        }
    }
}
