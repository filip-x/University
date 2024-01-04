package app.Lab7;

import lombok.Builder;
import lombok.Setter;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

@Builder
@Setter
public class RecursiveDescent {
    String inputText;
    Rule.NonTerminal initialInput;
    public ModelConfiguration run() {
        int n = inputText.length();
        ModelConfiguration configuration = ModelConfiguration
                .builder()
                .stateType(ModelConfiguration.StateType.q)
                .index(1)
                .workingStack(new ArrayList<>())
                .inputStack(List.of(initialInput))
                .build();
        while (configuration.getStateType() != ModelConfiguration.StateType.f
                && configuration.getStateType() != ModelConfiguration.StateType.e) {
            if (configuration.getStateType() == ModelConfiguration.StateType.q) {
                if (configuration.getInputStack().isEmpty()) {
                    if (n + 1 == configuration.getIndex())
                        configuration = success(configuration);
                    else configuration.stateType = ModelConfiguration.StateType.e;
                } else {
                    if (configuration.getInputStack().get(0) instanceof Rule.NonTerminal) {
                        configuration = expand(configuration);
                    } else {
                        if (configuration.getIndex() <= n && Objects.equals(((Rule.Terminal) configuration.getInputStack().get(0)).value, inputText.substring(configuration.getIndex() - 1, configuration.getIndex()))) {
                            configuration = advance(configuration);
                        } else {
                            configuration = momentaryInsuccess(configuration);
                        }
                    }
                }
            } else {
                if (configuration.getStateType() == ModelConfiguration.StateType.b) {
                    if (!configuration.getWorkingStack().isEmpty()) {
                        if (configuration.getWorkingStack().get(configuration.getWorkingStack().size() - 1) instanceof Rule.Terminal) {
                            configuration = back(configuration);
                        } else {
                            configuration = anotherTry(configuration);
                        }
                    } else {
                        configuration.stateType = ModelConfiguration.StateType.e;
                    }
                }
            }
        }

        if (configuration.getStateType() == ModelConfiguration.StateType.e) {
            System.out.println("Error");
        } else {
            System.out.println("Sequence accepted");
        }
        return configuration;
    }

    public ModelConfiguration expand(ModelConfiguration configuration) {
        if (configuration.stateType != ModelConfiguration.StateType.q)
            return null;
        if (configuration.inputStack.size() == 0 || configuration.inputStack.get(0) instanceof Rule.Terminal)
            return null;
        ModelConfiguration newConfig = configuration.clone();
        List<Rule.Element> inputStack = newConfig.inputStack;
        List<Rule.Element> workingStack = newConfig.workingStack;

        Rule.NonTerminal A = (Rule.NonTerminal) inputStack.get(0);
        A.extra = 1;
        inputStack.remove(0);
        for (int i = A.value.rules.get(0).value.size() - 1; i >=0; i--) {
            inputStack.add(0, A.value.rules.get(0).value.get(i));
        }
        workingStack.add(A);
        return newConfig;
    }

    public ModelConfiguration advance(ModelConfiguration configuration) {
        if (configuration.stateType != ModelConfiguration.StateType.q)
            return null;
        if (configuration.inputStack.size() == 0 || configuration.inputStack.get(0) instanceof Rule.NonTerminal)
            return null;
        Rule.Terminal head = (Rule.Terminal) configuration.inputStack.get(0);
        if (!Objects.equals(head.value, inputText.substring(configuration.index - 1, configuration.index)))
            return null;
        ModelConfiguration newConfig = configuration.clone();
        newConfig.index = newConfig.index + 1;
        List<Rule.Element> inputStack = newConfig.inputStack;
        List<Rule.Element> workingStack = newConfig.workingStack;

        inputStack.remove(0);
        workingStack.add(head);
        return newConfig;
    }

    public ModelConfiguration momentaryInsuccess(ModelConfiguration configuration) {
        if (configuration.stateType != ModelConfiguration.StateType.q)
            return null;
        if (configuration.inputStack.size() == 0 || configuration.inputStack.get(0) instanceof Rule.NonTerminal)
            return null;
        Rule.Terminal head = (Rule.Terminal) configuration.inputStack.get(0);
//        if (Objects.equals(head.value, inputText.substring(configuration.index - 1, configuration.index)))
//            return null;
        ModelConfiguration newConfig = configuration.clone();
        newConfig.stateType = ModelConfiguration.StateType.b;
        return newConfig;
    }

