package app;

import lombok.Data;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
@Data
public class SymbolTable {
    private List<List<AcceptedToken>> storageOfTokens;
    private Integer capacity = 2000;
    private Integer size = 0;

    public SymbolTable()
    {
        storageOfTokens = new ArrayList<>(Collections.nCopies(capacity,null));// we make all of the elements null (the size of the capacity)
    }

    public PositionHash tokenExists(AcceptedToken t){
        int hashValue = hashFunction(t.getValueOfDataType());
        int position = hashValue % capacity;

        if(storageOfTokens.get(position) != null && storageOfTokens.get(position).contains(t)) {
            System.out.println(position + "->"+t.getValueOfDataType());
            return new PositionHash(position, storageOfTokens.get(position).indexOf(t));
        }
        return null;
    }
    public AcceptedToken find(PositionHash position)
    {
        if(position.getFirst() < capacity && storageOfTokens.get(position.getFirst())!= null)
        {
            if(position.getSecond() < storageOfTokens.get(position.getFirst()).size() && storageOfTokens.get(position.getFirst()).get(position.getSecond())!= null)
                return  storageOfTokens.get(position.getFirst()).get(position.getSecond());
            return  null;
        }
        return  null;
    }
    private int hashFunction(String str){
        System.out.println("hash " + str + " - " + str.chars().sum());
        return str.chars().sum();
    }


    public PositionHash add(AcceptedToken t) {
        PositionHash position = tokenExists(t);
        if (position != null) {
            return position;
        }
        if (size + 1 > 0.80 * capacity) {
            grow();
        }
        size += 1;
        int hashValue = hashFunction(t.getValueOfDataType());
        int pos = hashValue % capacity;
        if (storageOfTokens.get(pos) == null) {
            storageOfTokens.set(pos, new ArrayList<>());// initilize this position if it does not exist ( pana cacum)
        }
        storageOfTokens.get(pos).add(t);
        return new PositionHash(pos,storageOfTokens.get(pos).size()-1);
    }

    private void grow(){
        var oldStorage = storageOfTokens;
        capacity = capacity *2;
        size = 0;
        storageOfTokens = new ArrayList<>(Collections.nCopies(capacity,null));
        oldStorage.forEach((list) ->{
            if(list != null)
            {
                list.forEach(this::add);
            }
        });
    }

}
