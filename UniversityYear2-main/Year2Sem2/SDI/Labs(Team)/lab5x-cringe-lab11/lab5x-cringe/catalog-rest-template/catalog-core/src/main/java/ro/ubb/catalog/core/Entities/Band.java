package ro.ubb.catalog.core.Entities;

import lombok.*;

import javax.persistence.CascadeType;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.OneToMany;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

@Entity
@NoArgsConstructor
@AllArgsConstructor
@Data
@EqualsAndHashCode(callSuper = true, exclude = {"artists"})
@ToString(callSuper = true, exclude = {"artists"})
@Builder
public class Band extends BaseEntity<Integer>{
    private String name;

    @OneToMany(mappedBy = "band", cascade = CascadeType.ALL, fetch = FetchType.EAGER)
    final private Set<Artist> artists = new HashSet<>();

    public Set<Artist> getArtists() {
        return artists;
    }
}
