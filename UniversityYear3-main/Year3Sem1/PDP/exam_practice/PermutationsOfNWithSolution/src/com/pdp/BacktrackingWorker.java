package com.pdp;

import mpi.MPI;

import java.util.ArrayList;
import java.util.List;

public class BacktrackingWorker {
    private Integer start;
    private Integer end;
    private Integer N;
    private boolean found;
    private List<Integer> solution;

    public BacktrackingWorker(Integer start, Integer end, Integer n) {
        this.start = start;
        this.end = end;
        N = n;
        found = false;
        solution = new ArrayList<>();
    }

    public void run() {
        for (int i = start; i <= end; i++) {
            if (found)
                break;
            backtracking(new ArrayList<>(List.of(i)));
        }

        MPI.COMM_WORLD.Send(new Object[]{solution}, 0, 1, MPI.OBJECT, 0, 4);
    }

    private void backtracking(List<Integer> partialSolution) {
        if (this.found)
            return;

        if (partialSolution.size() == N) {
            if (!this.found && pred(partialSolution)) {
                this.found = true;
                solution = new ArrayList<>(partialSolution);
            }
            return;
        }

        for (int i = 1; i <= N; i++) {
            if (!partialSolution.contains(i)) {
                partialSolution.add(i);
                backtracking(partialSolution);
                partialSolution.remove((Object)i);
            }
        }
    }

    private boolean pred(List<Integer> partialSol) {
        if (partialSol.get(0) % 2 == 0)
            return true;
        return false;
    }
}
