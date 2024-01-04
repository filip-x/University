package com.pdp;

import java.util.ArrayList;
import java.util.List;

import static com.pdp.Util.isPrime;

public class Main {
    private static int N = 100;
    private static int NR_THREADS = 5;
    private static List<Integer> primesUpToRadicalN;
    private static List<Integer> solution;

    public static void main(String[] args) {
        computePrimeNumbersUpToRadicalN();
        splitWork();
    }

    public static void computePrimeNumbersUpToRadicalN() {
        primesUpToRadicalN = new ArrayList<>();

        int radicalN = (int) Math.sqrt(N);

        for (int i = 2; i <= radicalN; i++) {
            if (isPrime(i, primesUpToRadicalN))
                primesUpToRadicalN.add(i);
        }
    }

    public static void splitWork() {
        int radicalNPlus1 = (int)Math.sqrt(N) + 1;
        int nrsPerThread = (N - radicalNPlus1 + 1) / NR_THREADS;

        List<Thread> threads = new ArrayList<>();
        List<ThreadWorker> workers = new ArrayList<>();

        for (int i = 0; i < NR_THREADS; i++) {
            int startInterval = radicalNPlus1 + i * nrsPerThread;
            int endInterval = startInterval + nrsPerThread - 1;

            if (endInterval == NR_THREADS - 1)
                endInterval = N;

            ThreadWorker worker = new ThreadWorker(N, primesUpToRadicalN, startInterval, endInterval);
            Thread thread = new Thread(worker);
            threads.add(thread);
            workers.add(worker);
            thread.start();
        }

        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        solution = new ArrayList<>(primesUpToRadicalN);

        for (int i = 0; i < workers.size(); i++) {
            solution.addAll(workers.get(i).getSolution());
        }

        System.out.println("The primes up to " + N + " are: " + solution);
    }
}
