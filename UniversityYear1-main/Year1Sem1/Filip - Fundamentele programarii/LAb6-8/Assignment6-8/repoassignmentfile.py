from assignmentrepo import  AssignmentRepo
from assignment import Assignment
from services import Services

class RepoAssignmentFile(AssignmentRepo):
    def __init__(self,file_name):
        super().__init__()
        self.file_n = file_name
        self.read_repo()

    def read_repo(self):
        open_file = open(self.file_n,'r')
        line = open_file.readline().strip()
        while len(line) > 0:
            line_items = line.split("-")
            file_assignment = Assignment(line_items[1],line_items[2],int(line_items[0]))
            self.assignments.append(file_assignment)
            line = open_file.readline().strip()
        open_file.close()

    def write_repo(self):
        open_file =open(self.file_n,'w')
        for i in range(len(self.assignments)):
            if self.assignments[i]!= None:
                line =str(self.assignments[i].get_aid())+"-"+self.assignments[i].get_description()+"-"+str(self.assignments[i].get_deadline())+"\n"
                open_file.write(line)
        open_file.close()
    
    def append_function(self,element):
        super().append_function(element)
        self.write_repo()

    def repo_remove(self,id):
        super().repo_remove(id)
        self.write_repo()