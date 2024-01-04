package com.pdp;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicBoolean;

public class WorkerThread implements Runnable{
    private int nrThreadsLeft;
    private int N;
    private AtomicBoolean found;
    private int start;
    private int end;

    private List<Integer> solution;

    public WorkerThread(int nrThreadsLeft, int n, AtomicBoolean found, int start, int end, List<Integer> solution) {
        this.nrThreadsLeft = nrThreadsLeft;
        N = n;
        this.found = found;
        this.start = start;
        this.end = end;

        this.solution = solution;
    }

    @Override
    public void run() {
        for (int i = start; i <= end; i++) {
            backtracking(new ArrayList<>(i));
        }
    }

    private void backtracking(List<Integer> partialSolution) {
        if (found.get())
            return;
        if (partialSolution.size() == N) {
            if (pred(partialSolution) && !found.get()) {
                found.set(true);
                solution = new ArrayList<>(partialSolution);
            }
            return;
        }

        // the nr of candidates is the number of elements which are not in the partial solution
        int possibleCandidates = N - partialSolution.size();
        int candidatesPerThread = possibleCandidates / nrThreadsLeft;

        if (nrThreadsLeft == 1) {
            for (int i = 0; i < N; i++) {
                if (!partialSolution.contains(i)) {
                    partialSolution.add(i);
                    backtracking(partialSolution);
                    partialSolution.remove((Object)i);
                }
            }
        } else {
            List<Thread> threads = new ArrayList<>();

            for (int i = 0; i < N; i++) {
                if (!partialSolution.contains(i)) {
                    Thread thread = new Thread(new WorkerThread(, n, found, ));
                }
            }
        }
    }

    private boolean pred(List<Integer> partialSolution) {
        if (partialSolution.get(0) % 2 == 0)
            return true;
        return false;
    }
}
