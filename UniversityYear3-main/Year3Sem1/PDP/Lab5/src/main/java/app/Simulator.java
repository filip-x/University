package app;
import java.util.ArrayList;
import java.util.Collections;
import java.util.concurrent.*;
import java.util.concurrent.atomic.AtomicReference;
import java.util.concurrent.locks.ReentrantLock;

public class Simulator {
    private static final int MAX_DEPTH = 10;
    Integer threadCount = 8;
    ThreadPoolExecutor threadPoolExecutor = (ThreadPoolExecutor) Executors.newFixedThreadPool(threadCount);


    public Polynomial multiplyPolynomials_Classic_Helper(Polynomial a, Polynomial b, int i) {
        Polynomial line = new Polynomial(new ArrayList<>(Collections.nCopies(a.getSize() + b.getSize() - 1, 0)));
        for (int j = 0; j < b.getSize(); j++) {
            line.getCoefficients().set(i + j, a.getCoefficients().get(i) * b.getCoefficients().get(j));
        }
        return line;
    }

    public Polynomial multiplyPolynomials_Classic_Sequential(Polynomial a, Polynomial b) {
        Polynomial r = new Polynomial(new ArrayList<>(Collections.nCopies(a.getSize() + b.getSize() - 1, 0)));
        for (int i = 0; i < a.getSize(); i++) {
            r = r.addition(multiplyPolynomials_Classic_Helper(a, b, i));
        }
        return r;
    }

    public Polynomial multiplyPolynomials_Classic_Parallel(Polynomial a, Polynomial b) throws InterruptedException {
        AtomicReference<Polynomial> r = new AtomicReference<>(new Polynomial(new ArrayList<>(Collections.nCopies(a.getSize() + b.getSize() - 1, 0))));
        ReentrantLock lock = new ReentrantLock();
        for (int i = 0; i < threadCount; i++) {
            int finalI = i;
            threadPoolExecutor.execute(() -> {
                for (int j = finalI; j < a.getSize(); j += threadCount) {
                    Polynomial line = multiplyPolynomials_Classic_Helper(a, b, j);
                    lock.lock();
                    r.set(r.get().addition(line));
                    lock.unlock();
                }
            });
        }
        threadPoolExecutor.shutdown();
        threadPoolExecutor.awaitTermination(60, TimeUnit.SECONDS);
        return r.get();
    }

    public Polynomial multiplyPolynomials_Karatsuba_Sequential(Polynomial p1, Polynomial p2) {
        if (p1.getDegree() < 2 || p2.getDegree() < 2)
            return multiplyPolynomials_Classic_Sequential(p1, p2);

        int m = Math.min(p1.getDegree(), p2.getDegree()) / 2;

        Polynomial low1 = new Polynomial(p1.getCoefficients().subList(0, m));
        Polynomial high1 = new Polynomial(p1.getCoefficients().subList(m, p1.getSize()));
        Polynomial low2 = new Polynomial(p2.getCoefficients().subList(0, m));
        Polynomial high2 = new Polynomial(p2.getCoefficients().subList(m, p2.getSize()));

        Polynomial z0 = multiplyPolynomials_Karatsuba_Sequential(low1, low2);
        Polynomial z1 = multiplyPolynomials_Karatsuba_Sequential(low1.addition(high1), low2.addition(high2));
        Polynomial z2 = multiplyPolynomials_Karatsuba_Sequential(high1, high2);

        Polynomial rez1 = z2.addZeros(2 * m);
        Polynomial rez2 = z1.subtraction(z2).subtraction(z0).addZeros(m);

        return rez1.addition(rez2).addition(z0);
    }

    public Polynomial multiplyPolynomials_Karatsuba_Parallel(Polynomial p1, Polynomial p2, int currentDepth) throws InterruptedException, ExecutionException {
        if (currentDepth > MAX_DEPTH) {
            return multiplyPolynomials_Karatsuba_Sequential(p1, p2);
        }

        if (p1.getDegree() < 2 || p2.getDegree() < 2)
            return multiplyPolynomials_Classic_Sequential(p1, p2);

        ThreadPoolExecutor executor = (ThreadPoolExecutor) Executors.newFixedThreadPool(8);

        int m = Math.min(p1.getDegree(), p2.getDegree()) / 2;

        Polynomial low1 = new Polynomial(p1.getCoefficients().subList(0, m));
        Polynomial high1 = new Polynomial(p1.getCoefficients().subList(m, p1.getSize()));
        Polynomial low2 = new Polynomial(p2.getCoefficients().subList(0, m));
        Polynomial high2 = new Polynomial(p2.getCoefficients().subList(m, p2.getSize()));

        Future<Polynomial> f_z0 = executor.submit(() -> multiplyPolynomials_Karatsuba_Parallel(low1, low2, currentDepth + 1));
        Future<Polynomial> f_z1 = executor.submit(() -> multiplyPolynomials_Karatsuba_Parallel(low1.addition(high1), low2.addition(high2), currentDepth + 1));
        Future<Polynomial> f_z2 = executor.submit(() -> multiplyPolynomials_Karatsuba_Parallel(high1, high2, currentDepth + 1));
        // asteapta un rezultat pe care nu il ai acuma
//        executor.shutdown();

        Polynomial z0 = f_z0.get();
        Polynomial z1 = f_z1.get();
        Polynomial z2 = f_z2.get();

//        executor.awaitTermination(60, TimeUnit.SECONDS);

        Polynomial rez1 = z2.addZeros(2 * m);
        Polynomial rez2 = z1.subtraction(z2).subtraction(z0).addZeros(m);

        return rez1.addition(rez2).addition(z0);
    }
}