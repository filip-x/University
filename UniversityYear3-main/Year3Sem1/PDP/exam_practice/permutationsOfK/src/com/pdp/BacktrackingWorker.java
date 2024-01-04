package com.pdp;

import mpi.MPI;

import java.util.ArrayList;
import java.util.List;

public class BacktrackingWorker {
    private int start;
    private int end;
    private int n;
    private int k;
    private int totalPermutations;

    public BacktrackingWorker(int start, int end, int n, int k) {
        this.start = start;
        this.end = end;
        this.n = n;
        this.k = k;
        this.totalPermutations = 0;
    }

    public void run() {
        System.out.println("Start is: " + start + " and end is " + end);
        for (int i = start; i <= end; i++) {
            backtracking(new ArrayList<>(List.of(i)));
        }

        MPI.COMM_WORLD.Send(new int[]{totalPermutations}, 0, 1, MPI.INT, 0, 5);
    }

    public void backtracking(List<Integer> currentSolution) {
        if (currentSolution.size() == k) {
            if (pred(currentSolution))
                totalPermutations += 1;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (!currentSolution.contains(i)) {
                currentSolution.add(i);
                backtracking(currentSolution);
                currentSolution.remove((Object)i);
            }
        }
    }

    public boolean pred(List<Integer> solution) {
        return solution.get(0) % 2 == 0;
    }
}
