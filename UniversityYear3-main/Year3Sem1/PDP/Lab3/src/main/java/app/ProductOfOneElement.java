package app;

import java.util.Vector;

public class ProductOfOneElement {

    public static Integer productOfOneElement(int x, int y, Vector<Vector<Integer>> matrixA, Vector<Vector<Integer>> matrixB) {

        int sum = 0;
        int size = matrixA.size();
        for(int i=0;i<size;i++)
        {
            sum+= matrixA.get(x).get(i) * matrixB.get(i).get(y);
        }
    return sum;
    }

    public static Vector<Vector<Integer>> emptyMatrix(int size) {
        Vector<Vector<Integer>> matrix = new Vector<>();
        for (int i = 0; i < size; i++) {
            matrix.add(new Vector<>());
            for (int j = 0; j < size; j++) {
                matrix.get(i).add(0);
            }
        }
        return matrix;
    }
}
