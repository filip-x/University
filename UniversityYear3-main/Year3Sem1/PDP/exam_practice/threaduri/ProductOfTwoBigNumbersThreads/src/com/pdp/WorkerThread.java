package com.pdp;

import java.util.List;

public class WorkerThread implements Runnable {
    private List<Integer> number1;
    private List<Integer> number2;
    private List<Integer> solution;
    private int startIndex;
    private int endIndex;
    private int solutionSize;

    public WorkerThread(List<Integer> number1, List<Integer> number2, int startIndex, int endIndex, int solutionSize) {
        this.number1 = number1;
        this.number2 = number2;
        this.startIndex = startIndex;
        this.endIndex = endIndex;
        this.solutionSize = solutionSize;

        this.solution = Util.initializeEmptyArray(solutionSize);
    }

    @Override
    public void run() {
        for (int i = endIndex; i >= startIndex; i--) {
            int indexInArray = this.number1.size() + i;
            int carry = 0;

            for (int j = number1.size() - 1; j >= 0; j--) {
                int sum = carry + number2.get(i) * number1.get(j) + solution.get(indexInArray);
                solution.set(indexInArray, sum % 10);
                carry = sum / 10;
                indexInArray -= 1;
            }
            while (carry > 0) {
                int sum = carry + solution.get(indexInArray);
                solution.set(indexInArray,  sum % 10);
                carry = sum / 10;
                indexInArray--;
            }
        }
    }

    public List<Integer> getSolution() {
        return solution;
    }
}
