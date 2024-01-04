package ro.ubb.catalog.client.ui;

import ro.ubb.catalog.web.DTOs.SongDto;
import ro.ubb.catalog.web.DTOs.SongFeaturingDto;

import java.util.Scanner;
import java.util.UUID;

public class AddSongFeaturingCommand extends Command {
    public AddSongFeaturingCommand(String key, String description, String url) {
        super(key, description, url);
    }

    @Override
    public void execute() throws Exception {
        Scanner keyboard = new Scanner(System.in);
        System.out.print("Enter a song ID: ");
        int songId = keyboard.nextInt();
        System.out.print("Enter an artist ID: ");
        int artistId = keyboard.nextInt();
        
        restTemplate.postForObject(
                url,
                new SongFeaturingDto(songId, artistId),
                SongFeaturingDto.class
        );
    }
}
