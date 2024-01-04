import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.ToString;

import java.util.ArrayList;
import java.util.List;


@Data
@AllArgsConstructor
@ToString
public class DirectedGraph {
    private final List<List<Integer>> edges = new ArrayList<>();
    private final List<Integer> nodes = new ArrayList<>();

    public DirectedGraph(int nodeCount) {

        for (int i = 0; i < nodeCount; i++) {
            this.edges.add(new ArrayList<>());
            this.nodes.add(i);
        }
    }

    public void addEdge(int node1, int node2) {
        System.out.println(node1 + " " + node2);
        this.edges.get(node1).add(node2);
    }

    public List<Integer> getNeighbours(int node) {
        return this.edges.get(node);
    }
}
