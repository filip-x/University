package app.MatrixTraversal;

import lombok.Builder;
import lombok.Getter;

public interface MatrixInterface {
    Pair next();
    void setUp(int matrixSize, int taskIndex,int taskCount);
    @Builder
    @Getter
    class Pair{
        private final int first;
        private final int second;
    }
}
