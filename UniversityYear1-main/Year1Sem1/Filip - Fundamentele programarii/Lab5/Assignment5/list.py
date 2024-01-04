import program as p
import random 
import service as s
class List:
    def __init__(self,b=True):#bool for the test 
        self.Students=[]
        if b == True:
            self.Students = self.init_students() # the list student copys the list returned from init_students
        self.undosaver=[]

    def init_students(self):
        newList=[]
        for i in range(0,11,1): # in this for we will take the values from the randomList and we will studnt after that we put the 3 values in the newList.
            (n, g) = self.randomList()  # n for the name and g for the group
            studnt=p.student(i,n,g) # we take the values from the class students witch is in program.py
            newList.append(studnt) # we add a new element to the list 
        return newList

    def addToList(self,studentcreated):
        self.Students.append(studentcreated)

    def removeFromList(self,groupremoved):
        for i in range(len(self.Students)):
            if self.Students[i] != None and groupremoved == self.Students[i].get_Group():
                self.Students[i]= None

    def copyList(self):
        auxList=[]
        auxList.extend(self.Students)
        self.undosaver.append(auxList)

    def restoreList(self):
        self.Students.clear()
        auxList=self.undosaver.pop()# this takes the last element from the list and removes it
        self.Students.extend(auxList)


    def randomList(self): # here it will make a random name and group for each student
        names=["Emma","Gabriel","Lousie","Filip","Claudiu","Maria","Amalia","Adi","Ioana","Stefan","Adelina","Miriam","Stefania"]
        y=random.randint(1,5)
        i=random.randint(0,12)
        z=names[i]
        return(z,y)

        
