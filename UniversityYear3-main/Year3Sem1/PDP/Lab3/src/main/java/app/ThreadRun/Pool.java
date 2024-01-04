package app.ThreadRun;

import app.MatrixTraversal.MatrixInterface;
import app.MatrixTraversal.MatrixTraversalMaker;
import app.ProductOfOneElement;
import lombok.Builder;
import lombok.Getter;

import java.util.Vector;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.TimeUnit;

@Builder
public class Pool {
    private  final Vector<Vector<Integer>> matrixA, matrixB;
    @Getter
    private Vector<Vector<Integer>> resultMatrix;
    int matrixSize, taskCount;

    MatrixTraversalMaker.MatrixTraversals matrixTraversalMaker;
    ExecutorService pool;

    public void  execute(){
        resultMatrix = ProductOfOneElement.emptyMatrix(matrixSize);
        for (int i = 0; i < taskCount; i++) {
            MatrixInterface iterator = MatrixTraversalMaker.build(matrixTraversalMaker);
            iterator.setUp(matrixSize, i, taskCount);
            Thread task = new Runner.Task(iterator, matrixA, matrixB, resultMatrix);
            pool.execute(task);
        }
        try {
            pool.shutdown();
            pool.awaitTermination(30, TimeUnit.SECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
