
class Drivers:
    def __init__(self,tid,name):
        self.id= tid
        self.name= name

    def get_id(self):
        return self.id

    def get_name(self):
        return self.name

    
    def set_id(self, tid):
        self.id = tid

    def set_name(self, name):
        self.name = name

   
    def __str__(self):
        return "ID: " + str(self.get_id()) + " Name " + self.get_name()
        
