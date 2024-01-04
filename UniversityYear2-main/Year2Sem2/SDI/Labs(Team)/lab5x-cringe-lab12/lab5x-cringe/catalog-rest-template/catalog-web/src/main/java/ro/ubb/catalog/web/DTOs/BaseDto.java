package ro.ubb.catalog.web.DTOs;

import lombok.*;

import java.io.Serializable;

@NoArgsConstructor
@AllArgsConstructor
@Getter
@Setter
@ToString
public class BaseDto<T> implements Serializable {
    private T id;
}
