
def create_coffee(n,coo,p=0):
    return {"name":n,"country_of_origin":coo,"price":p}

def get_name(coffee):
    return coffee["name"]


def get_country_of_origin(coffee):
    return coffee["country_of_origin"]


def get_price(coffee):
    return coffee["price"]

def set_name(coffee,n):
    coffee["price"] = n

def set_country_of_origin(coffee,coo):
    coffee["country_of_origin"] = coo

def set_price(coffee,p):
    coffee["price"] = p


