package ro.ubb.catalog.client.ui;

import java.util.*;
import org.springframework.stereotype.Component;

/**
 * Text menu (command line)
 */

@Component
public class TextMenu {
    private SortedMap<String, Command> commands;

    public TextMenu() {
        commands = new TreeMap<>();
    }

    /**
     * Adds a command
     *
     * @param c command to add
     */
    public TextMenu addCommand(Command c) {
        commands.put(c.getKey(), c);
        return this;
    }

    private void printMenu() {
        commands.values().forEach(e -> System.out.println(String.format("%4s : %s", e.getKey(), e.getDescription())));
    }

    /**
     * Prints the menu on the screen
     */
    public void show() {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            printMenu();
            System.out.printf("\nInput the option: ");
            String key = scanner.nextLine();

            Command com = commands.get(key);
            if (com == null) {
                System.out.println("Invalid Option");
                continue;
            }
            try {
                com.execute();
            } catch (Exception e) {
                e.printStackTrace();;
            }
        }
    }
}