package com.pdp;

import java.util.ArrayList;
import java.util.List;

public class Util {
    public static List<Integer> initializeEmptyArray(int arraySize) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0;i < arraySize; i++)
            res.add(0);
        return res;
    }

    public static List<Integer> addTwoLists(List<Integer> list1, List<Integer> list2, int listSize) {
        List<Integer> addition = Util.initializeEmptyArray(listSize);
        int carry = 0, sum, digit;

        for (int i = list1.size() - 1; i >= 0; i--) {
            sum = list1.get(i) + list2.get(i) + carry;

            digit = sum % 10;
            carry = sum / 10;

            addition.set(i, digit);
        }

        System.out.println("List1: " + list1);
        System.out.println("List2: " + list2);
        System.out.println("Result: " + addition);
        System.out.println("__________________");

        return addition;
    }
}
