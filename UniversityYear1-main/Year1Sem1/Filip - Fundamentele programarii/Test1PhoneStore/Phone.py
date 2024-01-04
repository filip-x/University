

def create_phone(manf,mod,p):
    return {"manufacturer":manf,"model":mod,"price":p}


   
def get_manufacturer(phone):
    return phone["manufacturer"]

def get_model(phone):
    return phone["model"]


def get_price(phone):
    return phone["price"]


def set_manufacturer(phone,manf):
    phone["manufacturer"] = manf


def set_model(phone,mod):
    phone["model"] = mod


def set_price(phone,p):
    phone["price"] = p

