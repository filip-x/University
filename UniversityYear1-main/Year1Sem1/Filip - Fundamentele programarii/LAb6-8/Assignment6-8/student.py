#Student: < studentID > , < name > , < group >
class Student:

    new_id=0
    
    def __init__(self,sname, sgroup,sid=None):
        if sid != None:
            self.id=sid
            if sid >= Student.new_id:
                Student.new_id=sid+1
        else:
            self.id = Student.new_id
            Student.new_id += 1
            
        self.name = sname
        self.group = sgroup
        
        

    def get_id(self):
        return self.id

    def get_name(self):
        return self.name

    def get_group(self):
        return self.group

    def set_id(self,sid):
        self.id = sid

    def set_name(self,sname):
        self.name = sname

    def set_group(self,sgroup):
        self.group = sgroup

    def __str__(self):
        return "ID: " + str(self.get_id()) + " Name: " + self.get_name() + " Group: " + str(self.get_group())
