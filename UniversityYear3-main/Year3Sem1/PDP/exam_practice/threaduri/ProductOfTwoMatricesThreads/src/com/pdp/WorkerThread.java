package com.pdp;

import java.util.List;

public class WorkerThread implements Runnable{
    private int matrixSize;
    private List<List<Integer>> matrix1;
    private List<List<Integer>> matrix2;
    private int startInterval;
    private int endInterval;
    private List<List<Integer>> solution;

    public WorkerThread(int matrixSize, List<List<Integer>> matrix1, List<List<Integer>> matrix2, int startInterval, int endInterval) {
        this.matrixSize = matrixSize;
        this.matrix1 = matrix1;
        this.matrix2 = matrix2;
        this.startInterval = startInterval;
        this.endInterval = endInterval;

        this.solution = Util.initializeMatrixWithZero(matrixSize);
    }

    @Override
    public void run() {
        for (int k = startInterval; k <= endInterval; k++) {
            int line = k / matrixSize;
            int col = k % matrixSize;

            int res = 0;

            for (int i = 0; i < matrixSize; i++) {
                res += matrix1.get(line).get(i) * matrix2.get(i).get(col);
            }

            List<Integer> lineInMatrix = solution.get(line);
            lineInMatrix.set(col, res);
            solution.set(line, lineInMatrix);
        }
    }

    public List<List<Integer>> getSolution() {
        return solution;
    }
 }
