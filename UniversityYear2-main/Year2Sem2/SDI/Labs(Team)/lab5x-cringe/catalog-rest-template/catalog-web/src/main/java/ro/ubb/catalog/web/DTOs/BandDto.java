package ro.ubb.catalog.web.DTOs;

import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.NoArgsConstructor;
import lombok.ToString;

@NoArgsConstructor
@Data
@EqualsAndHashCode(callSuper = true)
@ToString(callSuper = true)

public class BandDto extends BaseDto<Integer> {
    private String name;

    public BandDto(int id, String name) {
        super(id);
        this.name = name;
    }
}
