package ro.ubb.catalog.web.DTOs;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.Set;

@NoArgsConstructor
@AllArgsConstructor
@Data
public class SetDto<ID, T extends BaseDto<ID>> {
    private Set<T> set;
}
