package app.ThreadRun;

import app.MatrixTraversal.MatrixInterface;
import app.ProductOfOneElement;

import java.util.Vector;

public interface Runner {
    void execute();
    class Task extends Thread{
        MatrixInterface iterator;
        Vector<Vector<Integer>> matrixA,matrixB,resultMatrix;

        public Task(MatrixInterface iterator, Vector<Vector<Integer>>matrixA,Vector<Vector<Integer>> matrixB, Vector<Vector<Integer>> resultMatrix)
        {
            super();
            this.iterator = iterator;
            this.matrixA = matrixA;
            this.matrixB = matrixB;
            this.resultMatrix = resultMatrix;
        }
        public void run(){
            int x,y;
            for (MatrixInterface.Pair pair = iterator.next(); pair!= null; pair = iterator.next())// pair ia pozitile pe care sa mergi
            {
                x = pair.getFirst();
                y =pair.getSecond();
                resultMatrix.get(x).set(y, ProductOfOneElement.productOfOneElement(x,y,matrixA,matrixB));// calculates the points for the required task
            }
        }
    }
}
