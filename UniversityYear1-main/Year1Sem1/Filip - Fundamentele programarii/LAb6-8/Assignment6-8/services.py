from student import Student
from assignment import Assignment
from grade import Grade
import validations as v 
import random
from studentrepo import StudentsRepo
from assignmentrepo import AssignmentRepo
from graderepo import GradeRepo
from undoredo import Undo_Redo
from data_structure import List_collector
class Services:
    
    def __init__(self, students, assignemts, grades):

        self.students = students
        #self.students = self.populate_student_list() # students primeste toate elementele din populate_student_list
        #self.assignments = self.generated_list_of_assignments()
        self.assignments = assignemts
        self.grades = grades 
        self.list_undo = Undo_Redo(self.students, self.assignments, self.grades)


    def populate_student_list(self):
        for _ in range(0, 11, 1):
            (name, group) = self.get_random_student()
            generated_student = Student(name, group)
            self.students.append_function(generated_student) 

    def get_random_student(self):
        names = ["Filip", "Stefania", "Amalia", "Emma", "Sofia", "George", "Vlad", "Tudor", "Darius", "Vasile"]  # list with all the names
        group = random.randint(911, 917)  # random group
        i = random.randint(0, 9)
        name = names[i]
        #name = random.choice(names)
        return (name, group)

    def add_new_student(self, name, group):

        # TODO validare pentru nume si grupa

        new_student = Student(name,group)
        self.students.append_function(new_student)
        self.list_undo.choices_undo("2", new_student)  # imi salveaza studentul adaugat in list din undo


    def remove_the_students(self,group,name):
        # TODO validare pentru grupa 
        stud_gl=self.students.Get_list()
        new_list1=[]
        new_list2=[]
        grade_list = self.grades.Get_list()
        for i in range(len(stud_gl)):
            if  stud_gl[i] != None and stud_gl[i].get_group() == group: # fara () se face doar referinta la functie si nu se preia functia 
                new_list1.append(stud_gl[i])
                for j in range(len(grade_list)):
                    if grade_list[j] != None and grade_list[j].get_student() == stud_gl[i].get_id():
                        new_list2.append(grade_list[j])
                self.list_undo.choices_undo("3",[new_list1,new_list2])
                self.grades.repo_remove(stud_gl[i].get_id(),None)
                self.students.repo_remove(stud_gl[i].get_id())
            if stud_gl[i] != None and stud_gl[i].get_name() == name:
                new_list1.append(stud_gl[i])
                for j in range(len(grade_list)):
                    if  grade_list[j] !=None and grade_list[j].get_student() == stud_gl[i].get_id():
                        new_list2.append(grade_list[j])
                self.list_undo.choices_undo("3", [new_list1,new_list2])
                self.grades.repo_remove(stud_gl[i].get_id(),None)
                self.students.repo_remove(stud_gl[i].get_id())
                
            
    def find_update_person(self,id,name,group,choice2):
        stud_gid=self.students.student_search(id) 
        if stud_gid == None:
            return
        data_for_undo=[stud_gid,stud_gid.get_name(),stud_gid.get_group()]
        if choice2 == "1":
            stud_gid.set_name(name)
        elif choice2 == "2":
            stud_gid.set_group(group)
        elif choice2 == "3":
            stud_gid.set_name(name)
            stud_gid.set_group(group)
        data_for_undo.append(stud_gid.get_name())
        data_for_undo.append(stud_gid.get_group())
        self.list_undo.choices_undo("4", data_for_undo)
        if self.students.file_n != None:
            self.students.write_repo()
        
                    
    #============================================================ Student Finished

    def get_random_assignment(self):
        assignment= ["Add","Remove","List","Provide info","Scan","Undo","Copy","Input","Clean","Fly","Walk","Sign","Dress","Swimm"]
        deadline = random.randint(1,12) # we take only the mounth that deadline is 
        i=random.randint(0,13)
        assignments=assignment[i]
        return (assignments, deadline)
    
    def generated_list_of_assignments(self): # populate 
        for _ in range(0,11):
            (assign,deadline) = self.get_random_assignment()
            create_assig = Assignment(assign,deadline)
            self.assignments.append_function(create_assig)
        

    def add_new_assignment(self,description,deadline):
        
        new_assignment = Assignment(description,deadline)
        self.assignments.append_function(new_assignment)
        self.list_undo.choices_undo("6",new_assignment)
        
    
    def remove_the_assignment(self,description,deadline):# description is also deadline
        assig_gl = self.assignments.Get_list()
        new_list1 = []
        new_list2 = []
        grade_list = self.grades.Get_list()
        for i in range(len(assig_gl)):
            if assig_gl[i] != None and assig_gl[i].get_description() == description:
                new_list1.append(assig_gl[i])
                for j in range(len(grade_list)):
                    if grade_list[j].get_assignment() == assig_gl[i].get_id():
                        new_list2.append(grade_list[j])
                self.list_undo.choices_undo("7",[new_list1,new_list2])
                self.grades.repo_remove(None, assig_gl[i].get_aid())
                self.assignments.repo_remove(assig_gl[i].get_aid())
            if assig_gl[i] != None and assig_gl[i].get_deadline() == deadline:
                new_list1.append(assig_gl[i])
                for j in range(len(grade_list)):
                    if grade_list[j].get_assignment() == assig_gl[i].get_id():
                        new_list2.append(grade_list[j])
                self.list_undo.choices_undo("7", [new_list1,new_list2])
                self.grades.repo_remove(None, assig_gl[i].get_aid())
                self.assignments.repo_remove(assig_gl[i].get_aid())
            

    def find_update_assignment(self, choice, id, description, deadline):
        assig_gid=self.assignments.assignment_search(id) 
        if assig_gid == None:
            return
        data_for_undo = [assig_gid, assig_gid.get_description(), assig_gid.get_deadline()]
        if choice == "1":
            assig_gid.set_description(description)
        elif choice == "2":
            assig_gid.set_deadline(deadline)
        elif choice == "3":
            assig_gid.set_description(description)
            assig_gid.set_deadline(deadline)
        self.list_undo.choices_undo("8",data_for_undo)
        if self.assignments.file_n != None:
            self.assignments.write_repo()

     #============================================================ Assignment Finished
    

    #def generated_list_of_grades(self):
     #   generated_list3 = []
      #  for i in range(0, 11):
       #     grade = self.get_random_grade()
        #    create_grade = Grade(i,i,grade)
         #   generated_list3.append(create_grade)
       # return generated_list3

