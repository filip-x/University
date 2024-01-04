package ro.ubb.catalog.core.Entities;

import javax.persistence.Entity;
import java.util.HashMap;

@Entity
public class Instrument extends BaseEntity<Integer>{
    private String name;

    public Instrument(){
        super(-1);
        name = "";
    }

    public Instrument(Integer id, String name) {
        super(id);
        this.name = name;
    }

    @Override
    public Integer getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public HashMap<String, String> getAttributes() {
        HashMap<String, String> attributes = new HashMap<>();

        attributes.put("id", id.toString());
        attributes.put("name", name);

        return attributes;
    }



    @Override
    public String toString() {
        return "Instrument{" +
                "id=" + id +
                ", name='" + name + '\'' +
                '}';
    }
}
