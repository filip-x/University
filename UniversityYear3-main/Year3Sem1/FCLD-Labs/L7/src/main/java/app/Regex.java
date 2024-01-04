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
        // pe toata linia ( primul token)
         String constantInt = ("^\\s*([+-]?\\d+)(?![a-zA-Z_0-9])");//
        // reg ex sunt ca niste conditii; ex pentru int: first poate sa inceapa cu oricate whitespace-uri (spatii/tab-uri)
        // dupa poate sau nu sa aibe semn, iar dupa semn trebuie sa apara neaparat macar o cifra.
        // la final mai avem conditia ca dupa numar in nici un caz nu pot aparea litere direct lipite (ex 12a)
         String constantCharacter = ("^\\s*('.')");
         //poat eincepe cu oricate spatii, dupa te astepti sa fie un singur caracter (orice fel de caracter) intre doua ghilimele simple
         String constantString = ("^\\s*(\".*\")");
         // poate incepe cu oricate spatii, dupa te astepti sa fie oricate caractere (inclusiv nici unul) intre doua ghilimele duble
         String separator = ("^\\s*(>>|<<|!=|==|>=|<=|[\\+\\-\\*/%<=>\\[\\]\\{\\}\\(\\):;])");
         // poate incepe cu oricate spatii si dupa sa fie unul dintre alegeri din lista (ex sa fie >> sau << sau != etc
         String keyword = ("^\\s*(Read|Write|var|if|else|not|and|or|while|exit|main)");
         // same as above, dar cu cuvinte
         String identifier = ("^\\s*([a-zA-Z_][a-zA-Z0-9_]*)");
         // poate incepe cu oricate spatii, urmat de un caracter sau de _ (fara numere la inceput), dupa care poate fi orice litera, numar sau caracter _ underscore
        // identifier = nume de variabila

        regexList.add(new Pair(constantInt, "constantInt"));
        regexList.add(new Pair(constantCharacter,"constantChar"));
        regexList.add(new Pair(constantString,"constantString"));
        regexList.add(new Pair(separator,"separator"));
        regexList.add(new Pair(keyword,"keyword"));
        regexList.add(new Pair(identifier,"identifier"));
    }
    public List<String> detect(String code){//da primul token din string
        for(Pair element: regexList){
            Pattern pattern  = Pattern.compile(element.getFirst());// face din string in regex -> astefl incat sa putem sa procesezi string-uri
            Matcher matcher = pattern.matcher(code);// rulez pe string regex cu input-ul( toata linia  luata)
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
