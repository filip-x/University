package ro.ubb.catalog.core.Controller;


import ro.ubb.catalog.core.Entities.Song;

public interface ISongsController {
    Song addSong(int id, String name, int duration) throws Exception;
    Song updateSong(int id, String name) throws Exception;
    void removeSong(int id);
    Iterable<Song> getAllSongs() throws Exception;

}
