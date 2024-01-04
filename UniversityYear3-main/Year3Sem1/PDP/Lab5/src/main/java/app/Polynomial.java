package app;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import java.util.function.ToIntBiFunction;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Polynomial {
    private List<Integer> coefficients;

    public int getDegree() {
        return this.coefficients.size() - 1;
    }

    public int getSize() {
        return this.coefficients.size();
    }

    public Polynomial addition(Polynomial p2) {
        return general_add(p2, Integer::sum);
    }

    public Polynomial subtraction(Polynomial p2) {
        Polynomial result = general_add(p2, (a, b) -> a - b);

        int zeroPos = result.getCoefficients().lastIndexOf(0);
        if (zeroPos > 0 && result.getSize() > zeroPos + 1) {
            result.getCoefficients().subList(zeroPos + 1, result.getSize()).clear();
        }

        return result;
    }

    public Polynomial addZeros(int offset) {
        List<Integer> coefficients = new ArrayList<>();
        for(int i = 0; i < offset; i++){
            coefficients.add(0);
        }

        coefficients.addAll(getCoefficients());

        return new Polynomial(coefficients);
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();

        for (int i = getSize() - 1; i >= 0; i--) {
            stringBuilder.append(getCoefficients().get(i)).append("x^").append(i).append(" + ");
        }

        stringBuilder.setLength(stringBuilder.length() - 3);
        return stringBuilder.toString();
    }

    private Polynomial general_add(Polynomial p2, ToIntBiFunction<Integer, Integer> op) {
        int minDegree = Math.min(this.getDegree(), p2.getDegree());
        int maxDegree = Math.max(this.getDegree(), p2.getDegree());
        // tre sa stim care ii mai mare
        Polynomial result = new Polynomial(new ArrayList<>(Collections.nCopies(maxDegree + 1, 0)));// poli rez

        for (int i = 0; i <= minDegree; i++) {
            int sum = op.applyAsInt(this.getCoefficients().get(i), p2.getCoefficients().get(i));
            result.getCoefficients().set(i, sum);
        }

        Polynomial remaining = this.getDegree() > p2.getDegree() ? this : p2;// vede care din ele ii mai mare sa copiem apoi ce o mai ramas

        for (int i = minDegree + 1; i <= maxDegree; i++) {
            result.getCoefficients().set(i, remaining.getCoefficients().get(i));
        }

        return result;
    }
}