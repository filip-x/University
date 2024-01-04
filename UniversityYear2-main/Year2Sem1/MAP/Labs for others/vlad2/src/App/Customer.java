package App;

import java.util.ArrayList;
import java.util.List;

public class Customer {
    int id;
    String name;
    List<String> list = new ArrayList<>();
    public Customer(int id,String name, List<String> list)
    {
        this.id = id;
        this.name = name;
        this.list = list;

    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<String> getList() {
        return list;
    }

    public void setList(List<String> list) {
        this.list = list;
    }
}
