import Service as s
import Phone as ph
import test  as t

def Test():
    t.test_add()

def input_change(phones):
    manufacturer = input("Enter a manufacturer:")
    if len(manufacturer) < 3:
        print("Wrong manufacturer!")
        return False
    model = input("Enter a model:")
    if len(model) < 3:
        print("Wrong model!")
        return False
    price = int(input("Enter a price:"))
    if price < 100:
        print("Price to low!")
        return False  
    if s.change_phones(phones,manufacturer,model,price) == False:
         return False


 
def input_remove(phones):
    manufacturer = input("Enter a manufacturer:")
    if len(manufacturer) < 3:
        print("Wrong manufacturer!")
        return False
    model = input("Enter a model:")
    if len(model) < 3:
        print("Wrong model!")
        return False
    if s.remove_phone(phones,manufacturer,model) == False:
        return False
    

def input_add(phones):
    manufacturer = input("Enter a manufacturer:")
    if len(manufacturer) < 3:
        print("Wrong manufacturer!")
        return False
    model = input("Enter a model:")
    if len(model) < 3:
        print("Wrong model!")
        return False
    price = int(input("Enter a price:"))
    if price < 100:
        print("Price to low!")
        return False  
    s.add_phone(phones,manufacturer,model,price)



def prnit_ph(phones):
    new_list=s.sort_phones(phones)
    for i in range(len(new_list)):
        print("Manufacturer: " + ph.get_manufacturer(new_list[i]) + " Model: "+ ph.get_model(new_list[i]) + " Price: " + str(ph.get_price(new_list[i])))
        
def print_menu():
    print("1.add")
    print("2.remove")
    print("3.change")
    print("4.list")
    print("5.exit")

def start():
    phones=s.init_phone()

    while True:
        Test()
        print_menu()
        choice=input(">")
        if choice == "1":
            if input_add(phones) == False:
                print("Try again!")
                input_add(phones)
            print("Phone added")  
        elif choice == "2":
            if input_remove(phones) == False:
                print("No man or no model")
            else:
                print("Removed")
        elif choice == "3":
            if input_change(phones) == False:
                print("Wrong mod or man!")
            else:
                print("Changed!")
        elif choice == "4":
            prnit_ph(phones)
        elif choice == "5":
            return

start()    
        
