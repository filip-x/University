from service import Service

class UI:
    def __init__(self,student):
        self.service = Service(student)


    def input_add(self):
        sid=int(input("ID:"))
        name=input("Name:")
        
        count=int(input("Cont:"))
        grade=int(input("Grade:"))
        self.service.add(sid,name,count,grade)

    def print_menu(self):
        print("0.exit")
        print("1.add Student")
        print("2.give bonuses")
        print("3.show all students")
    

    def start(self):
        while True:
            self.print_menu()
            try:
                choise = ( input("Number between 0-3:"))
                if choise =="0":
                    return
                elif choise =="1":
                    print("Added")
                    self.input_add()
                elif choise =="2":
                    print("2")
                elif choise =="3":
                    print(self.service.student)
            except Exception as error:
                print("\n"+str(error)+"\n")
