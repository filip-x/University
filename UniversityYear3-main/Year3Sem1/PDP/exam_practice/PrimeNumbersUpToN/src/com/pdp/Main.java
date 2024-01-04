package com.pdp;

import mpi.*;

import java.util.ArrayList;
import java.util.List;

public class Main {
    private static int N = 100;
    private static List<Integer> primesToRadicalN;

    public static void main(String[] args) {
        MPI.Init(args);

        if (MPI.COMM_WORLD.Rank() == 0) {
            computeNumbersUpToRadicalN();
            splitWork();
            printSolutions();
        }
        else {
            runComputingProcess();
        }

        MPI.Finalize();
    }

    public static void computeNumbersUpToRadicalN() {
        primesToRadicalN = new ArrayList<>();
        int radicalN = (int) Math.sqrt(N);

        for (int i = 2; i <= radicalN; i++) {
            if (i == 2) {
                primesToRadicalN.add(i);
            }
            else if (isPrime(i))
                primesToRadicalN.add(i);
        }
    }

    // if we found the prime numbers from [2, ..., number - 1], we can use those to compute
    // for number
    public static boolean isPrime(int number) {
        for (int prime : primesToRadicalN) {
            if (prime > number)
                return true;
            if (number % prime == 0)
                return false;
        }
        return true;
    }

    public static void splitWork() {
        int radicalN = (int) Math.sqrt(N) + 1;
        int elemsInInterval = N - radicalN + 1;

        int nrPerThreads =  elemsInInterval / (MPI.COMM_WORLD.Size() - 1);

        for (int i = 0; i < MPI.COMM_WORLD.Size() - 1; i++) {
            int start = i * nrPerThreads + radicalN;
            int end = start + nrPerThreads - 1;


            if (i == MPI.COMM_WORLD.Size() - 2)
                end = N;

            MPI.COMM_WORLD.Send(new int[]{start}, 0, 1, MPI.INT, i + 1, 1);
            MPI.COMM_WORLD.Send(new int[]{end}, 0, 1, MPI.INT, i + 1, 2);
            MPI.COMM_WORLD.Send(new Object[]{primesToRadicalN}, 0, 1, MPI.OBJECT, i + 1, 3);
        }
    }

    public static void printSolutions() {
        List<Integer> primesUpToN = new ArrayList<>(primesToRadicalN);
        Object[] primes = new Object[1];
        for (int i = 1; i < MPI.COMM_WORLD.Size(); i++) {
            MPI.COMM_WORLD.Recv(primes, 0, 1, MPI.OBJECT, i, 4);

            List<Integer> primeObtained = (List<Integer>)primes[0];

            if (primeObtained.size() > 0)
                primesUpToN.addAll(primeObtained);
        }

        System.out.println("Primes up to " + N + " are: " + primesUpToN);
    }

    public static void runComputingProcess() {
        int[] start = new int[1];
        int[] end = new int[1];
        Object[] primes = new Object[1];
        MPI.COMM_WORLD.Recv(start, 0, 1, MPI.INT, 0, 1);
        MPI.COMM_WORLD.Recv(end, 0, 1, MPI.INT, 0, 2);
        MPI.COMM_WORLD.Recv(primes, 0, 1, MPI.OBJECT, 0, 3);

        ComputingWorker worker = new ComputingWorker(start[0], end[0], (List<Integer>)primes[0]);
        worker.run();
    }
}
