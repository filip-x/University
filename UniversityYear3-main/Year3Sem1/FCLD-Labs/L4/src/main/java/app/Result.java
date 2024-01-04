package app;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;

import java.util.List;

@Data
@AllArgsConstructor
public class Result {
    SymbolTable st;
    List<String> pif;
    String errorMessage;
}
