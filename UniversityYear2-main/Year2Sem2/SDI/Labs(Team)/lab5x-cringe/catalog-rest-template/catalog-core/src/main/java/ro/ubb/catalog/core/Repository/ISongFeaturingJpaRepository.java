package ro.ubb.catalog.core.Repository;

import org.springframework.data.jpa.repository.JpaRepository;
import ro.ubb.catalog.core.Entities.SongFeaturing;

import java.util.UUID;

public interface ISongFeaturingJpaRepository extends JpaRepository<SongFeaturing, UUID> {
}
