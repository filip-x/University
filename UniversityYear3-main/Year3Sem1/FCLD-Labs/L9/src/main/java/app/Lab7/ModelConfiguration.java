package app.Lab7;

import lombok.Builder;
import lombok.Getter;

import java.util.ArrayList;
import java.util.List;

@Getter
@Builder
public class ModelConfiguration {
    public enum StateType{
        q,b,f,e;
    }

    StateType stateType;
    Integer index;
    List<Rule.Element> workingStack;
    List<Rule.Element> inputStack;

    public ModelConfiguration clone(){
        List<Rule.Element> newWorkingStack = new ArrayList<>();
        for(var e:workingStack)
        {
            newWorkingStack.add(e.clone());
        }
        List<Rule.Element> newInputStack = new ArrayList<>();
        for(var e:inputStack){
            newInputStack.add(e.clone());
        }
        return ModelConfiguration.builder()
                .stateType(stateType)
                .index(index)
                .workingStack(newWorkingStack)
                .inputStack(newInputStack)
                .build();
    }
}
