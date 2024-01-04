import app.Polynomial;
import app.Simulator;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.ExecutionException;
import java.util.function.Supplier;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class Tests {
    public Polynomial generateRandomPolynomial() {
        Random r = new Random();
        List<Integer> rez = new ArrayList<>();
        int n = 100;
        for (int i = 0; i < n; i++) {
            rez.add(r.nextInt(10));
        }
        return new Polynomial(rez);
    }

    public Polynomial run(Supplier<Polynomial> runner, String text) {
        long startTime = System.nanoTime();
        Polynomial result = runner.get();
        double runTime = (double) (System.nanoTime() - startTime) / 1_000_000_000;
        System.out.println(text + runTime);
        return result;
    }

    @Test
    public void test_sequential() throws InterruptedException, ExecutionException {
        Simulator simulator = new Simulator();
        Simulator simulator2 = new Simulator();
        Polynomial p1 = generateRandomPolynomial();
        Polynomial p2 = generateRandomPolynomial();

        System.out.println(p1);
        System.out.println(p2);
        Polynomial r1 = run(() -> simulator.multiplyPolynomials_Classic_Sequential(p1, p2), "Classic Sequential - ");
        Polynomial r2 = run(() -> simulator.multiplyPolynomials_Karatsuba_Sequential(p1, p2), "Karatsuba Sequential - ");
        Polynomial r3 = run(() -> {
            try {
                return simulator.multiplyPolynomials_Classic_Parallel(p1, p2);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            return null;
        }, "Classic Parallel - ");
        Polynomial r4 = run(() -> {
            try {
                return simulator2.multiplyPolynomials_Karatsuba_Parallel(p1, p2, 0);
            } catch (InterruptedException | ExecutionException e) {
                e.printStackTrace();
            }
            return null;
        }, "Karatsuba Parallel - ");

        assertEquals(r1.toString(), r2.toString());
        assertEquals(r3.toString(), r2.toString());
        assertEquals(r4.toString(), r2.toString());
        System.out.println(r1);

    }
}
