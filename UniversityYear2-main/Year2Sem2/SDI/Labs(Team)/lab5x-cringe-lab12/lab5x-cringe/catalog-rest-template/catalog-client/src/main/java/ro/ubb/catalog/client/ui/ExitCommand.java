package ro.ubb.catalog.client.ui;

import lombok.AllArgsConstructor;

/**
 * Command that exits the program
 */

public class ExitCommand extends Command {

    public ExitCommand(String key, String descr) {
        super(key, descr, null);
    }

    /**
     * Executes exit
     */
    @Override
    public void execute() {
        System.exit(0); }
}