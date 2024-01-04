package com.pdp;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicBoolean;

public class Main {
    private static final int N = 10;
    private static final int NR_THREADS = 45;

    private static List<Integer> solution;
    private static AtomicBoolean found;
    private static List<Thread> threads;

    public static void main(String[] args) {
        solution = new ArrayList<>();
        threads = new ArrayList<>();
        found.set(false);

        splitWork();
        waitThreads();
        printSolution();
    }

    public static void splitWork() {
        int nrThreadsPerThread = 0;
        int nrsPerThread = 0;
        if (N >= NR_THREADS) {
            nrThreadsPerThread = 1;
            nrsPerThread = N / NR_THREADS;
        }
        else {
            nrsPerThread = 1;
            nrThreadsPerThread = 1 + (NR_THREADS - N) / N;
        }

        for (int i = 0; i < NR_THREADS; i++) {
            int start = i * nrsPerThread;
            int end = start + nrsPerThread - 1;

            Thread thread = new Thread(new WorkerThread(nrThreadsPerThread, N, found, start, end, solution));
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

    public static void printSolution() {
        if (found.get())
            System.out.println("The solution is " + solution);
        else
            System.out.println("We didn't find any solution, sorry!");
    }
}
