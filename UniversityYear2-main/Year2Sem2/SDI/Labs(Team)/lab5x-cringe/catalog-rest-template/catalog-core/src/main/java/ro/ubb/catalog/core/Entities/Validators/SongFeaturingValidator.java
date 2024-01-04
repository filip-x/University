package ro.ubb.catalog.core.Entities.Validators;


import ro.ubb.catalog.core.Entities.SongFeaturing;
import ro.ubb.catalog.core.Exceptions.ValidatorException;
import ro.ubb.catalog.core.Repository.IArtistsJpaRepository;
import ro.ubb.catalog.core.Repository.ISongsJpaRepository;

import java.util.Optional;

public class SongFeaturingValidator implements Validator<SongFeaturing> {
    private final ISongsJpaRepository songs;
    private final IArtistsJpaRepository artists;

    public SongFeaturingValidator(ISongsJpaRepository songsRepository, IArtistsJpaRepository artistsRepository) {
        this.songs = songsRepository;
        this.artists = artistsRepository;
    }

    @Override
    public void validate(SongFeaturing entity) throws ValidatorException {
        Optional.of(entity.getId())
                .filter(e -> e == null)
                .ifPresent(e -> {
                    throw new ValidatorException("Invalid ID");
                });

        Optional.of(entity.getSongId())
                .filter(e -> e <= 0)
                .ifPresent(e -> {
                    throw new ValidatorException("Invalid song ID");
                });

        Optional.of(entity.getSongId())
                .filter(e -> songs.findById(e).isEmpty())
                .ifPresent(e -> {
                    throw new ValidatorException("Song id not in repository.");
                });

        Optional.of(entity.getArtistId())
                .filter(e -> e <= 0)
                .ifPresent(e -> {
                    throw new ValidatorException("Invalid artist ID");
                });

        Optional.of(entity.getArtistId())
                .filter(e -> artists.findById(e).isEmpty())
                .ifPresent(e -> {
                    throw new ValidatorException("Artist id not in repository.");
                });
    }
}
