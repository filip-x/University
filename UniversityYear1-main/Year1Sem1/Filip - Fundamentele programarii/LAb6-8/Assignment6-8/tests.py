# here we have all the tests for add remove update -> students and assignment
from services import Services
import student as s 
import unittest
from studentrepo import StudentsRepo
from assignmentrepo import AssignmentRepo
from graderepo import GradeRepo
from data_structure import List_collector
class TestClass(unittest.TestCase):
    def test_student(self):
        stud= StudentsRepo()
        assig= AssignmentRepo()
        grade= GradeRepo()
        serv=Services(stud,assig,grade)
        auxlist = serv.students.Get_list()
        serv.add_new_student("Filip",912)
        self.assertTrue(auxlist[0].get_name() == "Filip" and auxlist[0].get_group() == 912)
        serv.add_new_student("Adi",913) #TEST FOR THE ADD FUNCTION
        self.assertTrue(auxlist[1].get_name() == "Adi" and auxlist[1].get_group() == 913)
        serv.remove_the_students(913,None) # TEST FOR THE REMOVE FUNCTION
        self.assertTrue(auxlist[1] == None)
        serv.find_update_person(0,"Adi",914,"3")
        self.assertTrue(auxlist[0].get_name() == "Adi" and auxlist[0].get_group() == 914)

    def test_assignment(self):
        stud = StudentsRepo()
        assig = AssignmentRepo()
        grade = GradeRepo()
        serv = Services(stud, assig, grade)
        auxlist = serv.assignments.Get_list()
        serv.add_new_assignment("Stay",12)
        self.assertTrue(auxlist[0].get_description() == "Stay" and auxlist[0].get_deadline() == 12)
        serv.add_new_assignment("Walk",9)
        self.assertTrue(auxlist[1].get_description() == "Walk" and auxlist[1].get_deadline() == 9)
        serv.remove_the_assignment("Walk",None)
        self.assertTrue(auxlist[1] == None)
        serv.find_update_assignment("1",0,"Eat",8)
        self.assertTrue(auxlist[0].get_description() == "Eat" and auxlist[0].get_deadline() == 12)

    def compare(self,elemb,elema):# bcs sunt inversi
        if elemb >= elema:
            return True
        else:
            return False
    def compare_filter(self,elem):
        if elem > 5:
            return True
        return False

    def test_list_collector(self):
        new_list = List_collector()
        self.assertEqual(len(new_list),0)
        new_list.append(0)
        self.assertEqual(len(new_list),1)
        self.assertEqual(new_list[0],0)
        new_list[0]=10
        self.assertEqual(new_list[0],10)
        del new_list[0]
        self.assertEqual(len(new_list),0)
        new_list.append(5)
        new_list.append(7)
        it=iter(new_list)
        v=next(it)
        self.assertEqual(v,5)
        v=next(it)
        self.assertEqual(v,7)
        self.assertRaises(StopIteration,next,it)
        new_list.append(8)
        new_list.append(3)
        new_list.gnomeSort(self.compare)
        self.assertEqual(new_list[0],3)
        self.assertEqual(new_list[1],5)
        self.assertEqual(new_list[2],7)
        self.assertEqual(new_list[3],8)
        self.assertEqual(new_list.filter(self.compare_filter),[7,8])



        
    
