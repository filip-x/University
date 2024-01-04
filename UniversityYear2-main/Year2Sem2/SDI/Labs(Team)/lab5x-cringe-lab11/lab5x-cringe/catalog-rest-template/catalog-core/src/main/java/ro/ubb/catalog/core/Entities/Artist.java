package ro.ubb.catalog.core.Entities;

import lombok.*;

import javax.persistence.*;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

@Entity
@NoArgsConstructor
@AllArgsConstructor
@Data
@EqualsAndHashCode(callSuper = true, exclude = {"band", "instrument", "songs"})
@ToString(callSuper = true, exclude = {"band", "instrument", "songs"})
@Builder
public class Artist extends BaseEntity<Integer> {
    private String name;

    @JoinColumn(name = "band_id", referencedColumnName = "id")
    @ManyToOne(fetch = FetchType.EAGER)
    private Band band;

    @JoinColumn(name = "instrument_id", referencedColumnName = "id")
    @OneToOne(cascade = CascadeType.ALL, fetch = FetchType.EAGER)
    private Instrument instrument;

    @OneToMany(mappedBy = "artist", cascade = CascadeType.ALL, fetch = FetchType.EAGER, orphanRemoval = true)
    final private Set<SongFeaturing> songs = new HashSet<>();

    public Band getBand() {
        return band;
    }

    public void setBand(Band band) {
        this.band = band;
    }

    public Instrument getInstrument() {
        return instrument;
    }

    public void setInstrument(Instrument instrument) {
        this.instrument = instrument;
    }

    public Set<SongFeaturing> getSongs() {
        return songs;
    }
}
