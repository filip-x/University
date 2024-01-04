package app.Lab7;

import lombok.Builder;
import lombok.Getter;

import java.util.List;

@Builder
@Getter
public class Production {
    // nonTerminal -> rule1 | rule2 | ...| rule-n
        String nonTerm;
        List<Rule> rules;
    }
