package ro.ubb.catalog.web.DTOs;

import lombok.*;
import ro.ubb.catalog.core.Entities.SongFeaturing;

import java.util.UUID;

@NoArgsConstructor
//@AllArgsConstructor
@Data
@EqualsAndHashCode(callSuper = true)
@ToString(callSuper = true)
public class SongFeaturingDto extends BaseDto<UUID> {
    private Integer songId;
    private Integer artistId;

    public SongFeaturingDto(Integer songId, Integer artistId) {
        this.songId = songId;
        this.artistId = artistId;
    }

    public SongFeaturingDto(UUID featuringId, Integer songId, Integer artistId) {
        super(featuringId);
        this.songId = songId;
        this.artistId = artistId;
    }
}
