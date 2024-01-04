package app.lab8;

import app.Lab6.Concat;
import app.Lab6.Grammer;
import app.Lab7.Production;
import app.Lab7.Rule;
import lombok.AllArgsConstructor;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Set;
// transforma grammar-ul pentru parsat

public class GrammarToRules {
    Grammer g;
    HashMap<String, Rule.Element> rules = new HashMap<>();

    public GrammarToRules(Grammer g) {
        this.g = g;
        for (var nonterm: g.getN()) {
            Production p = Production.builder().nonTerm(nonterm).rules(new ArrayList<>()).build();
            rules.put(nonterm, Rule.NonTerminal.builder().value(p).build());
        }
        for (var term: g.getE()) {
            rules.put(term, Rule.Terminal.builder().value(term).build());
        }
        for (var nonterm: g.getN()) {
            build(nonterm);
        }// we tranform the the grammar into the rules format
    }
    // S -> ab | cd
    public void build(String symbol) {
        List<Concat> productions = g.getP().get(new Concat(Set.of(symbol)));
        List<Rule> pRules = new ArrayList<>();
        for (Concat piece : productions) {
            List<Rule.Element> elems = new ArrayList<>();
            for (String pieceOfPiece : piece.getSymbols()) {
                elems.add(this.rules.get(pieceOfPiece));
            }
            pRules.add(new Rule(elems));
        }

        Production p = Production.builder().nonTerm(symbol).rules(pRules).build();
        Rule.NonTerminal S = Rule.NonTerminal.builder().extra(0).value(p).build();
        ((Rule.NonTerminal) rules.get(symbol)).setValue(p);
    }

    public Rule.NonTerminal getMainRule() {
        return (Rule.NonTerminal) rules.get(g.getS());
    }
}
