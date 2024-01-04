import org.junit.jupiter.api.Test;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.Executors;


public class Tests {
    public void run(Runnable runner, String text) {
    long startTime = System.nanoTime();
    runner.run();
    double runTime = (double) (System.nanoTime() - startTime) / 1_000_000_000;
    System.out.println(text + runTime);
}

    @Test
    public void test() throws InterruptedException, ExecutionException {
        DirectedGraph graph = Util.generateRandomGraph(10);
        run(() -> {
            try {
                Simualtor.hamiltonianStart(graph, Executors.newSingleThreadExecutor());
                System.out.println(Simualtor.finalPath);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }, "Single threaded: ");

        run(() -> {
            try {
                Simualtor.hamiltonianStart(graph, Executors.newFixedThreadPool(10));
                System.out.println(Simualtor.finalPath);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }, "Multi threaded: ");
    }
}
