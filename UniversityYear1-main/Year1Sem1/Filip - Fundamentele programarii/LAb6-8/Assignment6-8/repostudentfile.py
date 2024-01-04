from studentrepo import StudentsRepo
from student import Student
from services import Services
class RepoStudentFile(StudentsRepo):
    
    def __init__(self,file_name):
        super().__init__()
        self.file_n = file_name
        self.read_repo()

    def read_repo(self):
        open_file=open(self.file_n,"r")
        line = open_file.readline().strip()# strips it strips the the spaces at the end of an string and at the beginning
        while len(line) > 0:
            line_items = line.split("-")# it takes the words in the seq apart and then we remove the spaces
            file_student=Student(line_items[1],int(line_items[2]),int(line_items[0]))# we created a student
            self.students.append(file_student) # we got him in the list 
            line = open_file.readline().strip()
        open_file.close()

    def write_repo(self):
        open_file=open(self.file_n,"w")
        for i in range(len(self.students)):
            if self.students[i] != None: # if the students is not  there it won't be written
                line =str(self.students[i].get_id()) + "-" + self.students[i].get_name()+"-"+ str(self.students[i].get_group())+"\n"
                open_file.write(line)
        open_file.close()

    def append_function(self,element):
        super().append_function(element)
        self.write_repo()
    
    def repo_remove(self,id):
        super().repo_remove(id)
        self.write_repo()
