from data_structure import List_collector
class StudentsRepo:
    
    def __init__(self):
        self.students = List_collector()
        self.file_n = None# it is none if it dose not uses files

    def append_function(self,element):
        self.students.append(element)

    
    def Get_list(self):
        return self.students
    
    def student_search(self,id):
        for i in range(len(self.students)):
            if self.students[i] != None and self.students[i].get_id() == id:
                return self.students[i]
        return None
    
    def __str__(self):
        builder = ""
        for student in self.Get_list():
            if student != None:
                builder += str(student) + "\n"
        return builder

    def repo_remove(self,id):
        
        for i in range(len(self.students)):
            if self.students[i] != None and self.students[i].get_id() == id:
                self.students[i] = None
                 
