from data_structure import List_collector
class GradeRepo:
    def __init__(self):
        self.grades = List_collector() 
        self.file_n = None

    def append_function(self,element):
        self.grades.append(element)

    def Get_list(self):
        return self.grades

    def grade_search(self,aid,sid):
        for i in range(len(self.grades)):
            if self.grades[i] != None and (self.grades[i].get_assignment() == aid or self.grades[i].get_student() == aid):  
                return self.grades[i].get_grade()
        return None
                
    def repo_remove(self,sid=None,aid=None):# WE MAKE BOTH NONE AT STARTBCS WE DON'T RECALL TH FUNCTION WITH BOTH PARAMS 
        for i in range(len(self.grades)):
            if self.grades[i] != None and (self.grades[i].get_student() == sid or self.grades[i].get_assignment() == aid):  
                self.grades[i] = None
