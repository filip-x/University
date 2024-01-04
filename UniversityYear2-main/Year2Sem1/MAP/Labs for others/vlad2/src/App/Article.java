package App;

public class Article {
    int id;
    String name;
    String category;
    int price;
    String quantityAvalible;
    boolean status;
    public Article( int id,String name,String category,int price,String quantityAvalible,boolean status)
    {
        this.id = id;
        this.name = name;
        this.category = category;
        this.price = price;
        this.quantityAvalible = quantityAvalible;
        this.status = status;
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

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public String getQuantityAvalible() {
        return quantityAvalible;
    }

    public void setQuantityAvalible(String quantityAvalible) {
        this.quantityAvalible = quantityAvalible;
    }

    public boolean isStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }
}
