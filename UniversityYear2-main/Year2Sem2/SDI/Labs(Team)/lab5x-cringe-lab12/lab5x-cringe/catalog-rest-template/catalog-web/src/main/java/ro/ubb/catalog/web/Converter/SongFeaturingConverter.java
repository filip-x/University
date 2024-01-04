package ro.ubb.catalog.web.Converter;

import org.springframework.stereotype.Component;
import ro.ubb.catalog.core.Entities.SongFeaturing;
import ro.ubb.catalog.web.DTOs.SongFeaturingDto;

import java.util.UUID;

@Component
public class SongFeaturingConverter extends BaseConverter<UUID, SongFeaturing, SongFeaturingDto> {
    @Override
    public SongFeaturing convertDtoToModel(SongFeaturingDto dto) {
        var model = new SongFeaturing();

        model.setId(dto.getId());
        model.setArtistId(dto.getArtistId());
        model.setSongId(dto.getSongId());

        return model;
    }

    @Override
    public SongFeaturingDto convertModelToDto(SongFeaturing sf) {
        var dto = new SongFeaturingDto(sf.getFeaturingId(), sf.getSongId(), sf.getArtistId());
        return dto;
    }
}