#    def build_grade_list(self):
 #       builder = ""
  #      for grade in self.grades:
   #         if grade != None:
    #            builder += str(grade) + "\n"

     #   return builder


    def get_random_grade(self): # this gives a random grade !
        grade = random.randint(1, 10)
        return grade

    def add_grades(self):
        variable= Grade(1,1,6)
        self.grades.append_function(variable)
        variable = Grade(3,3,10)
        self.grades.append_function(variable)


    def assignment_and_student_id(self,aid,sid):
        if self.students.student_search(sid) == None or self.assignments.assignment_search(aid) == None:
            return False
        else:
            if v.validate_assi_stud(sid,aid,self.grades) == True:
                variable=Grade(aid,sid,0)
                self.grades.append_function(variable)
                self.list_undo.choices_undo("9",variable)
                return True
            else:
                print("\nAlready exists!\n")
                return False
        
        
        

    def group_and_assignment_id(self,aid,group):
        undo_redo_list=[]
        for i in range(len(self.students.Get_list())):
            if self.students.Get_list()[i] != None and self.students.Get_list()[i].get_group() == group and v.validate_assi_stud(self.students.Get_list()[i].get_id(), aid, self.grades) == True:
                variable_grade=Grade(aid, self.students.Get_list()[i].get_id(), 0)
                self.grades.append_function(variable_grade)
                undo_redo_list.append(variable_grade)
                self.list_undo.choices_undo("10",undo_redo_list)
    def finding_id_assignment(self,sid):
        for i in range(len(self.grades.Get_list())):
            if self.grades.Get_list()[i] != None and self.grades.Get_list()[i].get_student() == sid:
                print("Assignment ID: " + str(self.grades.Get_list()[i].get_assignment()) + " Student ID: " + str(self.grades.Get_list()[i].get_student()))
                
    def grading(self,aid,sid,grade):
        for i in range(len(self.grades.Get_list())):
            if self.grades.Get_list()[i] != None and self.grades.Get_list()[i].get_student() == sid:
                if self.grades.Get_list()[i].get_assignment() == aid:
                    self.grades.Get_list()[i].set_grade(grade)
                    self.list_undo.choices_undo("11",[self.grades.Get_list()[i],grade])
        if self.grades.file_n !=None:
            self.grades.write_repo()

    def standings1(self,aid):
        for i in range(len(self.grades.Get_list())):
            for j in range( i+1 ,len(self.grades.Get_list())):
                if self.grades.Get_list()[i] != None and self.grades.Get_list()[j] != None and self.grades.Get_list()[i].get_assignment() == aid and self.grades.Get_list()[j].get_assignment() == aid and self.grades.Get_list()[i].get_grade() > self.grades.Get_list()[j].get_grade():
                    aux = self.grades.Get_list()[i]
                    self.grades.Get_list()[i] = self.grades.Get_list()[j]
                    self.grades.Get_list()[j] = aux
    
    def standings2(self):
        aux_list= []
        for i in range(len(self.grades.Get_list())):
            if self.grades.Get_list()[i] != None and self.grades.Get_list()[i].get_grade() == 0:
                aux_list.append( self.grades.Get_list()[i])
        return aux_list
            
    def compare(self,avgElem1,avgElem2):
        if avgElem1[0] <= avgElem2[0]:
            return True
        return False

    def standings3(self):
        list_grades=[]
        avg=List_collector()
        sort=[]
        for i in range(len(self.grades.Get_list())):
            if self.grades.Get_list()[i] != None and self.grades.Get_list()[i].get_grade != 0:
                list_grades.append(self.grades.Get_list()[i])
        for i in range(len(self.students.Get_list())):
            if self.students.Get_list()[i] != None:
                Student = self.students.Get_list()[i]
                suma=0
                ct= 0
                for j in range(len(list_grades)):
                    if list_grades[j].get_student() == Student.get_id():
                        suma = suma + list_grades[j].get_grade()
                        ct += 1
                if ct!=0:
                    suma= suma/ct        
                avg.append([suma,Student])
        avg.gnomeSort(self.compare)
        for avgElem in avg:
            sort.append(avgElem[1])

        return sort

    def activate_undo(self):
        self.list_undo.undo()


    def activate_redo(self):
        self.list_undo.redo()





