package ro.ubb.catalog.core.Entities.Validators;


import ro.ubb.catalog.core.Entities.Song;
import ro.ubb.catalog.core.Exceptions.ValidatorException;

import java.util.Optional;

public class SongValidator implements Validator<Song> {
    @Override
    public void validate(Song entity) throws ValidatorException {
        Optional.of(entity.getId())
                .filter(e -> e <= 0)
                .ifPresent(e -> {
                    throw new ValidatorException("Negative song ID");
                });

        Optional.of(entity.getName())
                .filter(e -> e == null || e.isEmpty())
                .ifPresent(e -> {
                    throw new ValidatorException("Empty song name");
                });

        Optional.of(entity.getDuration())
                .filter(e -> e <= 0)
                .ifPresent(e -> {
                    throw new ValidatorException("Invalid duration");
                });
    }
}
