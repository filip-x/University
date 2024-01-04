package ro.ubb.catalog.core.Entities;

import lombok.*;

import javax.persistence.*;
import java.io.Serializable;


@NoArgsConstructor
@AllArgsConstructor
@Getter
@Setter
@EqualsAndHashCode()
public class SongFeaturingPK implements Serializable {
    private Song song;
    private Artist artist;
}
