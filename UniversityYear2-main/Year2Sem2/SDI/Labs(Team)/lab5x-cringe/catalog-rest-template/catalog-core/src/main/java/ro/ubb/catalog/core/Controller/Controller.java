package ro.ubb.catalog.core.Controller;

import lombok.NoArgsConstructor;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.transaction.annotation.Transactional;
import ro.ubb.catalog.core.Entities.*;
import ro.ubb.catalog.core.Repository.*;

import java.util.Comparator;
import java.util.Optional;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

@NoArgsConstructor
public class Controller implements IController {
    public static final Logger logger = LoggerFactory.getLogger(Controller.class);

    @Autowired
    ISongsJpaRepository songsRepository;

    @Autowired
    IArtistsJpaRepository artistsRepository;

    @Autowired
    ISongFeaturingJpaRepository songFeaturesRepository;

    @Autowired
    IInstrumentJpaRepository instrumentRepository;

    @Autowired
    IBandJpaRepository bandRepository;


    public Song addSong(int id, String name, int duration) {
        Song songToAdd = new Song(id, name, duration);
        var result = songsRepository.save(songToAdd);

        logger.trace("Add Song");

        return result;
    }

    public Artist addArtist(int id, String name) {
        Artist artistToAdd = new Artist(id, name);
        var result = artistsRepository.save(artistToAdd);

        logger.trace("Add Artist");

        return result;
    }

    @Transactional
    public Song updateSong(int id, String name) {
        Song updateSong = songsRepository.findById(id).orElseThrow();
        updateSong.setName(name);
        return updateSong;
    }

    @Transactional
    public Artist updateArtist(int id, String name) {
        Artist updateArtist = artistsRepository.findById(id).orElseThrow();
        updateArtist.setName(name);

        logger.trace("Update Artist");

        return updateArtist;
    }

    public void removeSong(int id) {
        songsRepository.deleteById(id);
        logger.trace("Delete Song");
    }

    public void removeArtist(int id) {
        artistsRepository.deleteById(id);
        logger.trace("Removed artist");
    }

    public SongFeaturing addFeaturing(int songId, int artistId) {
        var featuring = new SongFeaturing(songId, artistId);
        songFeaturesRepository.save(featuring);
        return featuring;
    }

    public Iterable<Song> filterSongsDurationLessThan(int duration) throws Exception {
        return StreamSupport.stream(songsRepository.findAll().spliterator(), false)
                .filter(song -> song.getDuration() < duration)
                .collect(Collectors.toList());
    }

    public Iterable<Song> getAllSongs() {
        return songsRepository.findAll();
    }

    public Iterable<Artist> getAllArtists() {
        return artistsRepository.findAll();
    }

    private int getNumberOfFeatures(Song song) {
        try {
            return (int) StreamSupport.stream(songFeaturesRepository.findAll().spliterator(), false)
                    .filter(e -> e.getSongId() == song.getId())
                    .count();
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }
    }

    public Song getSongWithMostFeatures() {
        return StreamSupport.stream(songsRepository.findAll().spliterator(), false)
                .max(Comparator.comparingInt(this::getNumberOfFeatures))
                .get();
    }

    private int getNumberOfSongs(Artist artist) {
        try {
            return (int) StreamSupport.stream(songFeaturesRepository.findAll().spliterator(), false)
                    .filter(e -> e.getSongId() == artist.getId())
                    .count();
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }
    }

    public Artist getArtistWithMostSongs() {
        return StreamSupport.stream(artistsRepository.findAll().spliterator(), false)
                .max(Comparator.comparingInt(this::getNumberOfSongs))
                .get();
    }

    @Override
    public Band addBand(int id, String name) throws Exception {
        Band bandToAdd = new Band(id, name);
        var result = bandRepository.save(bandToAdd);

        logger.trace("Add Band");

        return result;
    }

    @Override
    public Band updateBand(int id, String name) throws Exception {
        Band updateBand = bandRepository.findById(id).orElseThrow();
        updateBand.setName(name);

        logger.trace("Update Band");

        return updateBand;
    }

    @Override
    public void removeBand(int id) {
        bandRepository.deleteById(id);
        logger.trace("Removed Band");

    }

    @Override
    public Iterable<Band> getAllBands() throws Exception {
        return bandRepository.findAll();
    }

    @Override
    public Instrument addInstrument(int id, String name) throws Exception {
        Instrument instrumentToAdd = new Instrument(id, name);
        var result = instrumentRepository.save(instrumentToAdd);
        logger.trace("Add Instrument");
        return result;
    }

    @Override
    public Instrument updateInstrument(int id, String name) throws Exception {
        Instrument updateInstrument = instrumentRepository.findById(id).orElseThrow();
        updateInstrument.setName(name);

        logger.trace("Update Instrument");

        return updateInstrument;
    }

    @Override
    public void removeInstrument(int id) {
        instrumentRepository.deleteById(id);
        logger.trace("Removed Instrument");

    }

    @Override
    public Iterable<Instrument> getAllInstruments() throws Exception {
        return instrumentRepository.findAll();
    }
}
