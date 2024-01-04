package com.pdp;

import java.util.ArrayList;
import java.util.List;

public class Util {
    public static List<List<Integer>> initializeMatrixWithZero(int matrixSize) {
        List<List<Integer>> matrix = new ArrayList<>();

        for (int i = 0; i < matrixSize; i++) {
            List<Integer> line = new ArrayList<>();

            for (int j = 0; j < matrixSize; j++) {
                line.add(0);
            }
            matrix.add(line);
        }

        return matrix;
    }

    public static List<List<Integer>> addMatrices(List<List<Integer>> matrix1, List<List<Integer>> matrix2) {
        List<List<Integer>> result = new ArrayList<>();

        for (int i = 0; i < matrix1.size(); i++) {
            List<Integer> line = new ArrayList<>();
            for (int j = 0; j < matrix2.size(); j++) {
                line.add(matrix1.get(i).get(j) + matrix2.get(i).get(j));
            }
            result.add(line);
        }
        return result;
    }
}
