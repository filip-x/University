package com.app;

import mpi.*;

public class Main {

    public static void main(String[] args) {
        MPI.Init(args);
//        ClassicMultiplication.run();
        KaratsubaMultiplication.run();
    }
}
