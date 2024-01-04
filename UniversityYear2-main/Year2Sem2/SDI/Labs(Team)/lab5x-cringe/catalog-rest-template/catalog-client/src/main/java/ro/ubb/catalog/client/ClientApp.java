package ro.ubb.catalog.client;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import ro.ubb.catalog.client.ui.*;

/**
 * Created by radu.
 */

public class ClientApp {
    public static void main(String[] args) {

        AnnotationConfigApplicationContext context = new AnnotationConfigApplicationContext("ro.ubb.catalog.client.config");
        var console = context.getBean(TextMenu.class);
        String baseUrl = "http://localhost:8080/api";
        console
                .addCommand(new AddSongCommand("01", "Add a song", baseUrl + "/songs"))
                .addCommand(new AddArtistCommand("02", "Add an artist", baseUrl + "/artists"))
                .addCommand(new ListAllSongsCommand("03", "Lists all songs", baseUrl + "/songs"))
                .addCommand(new ListAllArtistsCommand("04", "List all artists", baseUrl + "/artists"))
                .addCommand(new RemoveArtistCommand("05", "Remove an artist", baseUrl + "/artists"))
                .addCommand(new RemoveSongCommand("06", "Remove a song", baseUrl + "/songs"))
                .addCommand(new UpdateSongCommand("07", "Update a song", baseUrl + "/songs"))
                .addCommand(new UpdateArtistCommand("08", "Update an artist", baseUrl + "/artists"))
                .addCommand(new AddSongFeaturingCommand("09", "Add featuring", baseUrl + "/featurings"))
                //.addCommand(new DisplaySongWithMostFeaturesCommand("10", "Display the song with the most features"))
                //.addCommand(new DisplayArtistWithMostSongsCommand("11", "Display the artist with the most songs"))
                .addCommand(new ExitCommand("12", "Exit"))
                .show();
        System.out.println("bye ");
    }
}
