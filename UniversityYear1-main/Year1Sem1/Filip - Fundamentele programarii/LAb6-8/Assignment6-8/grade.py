from assignment import Assignment
from student import Student

class Grade(Assignment,Student):
    def __init__(self,aid,sid,g):

        self.assignment = aid
        self.student = sid
        self.grade = g

    def get_assignment(self):
        return self.assignment

    def get_student(self):
        return self.student

    def get_grade(self):
        return self.grade

    def set_assignment(self, aid):
        self.assignment = aid

    def set_student(self, sid):
        self.student = sid

    def set_grade(self, g):
        self.grade = g

    def __str__(self):
        return "ID: " + str(self.get_assignment()) + " Name: " + str(self.get_student()) + " Group: " + str(self.get_grade())

     
