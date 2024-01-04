package com.app;


import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.function.ToIntBiFunction;

public class Polynomial {
    public List<Integer> getCoefficients() {
        return coefficients;
    }

    private List<Integer> coefficients;

    public Polynomial(List<Integer> c) {
        coefficients = c;
    }

    public Polynomial() {

    }



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

        Polynomial result = new Polynomial(new ArrayList<>(Collections.nCopies(maxDegree + 1, 0)));

        for (int i = 0; i <= minDegree; i++) {
            int sum = op.applyAsInt(this.getCoefficients().get(i), p2.getCoefficients().get(i));
            result.getCoefficients().set(i, sum);
        }

        Polynomial remaining = this.getDegree() > p2.getDegree() ? this : p2;

        for (int i = minDegree + 1; i <= maxDegree; i++) {
            result.getCoefficients().set(i, remaining.getCoefficients().get(i));
        }

        return result;
    }

    public static Polynomial generateRandomPolynomial() {
        Random r = new Random();
        List<Integer> rez = new ArrayList<>();
        int n = 5;
        for (int i = 0; i < n; i++) {
            rez.add(r.nextInt(10));
        }
        return new Polynomial(rez);
    }
}
