package ro.ubb.catalog.web.Converter;

import ro.ubb.catalog.core.Entities.BaseEntity;
import ro.ubb.catalog.web.DTOs.BaseDto;

import java.io.Serializable;
import java.util.Collection;
import java.util.Set;
import java.util.stream.Collectors;

public abstract class BaseConverter<ID extends Serializable, Model, Dto extends BaseDto<ID>>
    implements IConverter<ID, Model, Dto> {
    public Set<Dto> convertModelsToDtos(Collection<Model> models) {
        return models.stream()
                .map(this::convertModelToDto)
                .collect(Collectors.toSet());
    }
}
