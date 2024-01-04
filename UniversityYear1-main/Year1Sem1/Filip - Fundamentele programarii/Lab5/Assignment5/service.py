import program as p

class Service:

    def __init__(self,addlist):
        self.list = addlist

    def add_student(self,y,z):
        #y=input("Enter a name:")
        #z=input("Enter a group (1-5):")
        newstudent=p.student(len(self.list.Students),y,int(z))
        self.list.copyList()
        self.list.addToList(newstudent)
    
    def remove(self,z):
        self.list.copyList()
        self.list.removeFromList(int(z))
     
    def undo(self):
        if len(self.list.undosaver) > 0:
            self.list.restoreList()
        else:
            return False
    
        
        


    
    
