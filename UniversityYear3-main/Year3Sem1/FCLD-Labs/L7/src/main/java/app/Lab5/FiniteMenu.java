package app.Lab5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class FiniteMenu {
    public static void start() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Menu is running");
        FiniteAutomata finiteAutomata = null;
        boolean run = true;
        while (run){
            System.out.println("0. Exit\n1. Read a FA file\n2. Process a string with existing FA");
            String option  = reader.readLine();
            switch (option)
            {
                case "0":
                    run = false;
                    break;
                case "1":
                    System.out.println("Enter file name: ");
                    String file = reader.readLine();
                    finiteAutomata = FiniteFileConverter.read(file);
                    break;
                case "2":
                    if(finiteAutomata!=null)
                    {
                        System.out.println("Enter a string: ");
                        String s = reader.readLine();
                        System.out.println("Stirng match is: "+ finiteAutomata.check(s));
                    }
                    break;
                default:
                    break;
            }
        }
    }
}
