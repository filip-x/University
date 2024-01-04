from studentrepo import StudentsRepo
from assignmentrepo import AssignmentRepo
from graderepo import GradeRepo

class Undo_Redo:

    def __init__(self,student_list,assignment_list,grade_list):
        self.student = student_list
        self.assignment = assignment_list
        self.grade = grade_list
        self.c1list = []
        self.c2list = []
        self.index = 0 
        
    def choices_undo(self,choice,information): # din aceasta functie  se preiau datele din UI si se intrduc in lista pentru a le prelucra
        while len(self.c1list) > self.index:
            self.c1list.pop()
        listc=["2","3","4","6","7","8","9","10","11"]
        if choice in listc:
            new_list=[]
            new_list.append(choice)
            if choice == "2":
                new_list.append(information)# the info is  a student  here
            elif choice == "3":
                new_list.append(information)
            elif choice == "4":
                new_list.append(information)
            elif choice == "6":
                new_list.append(information)
            elif choice == "7":
                new_list.append(information)
            elif choice == "8":
                new_list.append(information)
            elif choice == "9":
                new_list.append(information)
            elif choice == "10":
                new_list.append(information)
            elif choice == "11":
                new_list.append(information)

            self.c1list.append(new_list)
            self.index+=1

    def undo(self):
        if self.index ==0:
            raise Exception("Nothing to undo")
        current_undo=self.c1list[self.index-1]
        choice = current_undo[0]
        information = current_undo[1]
        if choice =="2":
            self.undo_add(information)
        elif choice == "3":
            self.undo_remove(information[0],information[1])
        elif choice == "4":
            self.undo_update(information[0],information[1],information[2])
        elif choice == "6":
            self.undo_add_assignment(information)
        elif choice == "7":
            self.undo_remove_asignment(information[0],information[1])
        elif choice == "8":
            self.undo_update_assignment(information[0],information[1],information[2])
        elif choice == "9":
            self.undo_show_grades(information)
        elif choice == "10":
            self.undo_show_group_assignment(information)
        elif choice == "11":
            self.undo_grading(information[0])
        self.index= self.index -1

    def redo(self):
        if self.index == len(self.c1list):
            raise Exception("Nothing to redo")
        current_redo = self.c1list[self.index]
        choice = current_redo[0]
        information = current_redo[1]
        if choice == "2":
            self.redo_add(information)
        elif choice == "3":
            self.redo_remove(information[0],information[1])
        elif choice == "4":
            self.redo_update(information[0],information[3],information[4])
        elif choice == "6":
            self.redo_add_aassignment(information)
        elif choice == "7":
            self.redo_remove_assignemt(information[0],information[1])
        elif choice == "8":
            self.redo_update_assignment(information[0],information[3],information[4])
        elif choice == "9":
            self.redo_show_grades(information)
        elif choice == "10":
            self.redo_show_group_assignment(information)
        elif choice == "11":
            self.redo_grading(information[0],information[1])
        self.index = self.index + 1

    def undo_add(self,student): 
        self.grade.repo_remove(student.get_id())
        self.student.repo_remove(student.get_id())
    def redo_add(self,student):
        self.student.append_function(student)

    def undo_remove(self,student,grade):#NEEDS some changes
        for i in range(len(student)):
            self.student.append_function(student[i])
        for i in range(len(grade)):
             self.grade.append_function(grade[i])
    

    def redo_remove(self,student,grade):# needs some changes
        
        for i in range(len(student)):
            self.student.repo_remove(student[i].get_id())
        for i in range(len(grade)):
             self.grade.repo_remove(grade[i].get_student())


    def undo_update(self,student,name,group):
        student.set_name(name)
        student.set_group(group)
        
    def redo_update(self,student,name,group):
        student.set_name(name)
        student.set_group(group)
    
    #==============================================STUDENTS

    def redo_add_aassignment(self, assignment):
        self.assignment.append_function(assignment)

    def undo_add_assignment(self,assignment):
       self.grade.repo_remove(None,assignment.get_aid())
       self.assignment.repo_remove(assignment.get_aid())
       
    
    def undo_remove_asignment(self,assignment,grade):
        for i in range(len(assignment)):
            self.assignment.append_function(assignment[i])
        for i in range(len(grade)):
            self.grade.append_function(grade[i])

    def redo_remove_assignemt(self,assignment,grade):
        for i in range(len(assignment)):
            self.assignment.repo_remove(assignment[i].get_aid())
        for i in range(len(grade)):
            self.grade.repo_remove(None,grade[i].get_assignment())
        
    def undo_update_assignment(self,assignment,description,deadline):
        assignment.set_description(description)
        assignment.set_deadline(deadline)

    def redo_update_assignment(self, assignment, description, deadline):
        assignment.set_description(description)
        assignment.set_deadline(deadline)

#=======================================================ASSIGN

    def undo_show_grades(self,grade):
        self.grade.repo_remove(grade.get_student(),grade.get_assignment())

    def redo_show_grades(self,grade):
        self.grade.append_function(grade)

    def undo_show_group_assignment(self,grade):
        for i in range(len(grade)):
            self.grade.repo_remove(grade[i].get_student(),grade[i].get_assignment())
    
    def redo_show_group_assignment(self,grade):
        for i in range(len(grade)):
            self.grade.append_function(grade[i])

    def undo_grading(self,grade):
        grade.set_grade(0)

    def redo_grading(self,grade,last_grade):
        grade.set_grade(last_grade)

