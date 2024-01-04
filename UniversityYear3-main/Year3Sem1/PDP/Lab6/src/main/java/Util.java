import java.util.List;
import java.util.Random;

import static java.util.Collections.shuffle;

public class Util {
    public static DirectedGraph generateRandomGraph(int nodeCount){
        DirectedGraph graph = new DirectedGraph(nodeCount);
        List<Integer> nodes = graph.getNodes();
        shuffle(nodes);
        for (int i = 1; i < nodes.size(); i++){
            graph.addEdge(nodes.get(i - 1),  nodes.get(i));
        }
        System.out.println(graph);
        graph.addEdge(nodes.get(nodes.size() -1), nodes.get(0));

        Random random = new Random();

        for (int i = 0; i < nodeCount / 2; i++){
            int node1 = random.nextInt(nodeCount - 1);
            int node2 = random.nextInt(nodeCount - 1);

            if(!graph.getNeighbours(node1).contains(node2)) {
                graph.addEdge(node1, node2);
                i--;
            }
        }

        return graph;
    }
}
