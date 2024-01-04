import app.Lab7.ModelConfiguration;
import app.Lab7.Production;
import app.Lab7.RecursiveDescent;
import app.Lab7.Rule;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class ParserTest {
    RecursiveDescent recursiveDescent = RecursiveDescent.builder().build();

    @Test
    void run() {
        List<Rule> rules = new ArrayList<>();
        Production p = Production.builder().nonTerm("S").rules(rules).build();
        Rule.NonTerminal S = Rule.NonTerminal.builder().extra(0).value(p).build();
        List<Rule.Element> fi1 = List.of(new Rule.Terminal("a"), S, new Rule.Terminal("b"), S);
        List<Rule.Element> fi2 = List.of(new Rule.Terminal("a"), S);
        List<Rule.Element> fi3 = List.of(new Rule.Terminal("c"));
        rules.add(new Rule(fi1));
        rules.add(new Rule(fi2));
        rules.add(new Rule(fi3));

        recursiveDescent.setInputText("acbc");
        recursiveDescent.setInitialInput(S);

        ModelConfiguration result = recursiveDescent.run();
        StringBuilder s = new StringBuilder();
        for (var e: result.getWorkingStack())
            if (e instanceof Rule.NonTerminal)
                s.append(((Rule.NonTerminal) e).getValue().getNonTerm()).append(((Rule.NonTerminal) e).getExtra());
            else if (e instanceof Rule.Terminal)
                s.append(((Rule.Terminal) e).getValue());
        System.out.println(s.toString());
    }

    @Test
    void success() {
        recursiveDescent.setInputText("");
        ModelConfiguration testConfig = ModelConfiguration.builder()
                .stateType(ModelConfiguration.StateType.q)
                .workingStack(new ArrayList<>())
                .index(1)
                .inputStack(new ArrayList<>())
                .build();
        ModelConfiguration resultConfig = recursiveDescent.success(testConfig);
        assertEquals(resultConfig.getStateType(), ModelConfiguration.StateType.f);
    }

    @Test
    void expand_solo() {
        List<Rule.Element> fi1 = List.of(new Rule.Terminal("a"), new Rule.Terminal("b"));
        List<Rule.Element> fi2 = List.of(new Rule.Terminal("b"), new Rule.Terminal("c"));
        List<Rule.Element> fi3 = List.of(new Rule.Terminal("a"), new Rule.Terminal("c"));
        List<Rule> rules = List.of(new Rule(fi1), new Rule(fi2), new Rule(fi3));
        Production p = Production.builder().rules(rules).build();
        Rule.NonTerminal Aj = Rule.NonTerminal.builder().extra(2).value(p).build();
        Aj.setExtra(0);

        recursiveDescent.setInitialInput(Aj);
        recursiveDescent.setInputText("hello");
        ModelConfiguration testConfig = ModelConfiguration.builder()
                .stateType(ModelConfiguration.StateType.q)
                .workingStack(new ArrayList<>())
                .index(3)
                .inputStack(List.of(Aj))
                .build();
        ModelConfiguration resultConfig = recursiveDescent.expand(testConfig);
        assertEquals(resultConfig.getStateType(), ModelConfiguration.StateType.q);
        assertEquals(resultConfig.getIndex(),3);
        assertEquals(resultConfig.getInputStack().size(), 2);
        assertEquals(resultConfig.getWorkingStack().size(), 1);
        assertEquals(((Rule.NonTerminal) resultConfig.getWorkingStack().get(0)).getExtra(), 1);
    }

    @Test
    void advance_solo() {
        List<Rule.Element> fi1 = List.of(new Rule.Terminal("a"), new Rule.Terminal("b"));
        List<Rule.Element> fi2 = List.of(new Rule.Terminal("b"), new Rule.Terminal("c"));
        List<Rule.Element> fi3 = List.of(new Rule.Terminal("a"), new Rule.Terminal("c"));
        List<Rule> rules = List.of(new Rule(fi1), new Rule(fi2), new Rule(fi3));
        Production p = Production.builder().rules(rules).build();
        Rule.NonTerminal Aj = Rule.NonTerminal.builder().extra(2).value(p).build();
        Aj.setExtra(0);

        recursiveDescent.setInitialInput(Aj);
        recursiveDescent.setInputText("abababa");
        ModelConfiguration testConfig = ModelConfiguration.builder()
                .stateType(ModelConfiguration.StateType.q)
                .workingStack(new ArrayList<>())
                .index(1)
                .inputStack(fi1)
                .build();
        ModelConfiguration resultConfig = recursiveDescent.advance(testConfig);
        assertEquals(resultConfig.getStateType(), ModelConfiguration.StateType.q);
        assertEquals(resultConfig.getIndex(),2);
        assertEquals(resultConfig.getInputStack().size(), 1);
        assertEquals(resultConfig.getWorkingStack().size(), 1);
    }

    @Test
    void momentaryInsuccess_solo() {
        List<Rule.Element> fi1 = List.of(new Rule.Terminal("a"), new Rule.Terminal("b"));
        List<Rule.Element> fi2 = List.of(new Rule.Terminal("b"), new Rule.Terminal("c"));
        List<Rule.Element> fi3 = List.of(new Rule.Terminal("a"), new Rule.Terminal("c"));
        List<Rule> rules = List.of(new Rule(fi1), new Rule(fi2), new Rule(fi3));
        Production p = Production.builder().rules(rules).build();
        Rule.NonTerminal Aj = Rule.NonTerminal.builder().extra(2).value(p).build();
        Aj.setExtra(0);

        recursiveDescent.setInitialInput(Aj);
        recursiveDescent.setInputText("abababa");
        ModelConfiguration testConfig = ModelConfiguration.builder()
                .stateType(ModelConfiguration.StateType.q)
                .workingStack(new ArrayList<>())
                .index(1)
                .inputStack(fi2)
                .build();
        ModelConfiguration resultConfig = recursiveDescent.momentaryInsuccess(testConfig);
        assertEquals(resultConfig.getStateType(), ModelConfiguration.StateType.b);
        assertEquals(resultConfig.getIndex(),1);
        assertEquals(resultConfig.getInputStack().size(), 2);
        assertEquals(resultConfig.getWorkingStack().size(), 0);
    }

    @Test
    void back_solo() {
        List<Rule.Element> fi1 = List.of(new Rule.Terminal("a"), new Rule.Terminal("b"));
        List<Rule.Element> fi2 = List.of(new Rule.Terminal("b"), new Rule.Terminal("c"));
        List<Rule.Element> fi3 = List.of(new Rule.Terminal("a"), new Rule.Terminal("c"));
        List<Rule> rules = List.of(new Rule(fi1), new Rule(fi2), new Rule(fi3));
        Production p = Production.builder().rules(rules).build();
        Rule.NonTerminal Aj = Rule.NonTerminal.builder().extra(2).value(p).build();
        Aj.setExtra(0);

        recursiveDescent.setInitialInput(Aj);
        recursiveDescent.setInputText("abababa");
        ModelConfiguration testConfig = ModelConfiguration.builder()
                .stateType(ModelConfiguration.StateType.b)
                .workingStack(fi2)
                .index(2)
                .inputStack(new ArrayList<>())
                .build();
        ModelConfiguration resultConfig = recursiveDescent.back(testConfig);
        assertEquals(resultConfig.getStateType(), ModelConfiguration.StateType.b);
        assertEquals(resultConfig.getIndex(),1);
        assertEquals(resultConfig.getInputStack().size(), 1);
        assertEquals(resultConfig.getWorkingStack().size(), 1);
    }

    @Test
    void anotherTry_q_case() {
        List<Rule.Element> fi1 = List.of(new Rule.Terminal("a"), new Rule.Terminal("b"));
        List<Rule.Element> fi2 = List.of(new Rule.Terminal("b"), new Rule.Terminal("c"));
        List<Rule.Element> fi3 = List.of(new Rule.Terminal("a"), new Rule.Terminal("c"));
        List<Rule> rules = List.of(new Rule(fi1), new Rule(fi2), new Rule(fi3));
        Production p = Production.builder().rules(rules).build();
        Rule.NonTerminal Aj = Rule.NonTerminal.builder().extra(2).value(p).build();
        Aj.setExtra(2);

        recursiveDescent.setInitialInput(Aj);
        recursiveDescent.setInputText("hello");
        ModelConfiguration testConfig = ModelConfiguration.builder()
                .stateType(ModelConfiguration.StateType.b)
                .workingStack(List.of(Aj))
                .index(3)
                .inputStack(fi2)
                .build();
        ModelConfiguration resultConfig = recursiveDescent.anotherTry(testConfig);
        assertEquals(resultConfig.getStateType(), ModelConfiguration.StateType.q);
        assertEquals(resultConfig.getIndex(),3);
        assertEquals(resultConfig.getInputStack(), fi3);
        assertEquals(resultConfig.getWorkingStack().size(), 1);
        assertEquals(((Rule.NonTerminal) resultConfig.getWorkingStack().get(0)).getExtra(), 3);
    }

    @Test
    void anotherTry_b_case() {
        List<Rule.Element> fi1 = List.of(new Rule.Terminal("a"), new Rule.Terminal("b"));
        List<Rule.Element> fi2 = List.of(new Rule.Terminal("b"), new Rule.Terminal("c"));
        List<Rule.Element> fi3 = List.of(new Rule.Terminal("a"), new Rule.Terminal("c"));
        List<Rule> rules = List.of(new Rule(fi1), new Rule(fi2), new Rule(fi3));
        Production p = Production.builder().rules(rules).build();
        Rule.NonTerminal Aj = Rule.NonTerminal.builder().extra(2).value(p).build();
        Aj.setExtra(3);

        recursiveDescent.setInitialInput(Aj);
        recursiveDescent.setInputText("hello");
        ModelConfiguration testConfig = ModelConfiguration.builder()
                .stateType(ModelConfiguration.StateType.b)
                .workingStack(List.of(Aj))
                .index(3)
                .inputStack(fi3)
                .build();
        ModelConfiguration resultConfig = recursiveDescent.anotherTry(testConfig);
        assertEquals(resultConfig.getStateType(), ModelConfiguration.StateType.b);
        assertEquals(resultConfig.getIndex(),3);
        assertEquals(resultConfig.getInputStack().size(), 1);
        assertEquals(resultConfig.getWorkingStack().size(), 0);
        assertEquals(((Rule.NonTerminal) resultConfig.getInputStack().get(0)).getExtra(), 0);
    }

    @Test
    void anotherTry_e_case() {
        List<Rule.Element> fi1 = List.of(new Rule.Terminal("a"), new Rule.Terminal("b"));
        List<Rule.Element> fi2 = List.of(new Rule.Terminal("b"), new Rule.Terminal("c"));
        List<Rule.Element> fi3 = List.of(new Rule.Terminal("a"), new Rule.Terminal("c"));
        List<Rule> rules = List.of(new Rule(fi1), new Rule(fi2), new Rule(fi3));
        Production p = Production.builder().rules(rules).build();
        Rule.NonTerminal Aj = Rule.NonTerminal.builder().extra(2).value(p).build();
        Aj.setExtra(3);

        recursiveDescent.setInitialInput(Aj);
        recursiveDescent.setInputText("hello");
        ModelConfiguration testConfig = ModelConfiguration.builder()
                .stateType(ModelConfiguration.StateType.b)
                .workingStack(List.of(Aj))
                .index(1)
                .inputStack(fi3)
                .build();
        ModelConfiguration resultConfig = recursiveDescent.anotherTry(testConfig);
        assertEquals(resultConfig.getStateType(), ModelConfiguration.StateType.e);
        assertEquals(resultConfig.getInputStack().size(), 0);
        assertEquals(resultConfig.getWorkingStack().size(), 0);
    }
}
