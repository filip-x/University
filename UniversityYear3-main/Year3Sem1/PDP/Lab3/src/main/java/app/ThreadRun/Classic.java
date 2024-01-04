package app.ThreadRun;

import app.MatrixTraversal.MatrixInterface;
import app.MatrixTraversal.MatrixTraversalMaker;
import app.ProductOfOneElement;
import lombok.Builder;
import lombok.Getter;

import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

@Builder
public class Classic implements Runner {

    private final Vector<Vector<Integer>> matrixA, matrixB;
    @Getter
    private Vector<Vector<Integer>> resultMatrix;
    int matrixSize, taskCount;
    MatrixTraversalMaker.MatrixTraversals matrixTraversalMaker;

    @Override
    public void execute() {
        List<Thread> threadList = new ArrayList<>();
        resultMatrix = ProductOfOneElement.emptyMatrix(matrixSize);
        for(int i=0;i<taskCount;i++)
        {
            MatrixInterface iterator = MatrixTraversalMaker.build(matrixTraversalMaker);
            iterator.setUp(matrixSize,i,taskCount);
            Thread task = new Task(iterator,matrixA,matrixB,resultMatrix);
            task.start();
            threadList.add(task);
        }
        threadList.forEach(thread -> {
            try{
                thread.join();
            }catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        });
    }
}
