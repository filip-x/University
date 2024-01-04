package ro.ubb.catalog.web.Converter;

import ro.ubb.catalog.core.Entities.BaseEntity;
import ro.ubb.catalog.web.DTOs.BaseDto;

import java.io.Serializable;

public interface IConverter<ID extends Serializable, Model extends BaseEntity<ID>, Dto extends BaseDto<ID>> {
    Model convertDtoToModel(Dto dto);

    Dto convertModelToDto(Model model);
}
