package ro.ubb.catalog.client.ui;

import ro.ubb.catalog.web.DTOs.SongDto;

import java.util.Scanner;

public class RemoveSongCommand extends Command {
    public RemoveSongCommand(String key, String description, String url) {
        super(key, description, url);
    }

    @Override
    public void execute() throws Exception {

        Scanner keyboard = new Scanner(System.in);
        System.out.print("Enter a song id to remove: ");
        int id = keyboard.nextInt();
        restTemplate.delete(url + "/{id}", id);
    }
}
