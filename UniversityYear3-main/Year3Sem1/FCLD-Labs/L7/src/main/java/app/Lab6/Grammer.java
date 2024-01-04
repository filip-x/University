package app.Lab6;


import lombok.Builder;

import java.util.HashMap;
import java.util.List;

@Builder
public class Grammer {

    List<String> N; // Set of non-terminals
    List<String> E; // Set of terminals
    String S; // Start symbol
    HashMap<Concat, List<Concat>> P;

    public String toString()
    {
        StringBuilder stringBuilder = new StringBuilder();
        for(Concat key : P.keySet())
        {
            for(Concat t: P.get(key))
            {
                stringBuilder.append(key).append("->").append(t.toString()).append("\n");
            }
        }
        return "N = " + N.toString() + "\n" +
                "E = " + E.toString() + "\n" +
                "Start symbol = " + S + "\n" +
                "Productions: \n" + stringBuilder;
    }
    public boolean isCFG(){// CFg -> left side we ha ve a single symbol  and that symbol should be non terminal( it has other productions) terminal ( has no productions "Read")
        for(Concat key: P.keySet())
        {
            if(key.symbols.size() != 1)
            {
                return  false;
            }
            if(!N.contains(key.symbols.stream().findFirst().get().toString()))
            {
                return false;
            }
        }
        return  true;
    }
}
