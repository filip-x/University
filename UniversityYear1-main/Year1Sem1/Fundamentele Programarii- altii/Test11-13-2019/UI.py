import service as s 
import CoffeeShop as cs
import test as t 


def input_delet(coffees):# we take the input that the user writes and we delet it from the list
    country_of_origin=input("Write a country:")
    s.delete_coffee(coffees,country_of_origin)

def input_coffee(coffees): # we take the input and we add the coffee 
    name=input("Write a coffee name :")
    coo=input("write a country:")
    price=float(input("Write a price it can be float"))
    if price <= 0:
        return False
    s.add_coffee(coffees,name,coo,price)

def input_filter(coffees):
    country_of_origin=input("Write a country:")
    price=float(input("Write a price:"))
    filter_list = s.filter_list(coffees, country_of_origin, price)
    return filter_list

def print_menu():# menu print 
    print("1.add")
    print("2.print")
    print("3.filter")
    print("4.delete")


def print_coffee(coffees): # a function that prints the list 
    for i in range(len(coffees)):
        if cs.get_country_of_origin(coffees[i]) != "0":
            print("Name: "+ cs.get_name(coffees[i])+" Country_of_origin: "+cs.get_country_of_origin(coffees[i])+" Price: " + str(cs.get_price(coffees[i])))
def start():
    t.test_add()
    coffees=s.init_coffee()
    while True:
        print_menu()
        choice = input(">")
        if choice == "1":
            if input_coffee(coffees) == False:
                print("Wrong price!")
        elif choice == "2":
            sorted=s.sort_list(coffees)
            print_coffee(sorted)
        elif choice == "3":
            print_coffee(input_filter(coffees))
        elif choice == "4":
            input_delet(coffees)
            print("Removed from  the list")
        elif choice == "5":
            return

start()
