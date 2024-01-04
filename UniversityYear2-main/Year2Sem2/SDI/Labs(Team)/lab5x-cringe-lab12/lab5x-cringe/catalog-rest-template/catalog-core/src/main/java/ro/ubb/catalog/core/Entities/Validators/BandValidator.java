package ro.ubb.catalog.core.Entities.Validators;

import ro.ubb.catalog.core.Entities.Band;
import ro.ubb.catalog.core.Exceptions.ValidatorException;

import java.util.Optional;

public class BandValidator implements Validator<Band>{
    @Override
    public void validate(Band entity) throws ValidatorException {
        //Stream.of(new AbstractMap.SimpleEntry<>(entity.getName().isEmpty(), "Instrument name must not be empty"),
//                new AbstractMap.SimpleEntry<>(entity.getId() <= 0, "Instrument breed must not be empty"))
//                .filter(AbstractMap.SimpleEntry::getKey)
//                .forEach((b) -> {
//                    throw new ValidatorException(b.getValue());
//                });

        Optional.of(entity.getId())
                .filter(e -> e <= 0)
                .ifPresent(e -> {
                    throw new ValidatorException("Negative artist id");
                });

        Optional.of(entity.getName())
                .filter(e -> e == null || e.isEmpty())
                .ifPresent(e -> {
                    throw new ValidatorException("Empty string");
                });
    }
}
