package app.MatrixTraversal;

import java.util.ArrayList;
import java.util.List;

public class NMatrix implements MatrixInterface {
    final private List<Pair> positions = new ArrayList<>();
    int current = 0;
    @Override

    public Pair next() {
        if(current < positions.size())
            return positions.get(current++);
        return null;
    }

    @Override
    public void setUp(int matrixSize, int taskIndex, int taskCount) {
        int x, y;
        for (int linearIndex = taskIndex; linearIndex < matrixSize * matrixSize; linearIndex += taskCount) {
            x = linearIndex / matrixSize;
            y = linearIndex % matrixSize;
            positions.add(Pair.builder().first(x).second(y).build());
        }
    }
}
