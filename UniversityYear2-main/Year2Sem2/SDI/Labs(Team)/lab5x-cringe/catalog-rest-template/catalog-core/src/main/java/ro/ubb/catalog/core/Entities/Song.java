package ro.ubb.catalog.core.Entities;

import lombok.*;

import javax.persistence.Entity;
import java.util.HashMap;

@Entity
@NoArgsConstructor
@Setter
@Getter
public class Song extends BaseEntity<Integer> {
    private String name;
    private int duration;

    public Song(int id, String name, int duration) {
        super(id);
        this.name = name;
        this.duration = duration;
    }

    @Override
    public HashMap<String, String> getAttributes() {
        HashMap<String, String> attributes = new HashMap<>();

        attributes.put("id", id.toString());
        attributes.put("name", name);
        attributes.put("duration", String.valueOf(duration));

        return attributes;
    }

    @Override
    public String toString() {
        return "Song{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", duration=" + duration +
                '}';
    }
}
