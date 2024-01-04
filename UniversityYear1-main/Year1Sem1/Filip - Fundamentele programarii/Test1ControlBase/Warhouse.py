
def create_warehouse(n,p,q):
    return {"name":n,"price":p,"quantity":q}


def get_name(product):
    return product["name"]


def get_price(product):
    return product["price"]


def get_quantity(product):
    return product["quantity"]


def set_name(product, n):
    product["name"] = n


def set_price(product, p):
    product["price"] = p


def set_quantity(product, q):
    product["quantity"] = q
