package ro.ubb.catalog.client.ui;

import ro.ubb.catalog.web.DTOs.ArtistDto;
import ro.ubb.catalog.web.DTOs.SongDto;

import java.util.Scanner;

public class AddArtistCommand extends Command {
    public AddArtistCommand(String key, String description, String url) {
        super(key, description, url);
    }

    @Override
    public void execute() throws Exception {
        Scanner keyboard = new Scanner(System.in);
        System.out.print("Enter an artist id: ");
        int id = keyboard.nextInt();
        System.out.print("Enter a artist name: ");
        keyboard.nextLine();
        String name = keyboard.nextLine();
        int song_id;
        while (true) {
            System.out.println("Enter an song id (enter -1 if no more artists): ");
            song_id = keyboard.nextInt();
            if (song_id == -1) {
                break;
            }

            //controller.addFeaturing(song_id, id);
        }

        restTemplate.postForObject(
                url,
                new ArtistDto(id, name),
                ArtistDto.class
        );
    }
}