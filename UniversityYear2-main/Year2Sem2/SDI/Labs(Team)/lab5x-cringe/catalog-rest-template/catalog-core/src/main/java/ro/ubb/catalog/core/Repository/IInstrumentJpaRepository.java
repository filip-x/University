package ro.ubb.catalog.core.Repository;

import org.springframework.data.jpa.repository.JpaRepository;
import ro.ubb.catalog.core.Entities.Instrument;


public interface IInstrumentJpaRepository extends JpaRepository<Instrument,Integer> {
}
