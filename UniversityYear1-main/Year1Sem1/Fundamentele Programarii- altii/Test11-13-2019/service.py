import CoffeeShop as cs


def delete_coffee(res,country_of_origin):
    for i in range(len(res)):
       if cs.get_country_of_origin(res[i]) == country_of_origin:
           cs.set_country_of_origin(res[i],"0")
            

def filter_list(res,country_of_origin,price):

    new_list=[]
    sortedlist = [*res]  # or we can go with for
    for i in range(len(sortedlist)):
        if cs.get_country_of_origin(sortedlist[i]) == country_of_origin and cs.get_price(sortedlist[i]) <= price:
            new_list.append(sortedlist[i])  
        
    return new_list

def sort_list(res):

    sortedlist = [*res]  # or we can go with for

    for i in range(len(sortedlist)-1):
        for j in range(i+1, len(sortedlist)):
            if cs.get_country_of_origin(sortedlist[i]) > cs.get_country_of_origin(sortedlist[j]):
                aux = sortedlist[i]
                sortedlist[i] = sortedlist[j]
                sortedlist[j] = aux
            elif cs.get_country_of_origin(sortedlist[i]) == cs.get_country_of_origin(sortedlist[j]) and cs.get_price(sortedlist[i])>cs.get_price(sortedlist[j]):
                aux = sortedlist[i]
                sortedlist[i] = sortedlist[j]
                sortedlist[j] = aux

    return sortedlist


def add_coffee(res, name,country_of_origin, price): # we add a new coffe the input comes from the user in UI
    
    added_coffee = cs.create_coffee(name,country_of_origin,price)
    res.append(added_coffee)

def init_coffee():
    res=[]
    res.append(cs.create_coffee("Filip","Romania",3.5))
    res.append(cs.create_coffee("Late", "Germany",10))
    res.append(cs.create_coffee("Star","Italia",6.5))
    res.append(cs.create_coffee("Lila","France",8.35))
    res.append(cs.create_coffee("Ama", "Romania", 6.5))


    return res
