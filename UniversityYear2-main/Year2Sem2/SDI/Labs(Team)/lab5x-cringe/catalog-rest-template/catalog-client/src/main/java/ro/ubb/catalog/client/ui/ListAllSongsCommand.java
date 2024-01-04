package ro.ubb.catalog.client.ui;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.web.client.RestTemplate;
import ro.ubb.catalog.web.DTOs.SetDto;

public class ListAllSongsCommand extends Command {

    public ListAllSongsCommand(String key, String descr, String url) {
        super(key, descr, url);
    }

    @Override
    public void execute() throws Exception {
        var all_songs = restTemplate.getForObject(url, SetDto.class);
        //all_songs.forEach(System.out::println);
        System.out.println(all_songs);
    }
}
