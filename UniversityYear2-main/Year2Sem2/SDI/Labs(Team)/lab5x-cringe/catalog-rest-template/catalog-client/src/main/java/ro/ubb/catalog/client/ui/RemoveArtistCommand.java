package ro.ubb.catalog.client.ui;

import java.util.Scanner;

public class RemoveArtistCommand extends Command {
    public RemoveArtistCommand(String key, String description, String url) {
        super(key, description, url);
    }

    @Override
    public void execute() throws Exception {
        Scanner keyboard = new Scanner(System.in);
        System.out.print("Enter a id to remove: ");
        int id = keyboard.nextInt();
        restTemplate.delete(url + "/{id}", id);
    }
}