package app.Lab6;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;

public class GrammerFileConverter {
    public static Grammer read(String fileName) throws FileNotFoundException {
        try {
            File file = new File(fileName);
            Scanner scanner = new Scanner(file);
            List<String> N  = Arrays.asList(scanner.nextLine().split(" "));
            List<String> E  = Arrays.asList(scanner.nextLine().split(" "));
            String S = scanner.nextLine().strip();
            HashMap<Concat,List<Concat>> P = new HashMap<>();
            String line;
            Concat NTConcat = null;
            Set<String> symbols;
            Set<String> NT;
            List<String> pieceT;
            while (scanner.hasNextLine()){
                line = scanner.nextLine();
                pieceT =Arrays.asList(line.split("->"));
                NT = Arrays.stream(pieceT.get(0).split(",")).map(String::strip).collect(Collectors.toSet());
                if(NT.size() > 1)
                {
                    NTConcat = new Concat(NT);
                }
                else if(NT.size() == 1 )
                {
                    NTConcat = new Concat(Set.of(NT.stream().findFirst().get()));
                }
                symbols = Arrays.stream(pieceT.get(1).split(",")).map(String::strip).collect(Collectors.toSet());
                List<Concat> list = P.getOrDefault(NTConcat,new ArrayList<>());
                if(symbols.size() >1)
                {
                    list.add(new Concat(symbols));
                }
                else if( symbols.size() == 1)
                {
                    list.add(new Concat(Set.of(symbols.stream().findFirst().get())));
                }
                P.put(NTConcat,list);
            }
            return Grammer.builder()
                    .N(N)
                    .E(E)
                    .S(S)
                    .P(P)
                    .build();
        }
        catch (IOException e ){
            return  null;
        }
    }
}
