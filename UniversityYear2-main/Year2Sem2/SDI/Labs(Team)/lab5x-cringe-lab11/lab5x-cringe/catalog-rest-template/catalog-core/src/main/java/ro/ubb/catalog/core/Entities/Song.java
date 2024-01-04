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
@EqualsAndHashCode(callSuper = true, exclude = {"songs"})
@ToString(callSuper = true, exclude = {"songs"})
@Builder
public class Song extends BaseEntity<Integer> {
    private String name;
    private int duration;

    @OneToMany(mappedBy = "song", cascade = CascadeType.ALL, fetch = FetchType.EAGER, orphanRemoval = true)
    final private Set<SongFeaturing> songs = new HashSet<>();

}
