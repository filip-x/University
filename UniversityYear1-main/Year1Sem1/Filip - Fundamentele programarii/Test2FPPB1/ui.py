from service import Service




class UI:
    def __init__(self,buses,route_code):
        self.service = Service(buses,route_code)


    def km_travelled(self):
        id=int(input("Bus id:"))
        print(self.service.km_travel(id))

    def display_buses_rout(self):
        routine= int(input("Input the route code:"))
        rlist=self.service.routes_buses1(routine)
        for  i in range(len(rlist)):
            print(rlist[i])

    def print_menu(self):
        print("0.Exit")
        print("1.Display all buses traveliing acrros a certain rout:")
        print("2.Show all buses:")
        print("3.Give a bus id compute the km that the bus has travelled during service:")

    def start(self):
        
        while True:
            self.print_menu()
            try:
                choice=input("Write a number from,0,1,2,3:")
                if choice == "1":
                    self.display_buses_rout()
                elif choice == "2":
                    print(str(self.service.buses))
                elif choice == "3":
                    self.km_travelled()
                elif choice =="0":
                    return
            except Exception as error:
                print("\n"+ str(error) +"\n")



