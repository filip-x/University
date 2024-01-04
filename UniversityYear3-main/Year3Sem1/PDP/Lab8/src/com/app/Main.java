package com.app;

import mpi.*;

public class Main {

    public static void main(String[] args) throws InterruptedException {
        MPI.Init(args);

        DSM dsm = new DSM();
        int rankOfTheProcess = MPI.COMM_WORLD.Rank();
        if (rankOfTheProcess == 0) {
            Thread thread = new Thread(new Process(dsm));

            thread.start();

            dsm.subscribeToVariable("a");
            dsm.subscribeToVariable("b");
            dsm.subscribeToVariable("c");
            dsm.compareAndExchange("a",30,60);
            dsm.compareAndExchange("c",32,64);
            dsm.compareAndExchange("b",500, 10000);
            dsm.close();

            thread.join();

        } else if (rankOfTheProcess == 1) {
            Thread thread = new Thread(new Process(dsm));

            thread.start();

            dsm.subscribeToVariable("a");
            dsm.subscribeToVariable("b");
            dsm.subscribeToVariable("c");

            thread.join();
        } else if (rankOfTheProcess == 2) {
            Thread thread = new Thread(new Process(dsm));

            thread.start();

            dsm.subscribeToVariable("b");
            dsm.subscribeToVariable("c");
            dsm.compareAndExchange("b", 31, 500);

            thread.join();
        }
        MPI.Finalize();
    }
}
