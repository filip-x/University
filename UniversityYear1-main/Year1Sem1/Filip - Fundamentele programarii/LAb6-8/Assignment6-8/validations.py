import exceptions as ex

def add_student_validation(name,group):
    if name == "":
        raise ex.InputError("Nothing writen")
    if number_int(group) == False:
        raise ex.InputError("The number is not int")
    if group < 911 or group > 917:
        raise ex.Not_in_range("Group is not between 911 and 917")

def remove_student_validation(group,choice2):
    choice2 = int(choice2)
    if choice2 < 1 or choice2 > 3:
        raise ex.Not_in_range("Not in range")
    if group == None:
        return 
    if number_int(group) == False:
        raise ex.InputError("The number is not int")
    if group < 911 or group > 917:
        raise ex.Not_in_range("Group is not between 911 and 917")

def update_student_validation(id,name,group,choice2):
    choice2 = int(choice2)
    if choice2 < 1 or choice2 > 3:
        raise ex.Not_in_range("Not in range")
    if number_int(id) == False:
        raise ex.InputError("The id is not int")
    if group == None:
        return 
    if number_int(group) == False:
        raise ex.InputError("The number is not int")
    group = int(group)
    if group < 911 or group > 917:
        raise ex.Not_in_range("Not in range ")
    
def add_assignment_validation(description,deadline):
    deadline = int(deadline)
    if deadline > 12 or deadline < 1:
        raise ex.Not_in_range("Not in range")
    if number_int(deadline) == False:
        raise ex.InputError("The number is not int")
    if deadline > 12 or deadline < 1:
        raise ex.Not_in_range("Not in range")

def update_assignment_validation(choice2,id,deadline):
    choice2 = int(choice2)
    if deadline == None:
        return
    if choice2 < 1 or choice2 > 3:
        raise ex.Not_in_range("Not in range")
    if number_int(deadline) == False:
        raise ex.InputError("The number is not int")
    deadline = int(deadline)
    if deadline > 12 or deadline < 1:
        raise ex.Not_in_range("Not in range")

def remove_assignment_validation(choice2,id,deadline):
    choice2 = int(choice2)
    if deadline == None:
        return
    if choice2 < 1 or choice2 > 2:
        raise ex.Not_in_range("Not in range")
    if number_int(deadline) == False:
        raise ex.InputError("The number is not int")
    deadline = int(deadline)
    if deadline > 12 or deadline < 1:
        raise ex.Not_in_range("Not in range")


def validate_assi_stud(sid,aid,grades):
    for i in range(len(grades.Get_list())):
        if grades.Get_list()[i] != None and grades.Get_list()[i].get_student() == sid and grades.Get_list()[i].get_assignment() == aid:
            return False
    return True

def validate_grading(grade):
    if grade <= 0 or grade > 10:
        raise ex.Not_in_range("Not in range")

def number_int(x):
    try:
        int(x)
        return True
    except:
        return False


