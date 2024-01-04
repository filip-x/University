def Validate_add(participants, Words): # we validate the add command 
    if len(Words) != 4: #if the lenght of the command is larger then in the exemple then it's wrong 
        print("Incorrect command!")
        return False
    if errors(participants, Words) == False:
        return False
    if IntFunction(Words[1]) == False:
        print("It's not number!!!")
        return False
    if IntFunction(Words[2]) == False:
        print("It's not number!!!")
        return False
    if IntFunction(Words[3]) == False:
        print("It's not number!!!")
        return False
    if int(Words[1]) < 0 or int(Words[2]) < 0 or int(Words[3]) < 0 or int(Words[1])> 10 or int(Words[2]) > 10 or int(Words[3]) > 10:
        print("Invalid number!")
        return False
    return True


def Validate_insert(participants, Words): # the validation to the command insert if is wrong then a error apears 
    if len(Words) != 6:
        print("Incorrect command!")
        return False
    if errors(participants, Words) == False:
        return False
    if IntFunction(Words[1]) == False:
        print("It's not number!!!")
        return False
    if IntFunction(Words[2]) == False:
        print("It's not number!!!")
        return False
    if IntFunction(Words[3]) == False:
        print("It's not number!!!")
        return False
    if Words[4] != "at":
        print("It must be at ")
        return False
    if IntFunction(Words[5]) == False:
        print("It's not number!!!")
        return False
    if int(Words[1]) < 0 or int(Words[2]) < 0 or int(Words[3]) < 0 or int(Words[5]) < 0 or int(Words[5])>len(participants):
        print("Invalid number!")
        return False

    return True


def Validate_remove(participants, Words):# the validation for the remove command
    if len(Words) != 2:
        print("Incorrect command!")
        return False
    if errors(participants, Words) == False:
        return False
    if IntFunction(Words[1]) == False:
        print("It's not number!!!")
        return False
    if int(Words[1])<0 or int(Words[1]) >= len(participants):
        print("Invalid command!")
        return False
    return True


def Validate_remove_to(participants, Words): #the validation for the remove to command 
    if len(Words) != 4:
        print("Incorrect command!")
        return False
    if errors(participants, Words) == False:
        return False
    if IntFunction(Words[1]) == False:
        print("It's not number!!!")
        return False
    if IntFunction(Words[3]) == False:
        print("It's not number!!!")
        return False
    if int(Words[1]) < 0:
        print("Wrong first number!")
        return False
    if int(Words[1]) > int(Words[3]):
        print("Wrong command")
        return False
    if int(Words[3]) >= (len(participants)):
        print("Number to big, the bigest number you can remove is:" +
              str(int(len(participants))-1))
        return False
    return True


def Validate_replace(participants, Words): # we validate the replace command 
    if len(Words) != 5:
        print("Incorrect command!")
        return False
    if errors(participants, Words) == False:
        return False
    if IntFunction(Words[1]) == False:
        print("It's not number!!!")
        return False
    if Words[2] != "p1" and Words[2] != "p2" and Words[2] != "p3":
        return False
    if Words[3] != "with":
        print("Incorrect command")
        return False
    if IntFunction(Words[4]) == False:
        print("It's not number!!!")
        return False
    if int(Words[1]) < 0 or int(Words[1]) >=len(participants) or int(Words[4] < 0 or int(Words[4])>10):
        print("Invalid command!")
        return False
    return True


def Validate_list(participants, Words): # Validation to the list command 
    if len(Words) != 3:
        print("Incorrect command!")
        return False
    if errors(participants, Words) == False:
        return False
    if Words[1] != "<" and Words[1] != "=" and Words[1] != ">":
        return False
    if IntFunction(Words[2]) == False:
        return False
    if int(Words[2]) <0 or int(Words[2])> 10:
        print("Invalid number!")
        return False
    return True  
#if Words[1] in ["<","=",">"]: it's for the if with the or's


def Validate_avg(participants, Words):  # charch avg
    if len(Words) != 4:
        print("Incorrect command!")
        return False
    if errors(participants, Words) == False:
        return False
    if IntFunction(Words[1]) == False:
        print("It's not number!!!")
        return False
    if IntFunction(Words[3]) == False:
        print("It's not number!!!")
        return False
    if (int(Words[1]) < 0 or int(Words[3]) < 0) or (int(Words[1]) > int(Words[3])) or int(Words[3])>= len(participants):
        print("Invalid number or order")
        return False
    if Words[2] != "to":
        print("Incorrect command")
        return False
    return True


def Validate_min(participants, Words):  # chararac min
    if len(Words) != 4:
        print("Incorrect command!")
        return False
    if errors(participants, Words) == False:
        return False
    if IntFunction(Words[1]) == False:
        print("It's not number!!!")
        return False
    if IntFunction(Words[3]) == False:
        print("It's not number!!!")
        return False
    if (int(Words[1]) < 0 or int(Words[3]) < 0) or (int(Words[1]) > int(Words[3])) or int(Words[3]) >= len(participants):
        print("Invalid number or order")
        return False
    if Words[2] != "to":
        print("Incorrect command")
        return False
    return True


def Validate_top(participants, Words): # the top-validation
    if len(Words) != 2:
        print("Incorrect command!")
        return False
    if errors(participants, Words) == False:
        return False
    if IntFunction(Words[1]) == False:
        print("It's not number!!!")
        return False
    if int(Words[1]) < 0 or int(Words[1]) >= len(participants):
        print("Invalid number!")
        return False
    return True


def Validate_top_prob(participants, Words):
    if len(Words) != 3:
        print("Incorrect command!")
        return False
    if errors(participants, Words) == False:
        return False
    if IntFunction(Words[1]) == False:
        print("It's not number!!!")
        return False
    if int(Words[1]) < 0 or int(Words[1]) >= len(participants):
        print("Invalid number!")
        return False
    if Words[2] != "p1" and Words[2] != "p2" and Words[2] != "p3":
        print("Wrong Command")
        return False
    return True


def Validate_remove_score(participants, Words):
    if len(Words) != 3:
        print("Incorrect command!")
        return False
    if errors(participants, Words) == False:
        return False
    if Words[1] != "<" and Words[1] != ">" and Words[1] != "=":
        print("Invalid command!")
        return False
    if IntFunction(Words[2]) == False:
        print("It's not number!!!")
        return False
    if int(Words[2]) < 0 or int(Words[2])>= len(participants):
        print("Invalid command")
        return False
    return True


def IntFunction(number):# funtion to determin if an element is int  or not 
    try:
        int(number)
        return True
    except:
        return False


def errors(participants, Words):# if we have to many "     " it is an error or when the command has only one word it is wrong unless it is list or undo !!!
    # the first error is when  2 spaceses are inputed or the command is wrong
    for i in range(len(Words)):
        if Words[i] == "":
            print("Wrong command")
            return False
    if len(Words) == 1 and (Words[0] != "list" or Words[0] != "undo"):
        print("Wrong command !!!!!!")
        return False
