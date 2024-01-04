import Phone as ph

def sort_phones(phones):
    sortedlist=[*phones] # or we can go with for 
    
    for i in range(len(sortedlist)-1):
        for j in range(i+1,len(sortedlist)):
            if ph.get_price(sortedlist[i]) > ph.get_price(sortedlist[j]):
                aux = sortedlist[i]
                sortedlist[i]=sortedlist[j]
                sortedlist[j]=aux
    return sortedlist

def change_phones(res,manufacturer,model,price):
    ct=0
    for i in range(len(res)):
        if ph.get_manufacturer(res[i]) == manufacturer and ph.get_model(res[i]) == model:
            pret_adi=ph.get_price(res[i])
            price=price+pret_adi
            ph.set_price(res[i],price)
            ct+=1
    if ct == 0:
        return False
    

def add_phone(res,manufacturer,model,price):
    #man = ph.get_manufacturer(manufacturer)
    #mod = ph.get_model(model)
    #p =ph.get_model(price)
    added_phone=ph.create_phone(manufacturer,model,price)
    res.append(added_phone)

def remove_phone(res,manufacturer,model):
    ct=0
    for i in range(len(res)):
        if ph.get_manufacturer(res[i]) == manufacturer and ph.get_model(res[i]) == model:
            res.pop(i)
            ct+=1
            break
    if ct == 0:
        return False


def init_phone():
    res = []
    res.append(ph.create_phone("Samsung", "Note10", 3000))
    res.append(ph.create_phone("Apple", "Iphonex", 2320))
    res.append(ph.create_phone("Huawei", "P30", 1000))
    res.append(ph.create_phone("OnePlus", "Oneplus7", 2700))
    res.append(ph.create_phone("Google", "Pixel", 2500))
    return res

