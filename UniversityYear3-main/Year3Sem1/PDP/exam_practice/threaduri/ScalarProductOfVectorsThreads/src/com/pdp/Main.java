package com.pdp;

import java.util.ArrayList;
import java.util.List;

public class Main {
    private static final int N = 10;
    private static Integer NR_THREADS = 7;

    private static final List<Integer> vector1 = List.of(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    private static final List<Integer> vector2 = List.of(1, 2, 3, 4, 5, 5, 4, 3, 2, 1);
    private static Integer solution = 0;

    private static List<Thread> threads = new ArrayList<>();
    private static List<WorkerThread> workers = new ArrayList<>();

    public static void main(String[] args) {
        splitWork();
        waitThreads();
        constructSolution();
        printSolution();
    }

    public static void splitWork() {
        int nrsPerThread = N / NR_THREADS;

        for (int i = 0; i < NR_THREADS; i++) {
            int start = i * nrsPerThread;
            int end = start + nrsPerThread - 1;

            if (i == NR_THREADS - 1)
                end = N - 1;

            WorkerThread worker = new WorkerThread(vector1, vector2, N, start, end);
            workers.add(worker);

            Thread thread = new Thread(worker);
            threads.add(thread);

            thread.start();
        }
    }

    public static void waitThreads() {
        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void constructSolution() {
        for (WorkerThread worker : workers) {
            solution += worker.getSolution();
        }
    }

    public static void printSolution() {
        System.out.println("Solution is " + solution);
    }

}
