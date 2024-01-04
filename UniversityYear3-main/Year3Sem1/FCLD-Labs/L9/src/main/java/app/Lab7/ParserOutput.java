package app.Lab7;

import app.Lab6.Concat;
import app.Lab6.Grammer;
import app.Lab6.GrammerFileConverter;

import java.util.List;
import java.util.Set;
// face afisarea
public class ParserOutput {
    public static String build(List<Rule.Element> elements) {
        StringBuilder s = new StringBuilder();
        for (var e: elements)
            if (e instanceof Rule.NonTerminal)
                s.append(((Rule.NonTerminal) e).getValue().getNonTerm()).append(((Rule.NonTerminal) e).getExtra());// we append the nonterminal
            else if (e instanceof Rule.Terminal)
                s.append(((Rule.Terminal) e).getValue());//we append the terminal
        return s.toString();
    }


}
