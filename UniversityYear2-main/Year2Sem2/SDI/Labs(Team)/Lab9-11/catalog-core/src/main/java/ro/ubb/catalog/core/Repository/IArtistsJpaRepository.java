package ro.ubb.catalog.core.Repository;

import org.springframework.data.jpa.repository.JpaRepository;
import ro.ubb.catalog.core.Entities.Artist;

public interface IArtistsJpaRepository extends JpaRepository<Artist,Integer> {
}
