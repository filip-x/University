
#import service_students as s 
from services import Services
import tests as t 
import validations as v 


class UI: # classes are called like functions
        
    def __init__(self,students,assignemts,grades): # constructor
        self.service = Services(students, assignemts, grades)
#STANDING3    
    def input_standing3(self):
        list_standings3 = self.service.standings3()
        for i in range(len(list_standings3)):
            print("ID: " + str(list_standings3[i].get_id()) + " Name: " + list_standings3[i].get_name() + " Group: " + str(list_standings3[i].get_group()))
            # show student with the grade

#STANDING2
    def input_standing2(self):
        list_standings2=self.service.standings2()
        for i in range(len(list_standings2)):
            print("Assignment ID: " + str(list_standings2[i].get_assignment()) + " Student ID: " + str(list_standings2[i].get_student()) + " Grade:" + str(list_standings2[i].get_grade()))
# STANDINGS1
    def input_standing1(self):
        #sid = int(input("Write an id for the student:"))
        aid = int(input("Write the id for the assignemt:"))
        self.service.standings1(aid)
        for i in range(len(self.service.grades.Get_list())):
            if self.service.grades.Get_list()[i] != None and self.service.grades.Get_list()[i].get_assignment() == aid:
                print("Assignment ID: " + str(self.service.grades.Get_list()[i].get_assignment()) + " Student ID: " + str(self.service.grades.Get_list()[i].get_student()) + " Grade:" + str(self.service.grades.Get_list()[i].get_grade()))


    def grading_students_assignments(self):
        sid = int(input("Write an id for the student you want to grade:"))
        self.service.finding_id_assignment(sid)
        aid = int(input("Write the id for the assignemt you want to grade for the chosen student:"))
        grade = int(input("Write a grade from 1 to 10:"))
        v.validate_grading(grade)
        self.service.grading(aid,sid,grade)
    # GROUP TO ASSIGNMENT
    def input_grade_groups(self):
        group = int(input("Enter a group between 912-918:"))
        aid = int(input("Enter the input of the assignment:"))
        if self.service.group_and_assignment_id(aid,group) == False:
            print("Wrong number !")
            return
        group_assignment = self.service.grades.Get_list()
        for i in range(len(group_assignment)):
           # print("Assignment ID: " + str(aid) + " Student ID " +str(group_assignment[i].get_student())+ " Grade " + str(group_assignment[i].get_grade()))
            if group_assignment[i] != None:
                print("Assignment ID: " + str(group_assignment[i].get_assignment())+ " Student ID: " +str(group_assignment[i].get_student()) + " Grade:"+ str(group_assignment[i].get_grade()) )
    # STUDENT TO ASSIGNMENT
    def input_grade_2ex(self):
        aid = int(input("Enter a assignment id:"))
        sid = int(input("Enter a student id:"))
        if self.service.assignment_and_student_id(aid,sid) == False:
            print("Wrong ID")
        else:
            for i in range(len(self.service.grades.Get_list())):
                if self.service.grades.Get_list()[i]!= None:
                    print("Assignment ID: " + str(self.service.grades.Get_list()[i].get_assignment()) + " Student ID " + str(self.service.grades.Get_list()[i].get_student()) + " Grade " + str(self.service.grades.Get_list()[i].get_grade()))
#==========================================================================================================================
# UPDATE ASSIGNMENT 
    def input_update_assignment(self):#Reworked
        print("Enter 1 to change only the description. Enter 2 to change only the deadline or enter 3 to change both")
        choice2= input("Write 1, 2 or 3:")
        assignment_id = int(input("ID:"))
        description = None
        deadline = None
        if choice2 == "1":
            description = input("Write a new description:")
        elif choice2 =="2":
            deadline = input("Write a new the deadline:")
        elif choice2  == "3":
             description = input("Write a new description:")
             deadline = input("Write a new the deadline:")

        v.update_assignment_validation(choice2,assignment_id,deadline)
        self.service.find_update_assignment(choice2,assignment_id,description,deadline)
# REMOVE ASSIGNMENT
    def input_remove_assignment(self):#Reworked
        choice2 = input("Write 1 or 2:")
        description = None
        deadline = None
        if choice2 == "1":
           description = input("Write a description:")
        elif choice2 == "2":
            deadline = input("Write a the deadline:")
        v.remove_assignment_validation(choice2,description,deadline)
        self.service.remove_the_assignment(description,deadline)
# ADD  ASSIGNMENT
    def input_add_assignment(self):
        description = input("Write a description:")
        deadline = (input("Enter a deadline:"))
        v.add_assignment_validation(description,deadline)
        self.service.add_new_assignment(description,deadline)
#================================================================================================
# UPDATE STUDENT
    def input_update_student(self):# Reworked
        print("You need to input the id of the student in order to update him!")
        choice2 = input("1 to update the name,2 to update the group and 3 to update both")
        id = int(input("ID:"))
        group = None
        name = None
        if choice2 == "1":
            name = input("Type the new name: ")
        elif choice2 =="2":
            group = input("Type a new group: ")
        elif choice2 == "3":
            name = input("Type the new name: ")
            group = input("Type a new group: ")
        v.update_student_validation(id,name,group,choice2)
        self.service.find_update_person(id,name,group,choice2)
# REMOVE STUDENT 
    def input_remove_student(self):#Reworked
        group = None
        name = None
        choice2 = input("Write a number between 1 to 2: ")
        if choice2 == "1":
            group = int(input("Write a specific group you want to delete: "))
        elif choice2 == "2":
            name = input("write a name: ")
        v.remove_student_validation(group,choice2)
        self.service.remove_the_students(group,name)
# ADD STUDENT 
    def input_student(self):
        name = input("Write a name:")
        group = int(input("Write a group:"))
        v.add_student_validation(name,group)
        self.service.add_new_student(name,group)
#MENU
    def Menu_print(self):
        print("0.Exit")
        print("1.Show students")
        print("2.Add students")
        print("3.Remove students")
        print("4.Update students")
        print("5.Show assignment")
        print("6.Add assignment")
        print("7.Remove assignment")
        print("8.Update assignment")
        print("9.Show grades")
        print("10.Show group-assignments")
        print("11.Grading")
        print("12.Standings1")
        print("13.Standings2")
        print("14.Standings3")
        print("15.Undo")
        print("16.Redo")
#START FUNCTION
    def Start(self):
        #self.service.add_grades()
        #self.service.populate_student_list()
        #self.service.generated_list_of_assignments()
        while True:
            #try:
                self.Menu_print()
                choice=input(">")
                if choice == "0":
                    return 
                elif choice == "1":
                    print(str(self.service.students))
                elif choice == "2":
                    self.input_student()
                elif choice == "3":
                    self.input_remove_student()
                elif choice == "4":
                    self.input_update_student()
                elif choice == "5":
                    print(str(self.service.assignments))
                elif choice == "6":
                    self.input_add_assignment()
                elif choice == "7": 
                    self.input_remove_assignment()
                elif choice == "8":
                    self.input_update_assignment()
                elif choice == "9":
                    self.input_grade_2ex()
                elif choice == "10":
                    self.input_grade_groups()
                elif choice == "11":
                    self.grading_students_assignments()
                elif choice == "12":
                    self.input_standing1()
                elif choice == "13":
                    self.input_standing2()
                elif choice == "14":
                    self.input_standing3()
                elif choice == "15":
                    self.service.activate_undo()
                elif choice == "16":
                    self.service.activate_redo()
                else:
                    raise Exception("\nWrong number!\n")
            #except Exception as error:
            #    print("\n" + str(error) + "\n")



