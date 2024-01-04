package app.Lab5;

import app.Pair;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
// DFA -NDFA
//
public class FiniteAutomata {
    List<String> A; // states, the circles that we draw
    List<String> E; // on the arrows( alphabet of the langague)
    String start; // the start of the FiniteAutomata
    List<String>  finalStates; // the posible final states ( bcs there  can be more than one )
    HashMap<String, List<Pair>> descriptionOfTransitions;

    public FiniteAutomata(List<String> a, List<String> e, String start, List<String> finalStates, HashMap<String, List<Pair>> descriptionOfTransitions) {
        A = a;
        E = e;
        this.start = start;
        this.finalStates = finalStates;
        this.descriptionOfTransitions = descriptionOfTransitions;
    }
    // key: from where we begin( the state we begin at the moment)
    // values: pair of  edge and next state, (value from E, value from A)

    public boolean check(String s){

        return recursiveCheck(start,s);
    }
    public boolean recursiveCheck(String state, String token) {
        if (finalStates.contains(state) && token.length() == 0)
            return true;
        if (token.length() == 0)
            return false;
        String e = token.substring(0, 1);//si iei prima chestie

        for (Pair transitions :  descriptionOfTransitions.getOrDefault(state, new ArrayList<>())) {
            if (transitions.first.equals(e)) {
                if (recursiveCheck(transitions.second, token.substring(1)))// toate tranzicitile care au simbolul pe sageata
                    return true;

            }
        }
        return false;
    }

    public String toString() {
        StringBuilder sT = new StringBuilder();
        for (String key : descriptionOfTransitions.keySet()) {
            for (Pair t : descriptionOfTransitions.get(key)) {
                sT.append("Transition: ("+ key + ", "+t.first +") = "+t.second+"\n");
            }
        }
        return "States = " + A.toString() + "\n" +
                "Alphabet = " + E.toString() + "\n" +
                "Initial state = " + start + "\n" +
                "Final state = " + finalStates.toString() + "\n" +
                "Transitions: \n" + sT;
    }
}
