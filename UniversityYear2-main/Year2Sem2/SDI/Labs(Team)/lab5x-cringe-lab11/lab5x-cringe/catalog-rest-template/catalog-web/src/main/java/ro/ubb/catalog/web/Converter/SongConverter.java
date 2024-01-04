package ro.ubb.catalog.web.Converter;

import org.springframework.stereotype.Component;
import ro.ubb.catalog.core.Entities.Song;
import ro.ubb.catalog.web.DTOs.BaseDto;
import ro.ubb.catalog.web.DTOs.SongDto;

@Component
public class SongConverter extends BaseConverter<Integer, Song, SongDto> {
    @Override
    public Song convertDtoToModel(SongDto dto) {
        var model = new Song();

        model.setId(dto.getId());
        model.setName(dto.getName());
        model.setDuration(dto.getDuration());

        return model;
    }

    @Override
    public SongDto convertModelToDto(Song student) {
        var dto = new SongDto(student.getId(), student.getName(), student.getDuration());
        dto.setId(student.getId());
        return dto;
    }
}
