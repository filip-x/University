package app.Lab7;

import lombok.AllArgsConstructor;
import lombok.Builder;

import java.util.List;

@Builder
public class Rule {
    static interface Element{
        Element clone();
    }
    @AllArgsConstructor
    @Builder
    static class Terminal implements Element{

        String value;

        @Override
        public Element clone() {
            return Terminal.builder().value(value).build();
        }
    }
    @AllArgsConstructor
    @Builder
    static class NonTerminal implements Element{
        Production value;

        @Override
        public Element clone() {
            return NonTerminal.builder().value(value).build();
        }
    }
    List<Element>value;
}

