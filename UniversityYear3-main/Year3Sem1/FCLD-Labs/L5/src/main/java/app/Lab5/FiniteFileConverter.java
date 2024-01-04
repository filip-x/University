package app.Lab5;

import app.Pair;

import java.io.File;
import java.io.IOException;
import java.util.*;

public class FiniteFileConverter {
    public static FiniteAutomata read(String fileName){
        try {
            File file  =new File(fileName);
            Scanner scanner = new Scanner(file);
            List<String> A = Arrays.asList(scanner.nextLine().split(" "));
            List<String> E = Arrays.asList(scanner.nextLine().split(" "));
            String start = scanner.nextLine().strip();
            List<String> finalStates =Arrays.asList(scanner.nextLine().split(" "));
            HashMap<String,List<Pair>> descriptionOfTransitions = new HashMap<>();
            String line,R0,e,P0;
            List<String> transition;
            List<Pair> transitionList;
            while(scanner.hasNextLine()){
                line = scanner.nextLine();
                transition = Arrays.asList(line.split(" "));
                R0 = transition.get(0);// unde incepe
                e = transition.get(1); // pe arrow
                P0 = transition.get(2);// unde ajunge
                transitionList = descriptionOfTransitions.getOrDefault(R0,new ArrayList<>());
                transitionList.add(new Pair (e,P0));
                descriptionOfTransitions.put(R0,transitionList);
            }
            return new FiniteAutomata(A,E,start,finalStates,descriptionOfTransitions);
        }
        catch (IOException e){
            return null;
        }
    }
}
