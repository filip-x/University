package ro.ubb.catalog.core.Entities;

import lombok.*;

import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.JoinColumn;
import javax.persistence.OneToOne;
import java.util.HashMap;

@Entity
@NoArgsConstructor
@AllArgsConstructor
@Data
@EqualsAndHashCode(callSuper = true, exclude = {"artist"})
@ToString(callSuper = true, exclude = {"artist"})
@Builder
public class Instrument extends BaseEntity<Integer>{
    private String name;

    @OneToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "artist_id", referencedColumnName = "id")
    private Artist artist;

    public Artist getArtist() {
        return artist;
    }

    public void setArtist(Artist artist) {
        this.artist = artist;
    }
}
