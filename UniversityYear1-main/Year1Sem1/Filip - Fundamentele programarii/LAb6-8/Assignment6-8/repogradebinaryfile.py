from graderepo import GradeRepo
from grade import Grade
from services import Services
from repogradefile import RepoGradeFile
import pickle 
class RepoGradeBinaryFile(RepoGradeFile):

    def read_repo(self):
        try:
            open_file = open(self.file_n, "rb")
            save_grades_lists=pickle.load(open_file)
            for grade_list in save_grades_lists:
                file_grade = Grade(grade_list[0], grade_list[1], grade_list[2])  # we created a grade
                self.grades.append(file_grade)  # we got him in the list
            open_file.close()
        except EOFError:# pickle will give an error if the file is empty
            pass
        except IOError as error: # if it's an input error
            raise error
            

    def write_repo(self):
        save_grades_lists=[]
        open_file = open(self.file_n, "wb")
        for i in range(len(self.grades)):
            # if the grades is not  there it won't be written
            if self.grades[i] != None:
                grade_list=[self.grades[i].get_assignment(),self.grades[i].get_student(),self.grades[i].get_grade()]
                save_grades_lists.append(grade_list)
        pickle.dump(save_grades_lists,open_file)
        open_file.close()

    
