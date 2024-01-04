package app;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor


public class PositionHash {
    Integer first,second;
    @Override
    public String toString() {
        return "(" + first + ", " + second + ")";
    }
}