    public ModelConfiguration back(ModelConfiguration configuration) {
        if (configuration.stateType != ModelConfiguration.StateType.b)
            return null;
        if (configuration.workingStack.size() == 0 || configuration.workingStack.get(configuration.workingStack.size() - 1) instanceof Rule.NonTerminal)
            return null;
        ModelConfiguration newConfig = configuration.clone();
        newConfig.index = newConfig.index - 1;
        List<Rule.Element> inputStack = newConfig.inputStack;
        List<Rule.Element> workingStack = newConfig.workingStack;

        Rule.Terminal a1 = (Rule.Terminal) workingStack.get(configuration.workingStack.size() - 1);
        workingStack.remove(configuration.workingStack.size() - 1);
        inputStack.add(0, a1);
        return newConfig;
    }

    public ModelConfiguration anotherTry(ModelConfiguration configuration) {
        if (configuration.stateType != ModelConfiguration.StateType.b)
            return null;
        if (configuration.workingStack.size() == 0 || configuration.inputStack.size() == 0 || !(configuration.workingStack.get(configuration.workingStack.size() - 1) instanceof Rule.NonTerminal))
            return null;
        Rule.NonTerminal A = (Rule.NonTerminal) configuration.workingStack.get(configuration.workingStack.size() - 1);
        if (A.extra <= 0)
            return null;
        List<Rule.Element> fi = A.value.rules.get(A.extra - 1).value;
//        for (int i = 0; i < fi.size(); i++)
//            if (fi.get(i) != configuration.inputStack.get(i))
//                return null;
        if (A.value.rules.size() >= A.extra + 1) {
            ModelConfiguration newConfig = configuration.clone();
            List<Rule.Element> inputStack = newConfig.inputStack;
            List<Rule.Element> workingStack = newConfig.workingStack;
            Rule.NonTerminal Aj = (Rule.NonTerminal) workingStack.get(workingStack.size() - 1);
            Aj.extra = A.extra;
            if (fi.size() > 0) {
                inputStack.subList(0, fi.size()).clear();
            }
            fi = Aj.value.rules.get(A.extra).value;
            for (int i = fi.size() - 1; i >=0; i--) {
                inputStack.add(0, fi.get(i));
            }
            Aj.extra++;
            newConfig.stateType = ModelConfiguration.StateType.q;
            return newConfig;
        } else if (configuration.index == 1 && configuration.workingStack.get(configuration.workingStack.size() - 1).equals(initialInput)) {
            ModelConfiguration newConfig = configuration.clone();
            List<Rule.Element> inputStack = newConfig.inputStack;
            List<Rule.Element> workingStack = newConfig.workingStack;
            if (fi.size() > 0) {
                inputStack.subList(0, fi.size()).clear();
            }
            workingStack.remove(workingStack.size() - 1);
            newConfig.stateType = ModelConfiguration.StateType.e;
            return newConfig;
        } else {
            ModelConfiguration newConfig = configuration.clone();
            List<Rule.Element> inputStack = newConfig.inputStack;
            List<Rule.Element> workingStack = newConfig.workingStack;
            Rule.NonTerminal Aj = (Rule.NonTerminal) workingStack.get(workingStack.size() - 1);
            if (fi.size() > 0) {
                inputStack.subList(0, fi.size()).clear();
            }
            workingStack.remove(workingStack.size() - 1);
            inputStack.add(0, Aj);
            Aj.extra = 0;
            return newConfig;
        }
    }


    public ModelConfiguration success(ModelConfiguration configuration) {
        if (configuration.stateType != ModelConfiguration.StateType.q)
            return null;
        if (!configuration.inputStack.isEmpty() || configuration.index != inputText.length() + 1)
            return null;
        ModelConfiguration newConfig = configuration.clone();
        newConfig.stateType = ModelConfiguration.StateType.f;
        return newConfig;
    }
}
