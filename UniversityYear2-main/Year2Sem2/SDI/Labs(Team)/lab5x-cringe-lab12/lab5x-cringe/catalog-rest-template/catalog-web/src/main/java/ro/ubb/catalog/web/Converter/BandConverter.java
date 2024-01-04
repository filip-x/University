package ro.ubb.catalog.web.Converter;


import org.springframework.stereotype.Component;
import ro.ubb.catalog.core.Entities.Band;;
import ro.ubb.catalog.web.DTOs.BandDto;
@Component
public class BandConverter extends BaseConverter<Integer, Band, BandDto> {
    @Override
    public Band convertDtoToModel(BandDto dto) {
        var model = new Band();

        model.setId(dto.getId());
        model.setName(dto.getName());

        return model;
    }

    @Override
    public BandDto convertModelToDto(Band band) {
        var dto = new BandDto(band.getId(), band.getName());
        dto.setId(band.getId());
        return dto;
    }
}
