package ro.ubb.catalog.core.Entities.Validators;


import ro.ubb.catalog.core.Exceptions.ValidatorException;

public interface Validator<T> {
    void validate(T entity) throws ValidatorException;
}
