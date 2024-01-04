package app.Lab7;

import java.util.List;

public class RecursiveDescent {
    public ModelConfiguration expand(ModelConfiguration configuration) {
        if (configuration.inputStack.size() == 0 || configuration.inputStack.get(0) instanceof Rule.Terminal)
            return null;
        ModelConfiguration newConfig = configuration.clone();
        List<Rule.Element> inputStack = newConfig.inputStack;
        List<Rule.Element> workingStack = newConfig.workingStack;

        Rule.NonTerminal A = (Rule.NonTerminal) inputStack.get(0);
        workingStack.remove(0);
        for (int i = A.value.rules.get(0).value.size() - 1; i >=0; i--) {
            inputStack.add(0, A.value.rules.get(0).value.get(i));
        }
        workingStack.add(A);
        return newConfig;
    }

    public ModelConfiguration advance(ModelConfiguration configuration) {
        if (configuration.inputStack.size() == 0 || configuration.inputStack.get(0) instanceof Rule.NonTerminal)
            return null;
        ModelConfiguration newConfig = configuration.clone();
        newConfig.index = newConfig.index + 1;
        List<Rule.Element> inputStack = newConfig.inputStack;
        List<Rule.Element> workingStack = newConfig.workingStack;

        Rule.Terminal a1 = (Rule.Terminal) inputStack.get(0);
        inputStack.remove(0);
        workingStack.add(a1);
        return newConfig;
    }

    public ModelConfiguration momentaryInsuccess(ModelConfiguration configuration) {
        if (configuration.inputStack.size() == 0 || configuration.inputStack.get(0) instanceof Rule.NonTerminal)
            return null;
        ModelConfiguration newConfig = configuration.clone();
        newConfig.stateType = ModelConfiguration.StateType.b;
        return newConfig;
    }

    public ModelConfiguration back(ModelConfiguration configuration) {
        if (configuration.workingStack.size() == 0 || configuration.workingStack.get(configuration.workingStack.size() - 1) instanceof Rule.NonTerminal)
            return null;
        ModelConfiguration newConfig = configuration.clone();
        newConfig.index = newConfig.index - 1;
        List<Rule.Element> inputStack = newConfig.inputStack;
        List<Rule.Element> workingStack = newConfig.workingStack;

        Rule.Terminal a1 = (Rule.Terminal) workingStack.get(configuration.workingStack.size() - 1);
        workingStack.remove(configuration.workingStack.size() - 1);
        inputStack.add(a1);
        return newConfig;
    }

    public ModelConfiguration anotherTry(ModelConfiguration configuration) {
        return null;
    }


    public ModelConfiguration success(ModelConfiguration configuration) {
        ModelConfiguration newConfig = configuration.clone();
        newConfig.stateType = ModelConfiguration.StateType.f;
        return newConfig;
    }
}
