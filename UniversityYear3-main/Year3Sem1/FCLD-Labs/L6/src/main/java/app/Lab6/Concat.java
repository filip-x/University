package app.Lab6;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Getter;

import java.util.List;
import java.util.Objects;
import java.util.Set;


@Builder
@Getter
@AllArgsConstructor
public class Concat {
    Set<String> symbols;

    public String toString()
    {
        StringBuilder stringBuilder = new StringBuilder();
        List<String> listSymbol = List.copyOf(symbols);
        for(int i =0;i<symbols.size()-1;i++)
        {
            stringBuilder.append(listSymbol.get(i)).append(", ");
        }
        stringBuilder.append(listSymbol.get(symbols.size()-1));
        return stringBuilder.toString();
    }
    @Override // for the dictionary
     public boolean equals(Object o){
       if(this == o)
         {
             return  true;
         }
       if(o == null || getClass()!=o.getClass())
           return false;
       Concat that = (Concat) o;
       return Objects.equals(symbols,that.symbols);
     }
     @Override
     public int hashCode(){
        return Objects.hash(symbols);
     }
}
