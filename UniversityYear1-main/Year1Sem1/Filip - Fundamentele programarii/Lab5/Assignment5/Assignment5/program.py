''' Assignment5 Students '''
# list of students ( each student had id ,name ,group)

class student:
    def __init__(self,id,name,group): # here we have the constructor
        self.id = id
        self.name = name
        self.group = group
    # getter and setters  with getters we get a property of a student and with the setters we set a propety of a student
    def get_Id(self): # we have the getters and setters for the students 
        return self.id

    def get_Name(self):
        return self.name

    def get_Group(self):
        return self.group

    def set_Id(self,value):
        self.id= value

    def set_Name(self, value):
        self.name = value

    def set_Group(self, value):
        self.group = value


    
    


