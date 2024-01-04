import Phone as ph
def test_add():
    save=ph.create_phone("Filip","Comsa",1000)
    assert ph.get_manufacturer(save) == "Filip" and ph.get_model(save) == "Comsa" and ph.get_price(save) == 1000