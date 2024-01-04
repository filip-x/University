package app.MatrixTraversal;

public class MatrixTraversalMaker {


    public static MatrixInterface build( MatrixTraversals matrixTraversals) {
        if (matrixTraversals == MatrixTraversals.MatrixTraversalRow) {
            return new RowMatrix();
        }
        else if (matrixTraversals == MatrixTraversals.MatrixTraversalColumn)
        {
            return new ColumnMatrix();
        }
        else {
            return new NMatrix();
        }
    }

    public enum MatrixTraversals {
        MatrixTraversalRow,
        MatrixTraversalColumn,
        MatrixTraversalK
    }

}
