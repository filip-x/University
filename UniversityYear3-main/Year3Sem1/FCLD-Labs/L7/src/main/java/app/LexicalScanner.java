package app;

import lombok.Builder;
import lombok.Data;

import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.Scanner;
import app.Result;
public class LexicalScanner {
    public static Regex regex = new Regex();
    private static String handleError(int lineNumber, String code, List<String> result){
        if((result == null) && code.length() >0 && !regex.isEmptyLine(code)){
            return "Error on line "+ lineNumber +" It can not identify the token that starts with " + code;
        }
        return null;
    }
    private static String getError(List<String> errors){
        StringBuilder stringBuilder = new StringBuilder();
        if(errors.size()> 0)
            errors.forEach((error)-> stringBuilder.append(error).append("\n"));
        else
            stringBuilder.append("Lexical correct");
        return stringBuilder.toString();
    }


    public static Result scan(Scanner scanner) {// scan apeleaza detect pana are toate token-urile
        SymbolTable st = new SymbolTable();//constantele si variabilele
        List<String> pif = new ArrayList<>();// lista de tokens
        String lineOfCode = scanner.nextLine();
        List<String> errors = new ArrayList<>();
        String error;
        int lineNr = 1;
        List<String> result;
        while (true) {
            if (lineOfCode.length() == 0) {// if mai avem de citit
                if (scanner.hasNextLine()) {
                    lineOfCode = scanner.nextLine();
                    lineNr += 1;
                } else
                    break;
            }
            if (regex.isEmptyLine(lineOfCode)) {// linie goala
                lineOfCode = "";
                continue;
            }
            result = regex.detect(lineOfCode);// detect detects the type of token
            error = handleError(lineNr, lineOfCode, result);
            if (error != null) {
                errors.add(error);
                lineOfCode = "";
                continue;
            }
            lineOfCode = result.get(0);
            switch (result.get(2)) {
                case "separator", "keyword" -> {
                    pif.add(result.get(1));
                    pif.add("0");
                }
                //
                case "constantString", "constantChar", "constantInt" -> {
                    PositionHash pos = st.add(new AcceptedToken("Constant", result.get(1)));
                    pif.add("const");
                    pif.add(pos.toString());
                }
                case "identifier" -> {
                    PositionHash pos = st.add(new AcceptedToken("Identifier", result.get(1)));
                    pif.add("id");
                    pif.add(pos.toString());
                }
            }
        }
        return new Result(st, pif, getError(errors));
    }

}

