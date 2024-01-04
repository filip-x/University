package app;

import lombok.AllArgsConstructor;
import lombok.Data;

@Data
@AllArgsConstructor
public class Pair {
    String first;
    String second;

    @Override
    public String toString() {
        return "(" + first + ", " + second + ")";
    }
}
