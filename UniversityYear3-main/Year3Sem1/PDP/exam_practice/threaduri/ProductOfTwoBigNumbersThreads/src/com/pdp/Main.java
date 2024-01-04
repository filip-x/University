package com.pdp;

import java.util.ArrayList;
import java.util.List;

public class Main {
    private static List<Integer> number1 = List.of(1, 2, 3, 4, 5, 6, 7, 8, 9, 1);
    private static List<Integer> number2 = List.of(2, 3, 4, 5, 7, 8, 2);
    private static Integer SOLUTION_SIZE = number1.size() + number2.size();
    private static int NR_THREADS = 3;
    private static List<Thread> threads;
    private static List<WorkerThread> workers;

    private static List<Integer> solution;

    public static void main(String[] args) {
        splitWork();
        waitThreads();
        constructSolution();
    }

    public static void splitWork() {
        threads = new ArrayList<>();
        workers = new ArrayList<>();

        int nrsPerThreads = number2.size() / NR_THREADS;

        for (int i = 0; i < NR_THREADS; i++) {
            int start = i * nrsPerThreads;
            int end = start + nrsPerThreads - 1;

            if (i == NR_THREADS - 1)
                end = number2.size() - 1;

            WorkerThread worker = new WorkerThread(number1, number2, start, end, SOLUTION_SIZE);
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
        solution = Util.initializeEmptyArray(SOLUTION_SIZE);
        for (WorkerThread worker : workers) {
            solution = Util.addTwoLists(solution, worker.getSolution(), SOLUTION_SIZE);
            System.out.println(solution);
        }

        while (solution.get(0) == 0) {
            solution.remove(0);
        }

        System.out.println("The solution is: " + solution);
    }
}
