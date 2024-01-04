package com.pdp;

import java.util.List;

public class WorkerThread implements Runnable{
    private List<Integer> vector1;
    private List<Integer> vector2;
    private Integer N;
    private Integer startIndex;
    private Integer endIndex;
    private Integer solution;

    public WorkerThread(List<Integer> vector1, List<Integer> vector2, Integer n, Integer startIndex, Integer endIndex) {
        this.vector1 = vector1;
        this.vector2 = vector2;
        N = n;
        this.startIndex = startIndex;
        this.endIndex = endIndex;

        this.solution = 0;
    }

    @Override
    public void run() {
        for (int i = startIndex; i <= endIndex; i++) {
            solution += vector1.get(i) * vector2.get(i);
        }
    }

    public Integer getSolution() {
        return solution;
    }
}
