package app;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.regex.Pattern;
import java.util.regex.Matcher;




public class Regex {


    List<Pair> regexList = new ArrayList<>();
    Regex()
    {
         String constantInt = ("^\\s*([+-]?\\d+)(?![a-zA-Z_0-9])");
         String constantCharacter = ("^\\s*('.')");
         String constantString = ("^\\s*(\".*\")");
         String separator = ("^\\s*(>>|<<|!=|==|>=|<=|[\\+\\-\\*/%<=>\\[\\]\\{\\}\\(\\):;])");
         String keyword = ("^\\s*(Read|Write|var|if|else|not|and|or|while|exit|main)");
         String identifier = ("^\\s*([a-zA-Z_][a-zA-Z0-9_]*)");

        regexList.add(new Pair(constantInt, "constantInt"));
        regexList.add(new Pair(constantCharacter,"constantChar"));
        regexList.add(new Pair(constantString,"constantString"));
        regexList.add(new Pair(separator,"separator"));
        regexList.add(new Pair(keyword,"keyword"));
        regexList.add(new Pair(identifier,"identifier"));
    }
    public List<String> detect(String code){//da primul token din string
        for(Pair element: regexList){
            Pattern pattern  = Pattern.compile(element.getFirst());
            Matcher matcher = pattern.matcher(code);
            if(matcher.find()){

                return List.of(code.substring(matcher.end()),matcher.group(1), element.getSecond());// o lista formata din restul liniei fara token, token-ul himself si tipul token-ului
            }
        }
        return null;
    }

    public boolean isEmptyLine(String code){
        String emptyLine = ("^\\s*$");
        Matcher matcher = Pattern.compile(emptyLine).matcher(code);
        return matcher.find();
    }
}
