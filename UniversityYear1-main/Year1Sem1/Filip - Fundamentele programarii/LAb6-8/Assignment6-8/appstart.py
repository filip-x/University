import UI as u
from studentrepo import StudentsRepo
from assignmentrepo import AssignmentRepo
from graderepo import GradeRepo
from repostudentfile import RepoStudentFile 
from repoassignmentfile import RepoAssignmentFile
from repogradefile import RepoGradeFile
from repostudentbinaryfile import RepoStudentBinaryFile
from repoassignmentbinaryfile import RepoAssignmentBinaryFile
from repogradebinaryfile import RepoGradeBinaryFile
from repostudentjsonfile import RepoStudentJsonFile
from repoassignmentjsonfile import RepoAssignmentJsonFile
from repogradejsonfile import RepoGradeJsonFile

def read_settings(file_name,save_settings):# this  function reads the file settings and makes the file readable for us in code 
    open_file=open(file_name,"r")
    line = open_file.readline().strip()# strips it strips the the spaces at the end of an string and at the beginning
    while len(line) > 0:
        line_items = line.split("=")# it takes the words in the seq apart and then we remove the spaces
        line_items[0] = line_items[0].strip()# first element like repository students,assignemtns or grades
        line_items[1] = line_items[1].strip() # the second element will  be the element in the "" 
        line_items[1] = line_items[1].strip("\"")# here we eliminate the "" so that we will not work with and all the things will be the same ( it's okay with or without/ it dosen't mater)
        save_settings[line_items[0]] = line_items[1]# it puts in the dictionary the final info/ it saves the dictionary in the final form students= ....
        line = open_file.readline().strip()# we read the next line 
    open_file.close()
    
def create_dictionary():# the creation of the dictionary
    return {}    

def start_settings():
    save_settings=create_dictionary() # the dictionary will be transferd to save_settings
    students = None # at first all  3 are empty
    assignments = None
    grades = None
    read_settings("filesettings.properties",save_settings) # here me make the connection between the dictionary,file.settings and the function read)
    if save_settings["repository"] == "inmemory": # it checks the repository if it is in memory or in files 
        students = StudentsRepo() # we assign the repositorys to the files 
        assignments = AssignmentRepo()
        grades = GradeRepo()
    elif save_settings["repository"] == "textfiles":
        students = RepoStudentFile(save_settings["students"])  # we assign the repositorys to the files
        assignments = RepoAssignmentFile(save_settings["assignments"])
        grades = RepoGradeFile(save_settings["grades"])
    elif save_settings["repository"] == "binaryfile":
        students = RepoStudentBinaryFile(save_settings["students"])  # we assign the repositorys to the files
        assignments = RepoAssignmentBinaryFile(save_settings["assignments"])
        grades = RepoGradeBinaryFile(save_settings["grades"])
    elif save_settings["repository"] == "jsonfile":
        students = RepoStudentJsonFile(save_settings["students"])  # we assign the repositorys to the files
        assignments = RepoAssignmentJsonFile(save_settings["assignments"])
        grades = RepoGradeJsonFile(save_settings["grades"])
    

    call_ui = u.UI(students,assignments,grades)# we start the program
    call_ui.Start()



start_settings()      
