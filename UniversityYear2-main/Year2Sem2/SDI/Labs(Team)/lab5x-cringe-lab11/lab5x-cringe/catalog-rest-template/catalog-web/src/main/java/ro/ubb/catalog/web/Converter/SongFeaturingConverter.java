package ro.ubb.catalog.web.Converter;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import ro.ubb.catalog.core.Entities.SongFeaturing;
import ro.ubb.catalog.core.Repository.IArtistsJpaRepository;
import ro.ubb.catalog.core.Repository.ISongsJpaRepository;
import ro.ubb.catalog.web.DTOs.SongFeaturingDto;

import java.util.UUID;

@Component
public class SongFeaturingConverter extends BaseConverter<UUID, SongFeaturing, SongFeaturingDto> {
    @Autowired
    private IArtistsJpaRepository artistsJpaRepository;

    @Autowired
    private ISongsJpaRepository songsJpaRepository;

    @Override
    public SongFeaturing convertDtoToModel(SongFeaturingDto dto) {
        var model = new SongFeaturing();

        model.setArtist(artistsJpaRepository.getOne(dto.getArtistId()));
        model.setSong(songsJpaRepository.getOne(dto.getSongId()));

        return model;
    }

    @Override
    public SongFeaturingDto convertModelToDto(SongFeaturing sf) {
        var dto = new SongFeaturingDto(sf.getSong().getId(), sf.getArtist().getId());
        return dto;
    }
}
