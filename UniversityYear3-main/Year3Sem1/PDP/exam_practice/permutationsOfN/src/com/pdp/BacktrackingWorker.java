package com.pdp;

import mpi.MPI;

import java.util.ArrayList;
import java.util.List;

public class                                BacktrackingWorker {
    private int startIndex;
    private int endIndex;
    private int N;
    private int totalPermutations;

    public BacktrackingWorker(int startIndex, int endIndex, int N) {
        this.startIndex = startIndex;
        this.endIndex = endIndex;
        this.N = N;
        this.totalPermutations = 0;
    }

    public void run() {
        for (int i = startIndex; i <= endIndex; i++) {
            backtracking(new ArrayList<>(List.of(i)), N);
        }

        MPI.COMM_WORLD.Send(new int[]{totalPermutations}, 0, 1, MPI.INT, 0, 4);
    }

    public void backtracking(List<Integer> currentSolution, int N) {
        if (currentSolution.size() == N) {
            if (pred(currentSolution)) {
                totalPermutations += 1;
            }
            return;
        }

        for (int i = 1; i <= N; i++) {
            if (!currentSolution.contains(i)) {
                currentSolution.add(i);
                backtracking(currentSolution, N);
                currentSolution.remove((Object)i);
            }
        }
    }

    public boolean pred(List<Integer> solution) {
        return solution.get(0) % 2 == 0;
    }
}
