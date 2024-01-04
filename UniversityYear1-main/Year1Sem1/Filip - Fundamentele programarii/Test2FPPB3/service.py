
from studentrepo import StudentRepo
from student import Student
class Service:
    def __init__(self,student):
        self.student=student
    
    def add(self,id,name,count,grade):
        stud=Student(id,name,count,grade)
        self.student.append_function(stud)

        
    