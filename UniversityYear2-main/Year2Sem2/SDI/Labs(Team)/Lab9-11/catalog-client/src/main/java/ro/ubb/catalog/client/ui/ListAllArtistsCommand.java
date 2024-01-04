package ro.ubb.catalog.client.ui;

import ro.ubb.catalog.web.DTOs.SetDto;

public class ListAllArtistsCommand extends Command {
    public ListAllArtistsCommand(String key, String description, String url) {
        super(key, description, url);
    }

    @Override
    public void execute() throws Exception {
        var all_artists = restTemplate.getForObject(url, SetDto.class);
        System.out.println(all_artists);
    }
}