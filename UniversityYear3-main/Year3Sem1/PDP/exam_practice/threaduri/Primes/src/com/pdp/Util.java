package com.pdp;

import java.util.List;

public class Util {
    public static boolean isPrime(int nr, List<Integer> primesUpToRadicalN) {
        if (nr == 2) {
            return true;
        }
        else {
            for (int prime : primesUpToRadicalN) {
                if (nr % prime == 0)
                    return false;
            }
        }
        return true;
    }
}
