package com.app;

import mpi.MPI;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class KaratsubaMultiplication {
    public static void run() {
        int processRank = MPI.COMM_WORLD.Rank();
        if (processRank == 0) {
            Polynomial a = Polynomial.generateRandomPolynomial();
            Polynomial b = Polynomial.generateRandomPolynomial();
            mainProcess(a, b);
        } else {
            childProcess();
        }
        MPI.Finalize();
    }

    public static Polynomial algorithm(int start, int end, Polynomial a, Polynomial b, Polynomial d) {
        Polynomial r = new Polynomial(new ArrayList<>(Collections.nCopies(a.getSize() + b.getSize() - 1, 0)));


        for (int i = start; i < end; i++) {
            if (i > r.getSize()) {
                return r;
            }

            int indexResult = 0;
            for(int s = 0; s <= i/2; s++) {
                int t = i - s;
                if(t <= s)
                    break;
                if(s > a.getSize() - 1 || t > a.getSize() - 1)
                    continue;

                indexResult += (a.getCoefficients().get(s) + a.getCoefficients().get(t)) * (b.getCoefficients().get(s) + b.getCoefficients().get(t));
                indexResult = indexResult - d.getCoefficients().get(s) - d.getCoefficients().get(t);
            }

            if(i % 2 == 0)
                indexResult += d.getCoefficients().get(i/2);

            r.getCoefficients().set(i, indexResult);
        }

        return r;
    }

    public static void mainProcess(Polynomial a, Polynomial b) {
        int processCount = MPI.COMM_WORLD.Size();
        Polynomial finalResult = new Polynomial(new ArrayList<>(Collections.nCopies(a.getSize() + b.getSize() - 1, 0)));
        int step = finalResult.getSize() / (processCount - 1);
        step = step != 0 ? step : 1;
        Polynomial d = new Polynomial(new ArrayList<>(Collections.nCopies(a.getSize(), 0)));
        for(int i = 0; i < a.getSize(); i++)
            d.getCoefficients().set(i, a.getCoefficients().get(i) * b.getCoefficients().get(i));

//        finalResult.getCoefficients().set(0, d.getCoefficients().get(0));
//        finalResult.getCoefficients().set(a.getSize() + b.getSize() - 2, d.getCoefficients().get(a.getSize() - 1));

        int startIndex = 0, endIndex = 0;
        for (int i = 1; i < processCount; i++) {
            startIndex = endIndex;
            endIndex = startIndex + step;
            if (i == processCount - 1) {
                endIndex = finalResult.getSize();
            }

            MPI.COMM_WORLD.Send(new int[]{startIndex}, 0, 1, MPI.INT, i, 0);
            MPI.COMM_WORLD.Send(new int[]{endIndex}, 0, 1, MPI.INT, i, 0);

            MPI.COMM_WORLD.Send(new Object[]{a.getCoefficients()}, 0, 1, MPI.OBJECT, i, 0);
            MPI.COMM_WORLD.Send(new Object[]{b.getCoefficients()}, 0, 1, MPI.OBJECT, i, 0);

            MPI.COMM_WORLD.Send(new Object[]{d.getCoefficients()}, 0, 1, MPI.OBJECT, i, 0);
        }

        Object[] results = new Object[processCount - 1];
        for (int i = 1; i < processCount; i++) {
            MPI.COMM_WORLD.Recv(results, i - 1, 1, MPI.OBJECT, i, 0);
        }
        for (var o : results) {
            System.out.println(o);
            finalResult = finalResult.addition(new Polynomial((List<Integer>) o));
        }
        System.out.println(a);
        System.out.println(b);
        System.out.println(finalResult);
    }

    public static void childProcess() {
        int[] startIndex = new int[1];
        int[] endIndex = new int[1];

        Object[] oA = new Object[1];
        Object[] oB = new Object[1];
        Object[] oD = new Object[1];

        Polynomial a, b, d;

        MPI.COMM_WORLD.Recv(startIndex, 0, 1, MPI.INT, 0, 0);
        MPI.COMM_WORLD.Recv(endIndex, 0, 1, MPI.INT, 0, 0);


        MPI.COMM_WORLD.Recv(oA, 0, 1, MPI.OBJECT, 0, 0);
        MPI.COMM_WORLD.Recv(oB, 0, 1, MPI.OBJECT, 0, 0);
        MPI.COMM_WORLD.Recv(oD, 0, 1, MPI.OBJECT, 0, 0);

        a = new Polynomial((List<Integer>) oA[0]);
        b = new Polynomial((List<Integer>) oB[0]);
        d = new Polynomial((List<Integer>) oD[0]);

        Polynomial result = algorithm(startIndex[0], endIndex[0], a, b, d);

        MPI.COMM_WORLD.Send(new Object[]{result.getCoefficients()}, 0, 1, MPI.OBJECT, 0, 0);
    }
}
