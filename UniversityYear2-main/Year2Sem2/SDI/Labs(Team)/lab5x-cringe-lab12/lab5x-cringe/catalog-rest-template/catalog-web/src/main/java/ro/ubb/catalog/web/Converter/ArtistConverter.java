package ro.ubb.catalog.web.Converter;

import org.springframework.stereotype.Component;
import ro.ubb.catalog.core.Entities.Artist;
import ro.ubb.catalog.web.DTOs.ArtistDto;

@Component
public class ArtistConverter extends BaseConverter<Integer, Artist, ArtistDto> {
    @Override
    public Artist convertDtoToModel(ArtistDto dto) {
        var model = new Artist();

        model.setId(dto.getId());
        model.setName(dto.getName());

        return model;
    }

    @Override
    public ArtistDto convertModelToDto(Artist artist) {
        var dto = new ArtistDto(artist.getId(), artist.getName());
        dto.setId(artist.getId());
        return dto;
    }
}
