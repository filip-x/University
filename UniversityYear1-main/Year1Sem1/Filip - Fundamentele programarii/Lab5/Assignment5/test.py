import program as p 
import list as l 

def test_correctStudent():
    student=p.student(1,"Filip",3)
    assert student.get_Id()== 1 and student.get_Name()== "Filip" and student.get_Group()== 3

def test_addStudent():
    student = p.student(1, "Filip", 3)
    newlist=l.List(False)
    newlist.addToList(student)
    assert newlist.Students[0] == student
   
