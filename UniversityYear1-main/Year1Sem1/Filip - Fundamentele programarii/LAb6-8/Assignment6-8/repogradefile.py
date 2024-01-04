from graderepo import GradeRepo
from grade import Grade
from services import Services


class RepoGradeFile(GradeRepo):
    def __init__(self,file_name):
        super().__init__()
        self.file_n = file_name
        self.read_repo()

    def read_repo(self):
            open_file=open(self.file_n,"r")
            line = open_file.readline().strip()# strips it strips the the spaces at the end of an string and at the beginning
            while len(line) > 0:
                line_items = line.split("-")# it takes the words in the seq apart and then we remove the spaces
                file_student=Grade(int(line_items[0]),int(line_items[1]),int(line_items[2]))# we created a student
                self.grades.append(file_student) # we got him in the list 
                line = open_file.readline().strip()
            open_file.close()

    def write_repo(self):
        open_file = open(self.file_n,"w")
        for i in range (len(self.grades)):
            if self.grades[i] != None:
                line =str(str(self.grades[i].get_assignment()) + "-" + str(self.grades[i].get_student())+"-"+str(self.grades[i].get_grade()))+"\n"
                open_file.write(line)
        open_file.close()

    def append_function(self,element):
        super().append_function(element)
        self.write_repo()

    def repo_remove(self,sid,aid):
        super().repo_remove(sid,aid)
        self.write_repo()