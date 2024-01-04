package ro.ubb.catalog.core.Entities;

import javax.persistence.Id;
import javax.persistence.MappedSuperclass;
import java.io.Serializable;
import java.util.HashMap;

@MappedSuperclass
public class BaseEntity<ID extends Serializable> implements Serializable {
    @Id
    protected ID id;

    protected BaseEntity(ID id) {
        this.id = id;
    }

    public ID getId() {
        return id;
    }

    public void setId(ID id) {
        this.id = id;
    }

    public BaseEntity(){
        id = null;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null) return false;
        if (o == this) return true;
        if (!(o instanceof BaseEntity)) return false;

        BaseEntity<ID> other = (BaseEntity<ID>) o;
        return other.getId() == this.id;
    }

    public HashMap<String, String> getAttributes() {
        HashMap<String, String> attributes =  new HashMap<>();

        attributes.put("id", id.toString());

        return attributes;
    }

    @Override
    public String toString() {
        return "BaseEntity{" +
                "id=" + id +
                '}';
    }
}
