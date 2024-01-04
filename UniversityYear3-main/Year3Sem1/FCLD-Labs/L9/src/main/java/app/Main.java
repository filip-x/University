package app;

import app.Lab5.FiniteMenu;
import app.Lab6.Grammer;
import app.Lab6.GrammerFileConverter;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {

        //GRAMMER CHECK
        grammerCheck();
        //FNITE AUTOMATA
        FiniteMenu.start();
        File file = new File("input.in");
        Scanner scanner = new Scanner(file);
        Result result  = app.LexicalScanner.scan(scanner);
        scanner.close();
        FileWriter fileWrite  = new FileWriter("output.out");
        fileWrite.write("Pif:\n");
        for(int i = 0; i < result.getPif().size(); i+=2) {
            fileWrite.write("(" + result.getPif().get(i) + ", " + result.getPif().get(i+1) + ")\n");
        }
            fileWrite.write("\nSt:\n");
        List<List<AcceptedToken>> storge = result.st.getStorageOfTokens();
        for(int i =0;i<storge.size();i++)
        {
            if(storge.get(i) == null)
                continue;
            for(int j=0;j<storge.get(i).size();j++)
            {
                if(storge.get(i).get(j)!= null)
                {
                    AcceptedToken token = storge.get(i).get(j);
                    fileWrite.write("("+i+ ", "+j+") =>"+token.getValueOfDataType() + "\n");
                }
            }
        }
        fileWrite.write("Erros detected: \n"+ result.getErrorMessage());
        fileWrite.close();
    }

    public static void grammerCheck() throws FileNotFoundException {
        Grammer grammar = GrammerFileConverter.read("g2.txt");
        System.out.println(grammar);
        System.out.println("Is CFG: "+ grammar.isCFG());
    }

}
