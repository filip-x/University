package ro.ubb.catalog.web.Converter;

import org.springframework.stereotype.Component;
import ro.ubb.catalog.core.Entities.Instrument;
import ro.ubb.catalog.web.DTOs.InstrumentDto;

@Component
public class InstrumentConverter extends BaseConverter<Integer, Instrument, InstrumentDto> {

    @Override
    public Instrument convertDtoToModel(InstrumentDto dto) {
        var model = new Instrument();
        model.setId(dto.getId());
        model.setName(dto.getName());
        return  model;
    }

    @Override
    public InstrumentDto convertModelToDto(Instrument instrument) {
        var dto = new InstrumentDto(instrument.getId(),instrument.getName());
        dto.setId(instrument.getId());
        return dto;
    }
}
