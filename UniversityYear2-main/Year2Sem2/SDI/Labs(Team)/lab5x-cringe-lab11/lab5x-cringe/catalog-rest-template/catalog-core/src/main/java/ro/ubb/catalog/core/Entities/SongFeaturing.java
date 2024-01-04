package ro.ubb.catalog.core.Entities;

import lombok.*;

import javax.persistence.*;
import java.io.Serializable;
import java.util.HashMap;
import java.util.UUID;

@Entity
@Table(name = "song_featuring")
@IdClass(SongFeaturingPK.class)
@NoArgsConstructor
@AllArgsConstructor
@Getter
@Setter
@Builder
public class SongFeaturing implements Serializable {
    @Id
    @ManyToOne(optional = false, fetch = FetchType.EAGER)
    @JoinColumn(name = "song_id", referencedColumnName = "id")
    private Song song;

    @Id
    @ManyToOne(optional = false, fetch = FetchType.EAGER)
    @JoinColumn(name = "artist_id", referencedColumnName = "id")
    private Artist artist;
}
