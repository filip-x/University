package Controller;

import Model.Chestionar;
import Model.Intrebare;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

public class Service {


    BufferedReader readerFromFile;
    List<Intrebare> list;
    Chestionar chestionar;
    int id = 0;
    int nrChestionar = 0;


    // here we get all 40 questions out of the file and we put them into our list;
    public void readFromFile() {
        try {
            readerFromFile = new BufferedReader(new FileReader("date.in"));
            String line = readerFromFile.readLine();
            String r1 = readerFromFile.readLine();
            String r2 = readerFromFile.readLine();
            String r3 = readerFromFile.readLine();
            String r4 = readerFromFile.readLine();
            List<String> rasp = new LinkedList<>();
            List<String> raspCorect = new LinkedList<>();
            if (r1.substring(0, 1).equals("*")) {
                raspCorect.add(r1);
            }
            if (r2.substring(0, 1).equals("*")) {
                raspCorect.add(r2);
            }
            if (r3.substring(0, 1).equals("*")) {
                raspCorect.add(r3);
            }
            if (r1.substring(0, 1).equals("*")) {
                raspCorect.add(r4);
            }
            rasp.add(r1);
            rasp.add(r2);
            rasp.add(r3);
            rasp.add(r4);
            while (line != null) {
                Intrebare intreb = new Intrebare(line, rasp, raspCorect);
                this.list.add(intreb);
                line = readerFromFile.readLine();
                r1 = readerFromFile.readLine();
                r2 = readerFromFile.readLine();
                r3 = readerFromFile.readLine();
                r4 = readerFromFile.readLine();
                if (r1.substring(0, 1).equals("*")) {
                    raspCorect.add(r1);
                }
                if (r2.substring(0, 1).equals("*")) {
                    raspCorect.add(r2);
                }
                if (r3.substring(0, 1).equals("*")) {
                    raspCorect.add(r3);
                }
                if (r1.substring(0, 1).equals("*")) {
                    raspCorect.add(r4);
                }
                rasp.add(r1);
                rasp.add(r2);
                rasp.add(r3);
                rasp.add(r4);
            }
            readerFromFile.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public List<Integer> getRandomQuestions() {
        List<Integer> theNumbers = new LinkedList<>();
        int number;
        int index = 26;

        Random rand = new Random();

        while (index != 0) {
            number = rand.nextInt(39);

            while (true) {
                if (theNumbers.contains(number))
                    number = rand.nextInt(39);
                else {
                    theNumbers.add(number);
                    break;
                }
            }
            index--;
        }
        return theNumbers;
    }

    public void createChestionar() {
        Random rand = new Random();
        this.id = rand.nextInt(1000);
        this.nrChestionar++;

        int n = 0;
        List<Integer> numereRandom = getRandomQuestions();
        List<Intrebare> finalList = new LinkedList<>();
        for (Integer i : numereRandom) {
            finalList.add(this.list.get(i));

            chestionar = new Chestionar(id, nrChestionar, 0, 0, finalList);
        }
    }
}