import CoffeeShop as cs
import service as s



def test_add():
    test=[]
    s.add_coffee(test,"Comsa","Filip",3.5)
    assert cs.get_name(test[0]) == "Comsa"and cs.get_country_of_origin(test[0]) == "Filip" and cs.get_price(test[0]) == 3.5