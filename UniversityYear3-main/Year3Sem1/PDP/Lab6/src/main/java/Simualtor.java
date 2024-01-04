import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicBoolean;

public class Simualtor {
    static AtomicBoolean shouldFinish = new AtomicBoolean(false);
    static List<Integer> finalPath;

    private static void recursive(DirectedGraph graph, List<Integer> path, int node) {
        path.add(node);
        if (!shouldFinish.get()) {
            if (path.size() == graph.getNodes().size()) {
                if (graph.getNeighbours(path.get(0)).contains(node)) {
                    System.out.println(graph.getNeighbours(path.get(0)));
                    finalPath = path;
                    finalPath.add(path.get(0));
                    shouldFinish.set(true);
                }
            }

            for (int v : graph.getNeighbours(node)) {
                if (!path.contains(v))
                    recursive(graph, new ArrayList<>(path), v);
            }
        }
    }

    public static void hamiltonianStart(DirectedGraph graph, ExecutorService executorService) throws InterruptedException {
        for (int i = 0; i < graph.getNodes().size(); i++) {// fiecare nod creeaza un thread nou apoi apeleaza recursive
            int finalI = i;
            executorService.submit(() -> {
                recursive(graph, new ArrayList<>(), finalI);
            });
        }

        executorService.shutdown();
        executorService.awaitTermination(60, TimeUnit.SECONDS);
    }
}
