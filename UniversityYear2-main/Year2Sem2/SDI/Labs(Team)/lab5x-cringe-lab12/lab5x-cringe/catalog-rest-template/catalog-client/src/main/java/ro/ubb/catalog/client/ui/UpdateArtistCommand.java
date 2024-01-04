package ro.ubb.catalog.client.ui;

import ro.ubb.catalog.web.DTOs.ArtistDto;
import ro.ubb.catalog.web.DTOs.SongDto;

import java.util.Scanner;

public class UpdateArtistCommand extends Command {
    public UpdateArtistCommand(String key, String description, String url) {
        super(key, description, url);
    }

    @Override
    public void execute() throws Exception {
        Scanner keyboard = new Scanner(System.in);
        System.out.print("Enter a artist id to update: ");
        int id = keyboard.nextInt();
        System.out.print("Update artist name: ");
        keyboard.nextLine();
        String name = keyboard.nextLine();

        restTemplate.put(url + "/{id}", new ArtistDto(id, name), id);
    }
}
