package app;

import lombok.AllArgsConstructor;

import lombok.Data;


@Data
@AllArgsConstructor
public class Pair {
    public String first;
    public String second;

    @Override
    public String toString() {
        return "(" + first + ", " + second + ")";
    }
}
