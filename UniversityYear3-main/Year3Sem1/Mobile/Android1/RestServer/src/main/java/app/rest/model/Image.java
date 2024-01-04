package app.rest.model;

import lombok.*;

import javax.persistence.*;


@Entity
@Getter
@Setter
@ToString
@Builder
@AllArgsConstructor
@NoArgsConstructor
public class Image {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "image_gen")
    @SequenceGenerator(name = "image_gen", sequenceName = "image_seq", allocationSize = 1)
    @Column(name = "id", nullable = false)
    private Long id;

    @Column(columnDefinition = "LONGTEXT")
    private String base64Image;
}
