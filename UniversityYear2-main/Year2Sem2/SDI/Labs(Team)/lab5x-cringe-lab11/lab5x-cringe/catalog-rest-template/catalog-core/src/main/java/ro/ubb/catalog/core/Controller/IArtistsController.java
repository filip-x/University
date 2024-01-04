package ro.ubb.catalog.core.Controller;


import ro.ubb.catalog.core.Entities.Artist;

public interface IArtistsController {
    Artist addArtist(int id, String name) throws Exception;
    Artist updateArtist(int id, String name) throws Exception;
    void removeArtist(int id);
    Iterable<Artist> getAllArtists() throws Exception;
    Artist getArtist(int id);

    void giveInstrumentToArtist(Integer artistId, Integer instrumentId);
}
