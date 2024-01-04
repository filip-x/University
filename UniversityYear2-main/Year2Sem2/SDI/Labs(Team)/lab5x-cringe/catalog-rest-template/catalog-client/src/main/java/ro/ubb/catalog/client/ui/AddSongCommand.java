package ro.ubb.catalog.client.ui;

import ro.ubb.catalog.web.DTOs.SongDto;

import java.util.Scanner;

public class AddSongCommand extends Command {

    /**
     * @param key         the id of the command (unique)
     * @param description what the command does
     */
    public AddSongCommand(String key, String description, String url) {
        super(key, description, url);
    }

    @Override
    public void execute() throws Exception {
        Scanner keyboard = new Scanner(System.in);
        System.out.print("Enter a song id: ");
        int id = keyboard.nextInt();
        System.out.print("Enter a song title: ");
        keyboard.nextLine();
        String title = keyboard.nextLine();
        System.out.print("Enter a duration: ");
        int duration = keyboard.nextInt();

        int artist_id;
        while (true) {
            System.out.println("Enter an artist id (enter -1 if no more artists): ");
            artist_id = keyboard.nextInt();
            if (artist_id == -1) {
                break;
            }

//            controller.addFeaturing(id, artist_id);
        }

        restTemplate.postForObject(
                url,
                new SongDto(id, title, duration),
                SongDto.class
        );
    }
}
