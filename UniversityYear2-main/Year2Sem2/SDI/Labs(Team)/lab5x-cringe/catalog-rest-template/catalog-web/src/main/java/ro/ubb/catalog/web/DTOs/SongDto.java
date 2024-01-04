package ro.ubb.catalog.web.DTOs;

import lombok.*;

@NoArgsConstructor
//@AllArgsConstructor
@Data
@EqualsAndHashCode(callSuper = true)
@ToString(callSuper = true)
public class SongDto extends BaseDto<Integer> {
    private String name;
    private int duration;

    public SongDto(int id, String title, int duration) {
        super(id);
        this.name = title;
        this.duration = duration;
    }
}
