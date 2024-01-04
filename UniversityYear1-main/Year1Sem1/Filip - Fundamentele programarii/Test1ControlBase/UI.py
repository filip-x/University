import Service as s 
import Warhouse as wh
import validation as v


def Show_list(products):

    for i in range(len(products)):
        print("Name: " + wh.get_name(products[i]) + " Price: " + str(wh.get_price(products[i])) +" Quantity: " + str(wh.get_quantity(products[i])))

def start():
    products=s.int_products()
    while True:
        choice=input("Write a command:")
        command_list=choice.split()# daca punem "" in split atunci imi ia si spatiile asa nu le ia 
        print(command_list)
        if command_list[0] == "list":
            if v.validation_list_price(command_list) == True:
                sorted=s.sort_list_by_price(products)
                Show_list(sorted)
            elif v.validation_list_quantity(command_list) == True:
                sorted = s.sort_list_by_quantity(products)
                Show_list(sorted)
            else:
                print("Try again!")
        if choice == "add":
            pass

start()
