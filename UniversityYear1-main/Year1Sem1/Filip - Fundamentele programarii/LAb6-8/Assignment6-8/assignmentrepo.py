from data_structure import List_collector
class AssignmentRepo:

    def __init__(self):
        self.assignments = List_collector()
        self.file_n = None

    def append_function(self,element):
        self.assignments.append(element)

    def Get_list(self):
        return self.assignments

    def assignment_search(self,id):
        for i in range (len(self.assignments)):
            if self.assignments[i] != None and self.assignments[i].get_aid() == id:
                return self.assignments[i]
        return None
    
    def __str__(self):
        builder = ""
        for assignment in self.Get_list():
            if assignment != None:
                builder += str(assignment) + "\n"

        return builder

    def repo_remove(self,id):
        for i in range(len(self.assignments)):
            if  self.assignments[i] != None and self.assignments[i].get_aid() == id:
                self.assignments[i] = None
