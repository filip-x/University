from service import Service
from list import List
import test as t
class UI:
    
    def __init__(self,service):
        self.service=service

    def MenuOptions(self):
        print("1.Show students")
        print("2.Add students")
        print("3.Remove students")
        print("4.Undo option")
        print("5.Exit")
    
    def create_student(self):
        y = input("Enter a name:")
        z = input("Enter a group (1-5):")
        if int(z) < 1 or int(z) > 5:
            print("False Group")
            return False
        self.service.add_student(y,z)

    
    def remove_group(self):
        z = input("Enter a group you want to remove:")
        if int(z) < 1 or int(z) > 5:
            return False
        self.service.remove(z)

    def ShowStudents(self):
        for j in self.service.list.Students:# we have variable j as to get each student from the list
            if j != None: 
                print(("Id: "+ str(j.get_Id()) +" Name: "+ j.get_Name() + " Group "+ str(j.get_Group())))


    def start(self):
        print("Students with id, name and group")
        t.test_correctStudent()
        t.test_addStudent()
        while True:
            try:
                ui.MenuOptions()
                choice = input(">")
                if choice == "1":
                    self.ShowStudents()
                elif choice == "2":
                    if  not self.create_student() is not False:
                        print("Wrong command, try again")
                        self.create_student() 
                elif choice == "3":
                   if not self.remove_group() is not False:
                       print("Wrong Command,try again")
                       self.remove_group()
                elif choice == "4":
                    if self.service.undo() == False:
                        print("No more undos")
                    self.service.undo()
                elif choice == "5":
                    return
                else:
                    print("\nInvalid command\n")
            except Exception as Error:
                print(str(Error))

l =List()
s = Service(l)
ui = UI(s)
ui.start()
