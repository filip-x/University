package app;

import app.MatrixTraversal.MatrixTraversalMaker;
import app.ThreadRun.Classic;
import app.ThreadRun.Pool;

import java.util.Random;
import java.util.Vector;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.function.Supplier;

public class Simulation {
    Integer size;
    Vector<Vector<Integer>> matrixA,matrixB;

    public void generateRandomMatrices()
    {
        Random random = new Random();
        size = 250;
        matrixA = new Vector<>();
        matrixB = new Vector<>();
        for (int i = 0; i < size; i++) {
            matrixA.add(new Vector<>());
            matrixB.add(new Vector<>());
            for (int j = 0; j < size; j++) {
                matrixA.get(i).add(random.nextInt(10000));
                matrixB.get(i).add(random.nextInt(10000));
            }
        }
    }

    public double  classicThreadRunner(final int taskCount, MatrixTraversalMaker.MatrixTraversals matrixIterator) {
        long startTime = System.nanoTime();
            Classic taskRunner = Classic.builder()
                    .matrixA(matrixA)
                    .matrixB(matrixB)
                    .matrixSize(size)
                    .matrixTraversalMaker(matrixIterator)
                    .taskCount(taskCount)
                    .build();
            taskRunner.execute();
        return (double) (System.nanoTime() - startTime) / 1_000_000_000;
    }

    public double threadPoolRunner(final int taskCount, MatrixTraversalMaker.MatrixTraversals matrixIterator, ExecutorService pool) {
        long startTime = System.nanoTime();
            Pool taskRunner = Pool.builder()
                    .matrixA(matrixA)
                    .matrixB(matrixB)
                    .matrixSize(size)
                    .matrixTraversalMaker(matrixIterator)
                    .taskCount(taskCount)
                    .pool(pool)
                    .build();
            taskRunner.execute();
        return (double) (System.nanoTime() - startTime) / 1_000_000_000;
    }

    public void start(){
        generateRandomMatrices();
        System.out.println(classicThreadRunner(5, MatrixTraversalMaker.MatrixTraversals.MatrixTraversalRow));
        System.out.println(classicThreadRunner(5, MatrixTraversalMaker.MatrixTraversals.MatrixTraversalColumn));
        System.out.println(classicThreadRunner(5, MatrixTraversalMaker.MatrixTraversals.MatrixTraversalK));
        //simple
        System.out.println(threadPoolRunner(5, MatrixTraversalMaker.MatrixTraversals.MatrixTraversalRow, Executors.newFixedThreadPool(5)));
        System.out.println(threadPoolRunner(5, MatrixTraversalMaker.MatrixTraversals.MatrixTraversalColumn, Executors.newFixedThreadPool(5)));
        System.out.println(threadPoolRunner(5, MatrixTraversalMaker.MatrixTraversals.MatrixTraversalK, Executors.newFixedThreadPool(5)));
        // pool


    }
}
