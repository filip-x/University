package app.rest.model;

import lombok.*;
import org.springframework.lang.Nullable;

import javax.persistence.*;

@Entity
@Getter
@Setter
@ToString
@Builder
@AllArgsConstructor
@NoArgsConstructor
public class Post {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "post_gen")
    @SequenceGenerator(name = "post_gen", sequenceName = "post_seq", allocationSize = 1)
    @Column(name = "id", nullable = false)
    private Long id;

    private String imageUrl;
    private String title;
    private String authorName;
    private String description;
    @Column(nullable = true)
    private Double latitude;
    @Column(nullable = true)
    private Double longitude;
}
