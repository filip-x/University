package ro.ubb.catalog.client.ui;

import ro.ubb.catalog.web.DTOs.SongDto;

import java.util.Scanner;

public class UpdateSongCommand extends Command {
    public UpdateSongCommand(String key, String description, String url) {
        super(key, description, url);
    }

    @Override
    public void execute() throws Exception {

        Scanner keyboard = new Scanner(System.in);
        System.out.print("Enter a song id to update: ");
        int id = keyboard.nextInt();
        System.out.print("Update song name: ");
        keyboard.nextLine();
        String title = keyboard.nextLine();
        System.out.print("Update song duration: ");
        int duration = keyboard.nextInt();
        restTemplate.put(url + "/{id}", new SongDto(id, title, duration), id);
    }
}

