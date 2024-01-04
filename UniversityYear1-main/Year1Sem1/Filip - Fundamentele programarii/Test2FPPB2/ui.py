from service import Service

class UI:
    
    def __init__(self,human):
        self.service = Service(human)

    def print_menu(self):
        print("0.Exit")
        print("1.Day")
        print("2.3Days")
        print("3.Vaccinate")
        print("4.Show file")

    def start(self):
        self.print_menu()

        while True:
            try:
                choice = (input("Write a number between 0 and 3:"))
                if choice =="0":
                    return
                elif choice =="1":
                    print("A dat has  passed")
                    self.service.one_day()
                elif choice =="2":
                    print("2")
                elif choice == "2":
                    print("2")
                elif choice == "3":
                    print("3")
                elif choice == "4":
                    print(self.service.human)
            except Exception as error:
                print("\n"+str(error)+"\n")


    
