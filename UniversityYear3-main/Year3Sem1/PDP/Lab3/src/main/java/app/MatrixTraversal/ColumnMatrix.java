package app.MatrixTraversal;

import java.util.ArrayList;
import java.util.List;

public class ColumnMatrix implements MatrixInterface{

    // the position is a list of pairs
    final private List<Pair> positions  = new ArrayList<>();
    int current= 0;

    @Override
    public Pair next() {
        if(current < positions.size())
            return positions.get(current++);
        return null;
    }

    @Override
    public void setUp(int matrixSize, int taskIndex, int taskCount) {
        int taskSize = matrixSize* matrixSize/taskCount;
        int linearStart = taskIndex* taskSize;
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
            positions.add(Pair.builder().first(y).second(startX).build());
        }
        for (int x = startX + 1; x < endX; x++) {
            for (int y = 0; y < matrixSize; y++) {
                positions.add(Pair.builder().first(y).second(x).build());
            }
        }
        for (int y = 0; y <= endY; y++) {
            positions.add(Pair.builder().first(y).second(endX).build());
        }

    }
}
