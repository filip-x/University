package app.MatrixTraversal;

import java.util.ArrayList;
import java.util.List;

public class RowMatrix implements  MatrixInterface{
    final private List<Pair> positions =new ArrayList<>();
    int current = 0;

    @Override
    public Pair next() {
        if(current < positions.size())
            return positions.get(current++);
        return null;
    }

    @Override
    public void setUp(int matrixSize, int taskIndex, int taskCount) {

        // computing linear positions
        int taskSize = matrixSize * matrixSize / taskCount;
        int linearStart = taskIndex * taskSize;
        int linearEnd;
        if (taskIndex + 1 == taskCount) // last task
            linearEnd = matrixSize * matrixSize - 1;
        else linearEnd = (taskIndex + 1) * taskSize - 1;
        // converting to coordinates
        int startX, startY;
        startX = linearStart / matrixSize;
        startY = linearStart % matrixSize;

        int endX, endY;
        endX = linearEnd / matrixSize;
        endY = linearEnd % matrixSize;
        for (int y = startY; y < matrixSize; y++) {
            positions.add(Pair.builder().first(startX).second(y).build());
        }
        for (int x = startX + 1; x < endX; x++) {
            for (int y = 0; y < matrixSize; y++) {
                positions.add(Pair.builder().first(x).second(y).build());
            }
        }
        for (int y = 0; y <= endY; y++) {
            positions.add(Pair.builder().first(endX).second(y).build());
        }
    }
}
