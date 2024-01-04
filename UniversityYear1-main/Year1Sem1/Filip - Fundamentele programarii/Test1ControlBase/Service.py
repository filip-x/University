import Warhouse as wh


def sort_list_by_price(big_list):
    sortedlist = [*big_list]  # or we can go with for
    for i in range(len(sortedlist)-1):
        for j in range(i+1,len(sortedlist)):
            if wh.get_price(sortedlist[i]) > wh.get_price(sortedlist[j]):
                aux = sortedlist[i]
                sortedlist[i]=sortedlist[j]
                sortedlist[j]=aux
    return sortedlist


def sort_list_by_quantity(big_list):
    sortedlist = [*big_list]  # or we can go with for
    for i in range(len(sortedlist)-1):
        for j in range(i+1, len(sortedlist)):
            if wh.get_quantity(sortedlist[i]) > wh.get_quantity(sortedlist[j]):
                aux = sortedlist[i]
                sortedlist[i] = sortedlist[j]
                sortedlist[j] = aux
    return sortedlist



def int_products():
    res=[]
    res.append(wh.create_warehouse("Filip",10,5))
    res.append(wh.create_warehouse("Masa",200,10))
    res.append(wh.create_warehouse("Tv",1000,2))
    res.append(wh.create_warehouse("Creion",2,500))
    res.append(wh.create_warehouse("Hartie",1,5422))
    return res
