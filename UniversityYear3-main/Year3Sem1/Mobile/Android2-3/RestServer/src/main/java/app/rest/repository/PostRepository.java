package app.rest.repository;

import app.rest.model.Post;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.rest.core.annotation.RestResource;
import org.springframework.hateoas.server.ExposesResourceFor;
import org.springframework.stereotype.Repository;
import org.springframework.web.bind.annotation.CrossOrigin;

import java.util.List;
import java.util.Optional;

@CrossOrigin(origins = "*")
@Repository
public interface PostRepository extends JpaRepository<Post, Long> {
    Optional<Post> findById(Long id);
    Post save(Post post);
    void deleteById(Long id);
    List<Post> findAll();
    List<Post> findAllByAuthorName(String authorName);
    List<Post> findAllByAuthorName(String authorName, Pageable pageable);
    List<Post> findAllByTitleContainsAndAuthorName(String term, String authorName);
}
