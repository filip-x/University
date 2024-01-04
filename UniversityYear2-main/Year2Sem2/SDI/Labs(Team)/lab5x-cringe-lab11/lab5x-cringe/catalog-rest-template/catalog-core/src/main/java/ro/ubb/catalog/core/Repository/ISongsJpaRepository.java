package ro.ubb.catalog.core.Repository;

import org.springframework.data.jpa.repository.JpaRepository;
import ro.ubb.catalog.core.Entities.Song;

public interface ISongsJpaRepository extends JpaRepository<Song, Integer> {
}
