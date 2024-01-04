from service import Service
class UI:
    
    def __init__(self,drivers,orders):
        self.service = Service(drivers,orders)


    def inpute_compute(self):
        id =input("ID:")
        price=self.service.compute(id)
        return price
    def input_add(self):
        id = int(input("ID:"))
        distance= int(input("Distance:"))
        if self.service.add(id,distance) == True:
            print("Added")
        elif self.service.add(id,distance) == False:
            print("False")

    def printmenu(self):
        print("1.add")
        print("2.Show")
        print("3.Compute")
        print("0.exit")
    
    def start(self):
        while True:
            self.printmenu()
            choise= input("Write a number between 0 and 3:")
            try:
                if choise == "0":
                    return
                elif choise == "1":
                    self.input_add()
                elif choise == "2":
                    print(self.service.orders)
                elif choise == "3":
                    print(self.inpute_compute())
            except Exception as error:
               print("\n"+str(error)+"\n")

