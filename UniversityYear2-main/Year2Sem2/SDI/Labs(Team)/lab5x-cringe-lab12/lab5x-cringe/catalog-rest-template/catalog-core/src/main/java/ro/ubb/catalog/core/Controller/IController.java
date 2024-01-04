package ro.ubb.catalog.core.Controller;


import ro.ubb.catalog.core.Entities.Artist;
import ro.ubb.catalog.core.Entities.Song;

public interface IController extends ISongsController, IArtistsController, IFeaturingController,IInstrumentsController,IBandController {
    Iterable<Song> filterSongsDurationLessThan(int duration) throws Exception;

    Song getSongWithMostFeatures() throws Exception;

    Artist getArtistWithMostSongs() throws Exception;
}