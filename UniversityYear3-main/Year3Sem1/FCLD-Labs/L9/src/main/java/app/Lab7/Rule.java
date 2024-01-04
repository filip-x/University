package app.Lab7;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;

import java.util.List;

@Builder
@AllArgsConstructor
public class Rule {// RULE are o singura bucata dintr-un production
    public interface Element{
        Element clone();
    }
    @AllArgsConstructor
    @Builder
    @Data
    public static class Terminal implements Element{

        String value;

        @Override
        public Element clone() {
            return Terminal.builder().value(value).build();
        }
    }
    @AllArgsConstructor
    @Builder
    @Data
    public static class NonTerminal implements Element{
        Production value;
        @Builder.Default
        Integer extra= 0;

        @Override
        public Element clone() {
            return NonTerminal.builder().extra(extra).value(value).build();
        }
    }
    List<Element>value;
}

