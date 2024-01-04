package app.rest.repository;

import app.rest.model.Book;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.rest.core.annotation.RestResource;
import org.springframework.web.bind.annotation.CrossOrigin;

import java.util.List;
import java.util.Optional;

@CrossOrigin(origins = "*")
@RestResource
public interface BookRepository extends JpaRepository<Book, Long> {
    Optional<Book> findById(Long id);
    Book save(Book post);
    void deleteById(Long id);
    List<Book> findAll();
}