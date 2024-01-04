from studentrepo import StudentsRepo
from student import Student
from services import Services
from repostudentfile import RepoStudentFile
import pickle 
class RepoStudentBinaryFile(RepoStudentFile):

    def read_repo(self):
        try:
            open_file = open(self.file_n, "rb")
            save_students_lists=pickle.load(open_file)
            for student_list in save_students_lists:
                file_student = Student(student_list[1], student_list[2], student_list[0])  # we created a student
                self.students.append(file_student)  # we got him in the list
            open_file.close()
        except EOFError:# pickle will give an error if the file is empty
            pass
        except IOError as error: # if it's an input error
            raise error
            

    def write_repo(self):
        save_students_lists=[]
        open_file = open(self.file_n, "wb")
        for i in range(len(self.students)):
            # if the students is not  there it won't be written
            if self.students[i] != None:
                student_list=[self.students[i].get_id(),self.students[i].get_name(),self.students[i].get_group()]
                save_students_lists.append(student_list)
        pickle.dump(save_students_lists,open_file)
        open_file.close()

    
