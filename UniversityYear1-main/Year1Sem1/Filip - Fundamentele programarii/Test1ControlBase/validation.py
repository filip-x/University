

def validation_list_price(Words):
    if Words[1] != "price":
        print("Wrong command!")
        return False
    return True


def validation_list_quantity(Words):
    if Words[1] != "quantity":
        print("Wrong command!")
        return False
    return True

def int_validatio(number):
    try:
        int(number)
        return True
    except:
        return False
        # sau 
        

def validation_add():
    pass
