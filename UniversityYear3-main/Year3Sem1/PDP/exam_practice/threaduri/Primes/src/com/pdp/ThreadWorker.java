package com.pdp;

import java.util.ArrayList;
import java.util.List;

public class ThreadWorker implements Runnable {
    private Integer N;
    private List<Integer> primesUpToRadicalN;
    private Integer startInterval;
    private Integer endInterval;
    private List<Integer> solution;

    public ThreadWorker(Integer n, List<Integer> primesUpToRadicalN, Integer startInterval, Integer endInterval) {
        N = n;
        this.primesUpToRadicalN = primesUpToRadicalN;
        this.startInterval = startInterval;
        this.endInterval = endInterval;
        this.solution = new ArrayList<>();
    }

    @Override
    public void run() {
        for (int i = startInterval; i <= endInterval; i++) {
            if (Util.isPrime(i, primesUpToRadicalN)) {
                solution.add(i);
            }
        }
    }

    public List<Integer> getSolution() {
        return this.solution;
    }
}
