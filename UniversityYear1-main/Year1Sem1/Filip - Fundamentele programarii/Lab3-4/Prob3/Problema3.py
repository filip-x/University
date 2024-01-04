# Problem 2
# this function returns a dict with the problems and pos
import validations as v
import functions as f
import Test as t


def init_participant():# the list with the first 10 participants 
    res =[]
    res.append(f.createParticipant(10,10,10))
    res.append(f.createParticipant(10, 9, 8))
    res.append(f.createParticipant(6, 3, 5))
    res.append(f.createParticipant(8, 5, 3))
    res.append(f.createParticipant(9, 8, 7))
    res.append(f.createParticipant(6, 9, 8))
    res.append(f.createParticipant(8, 8, 6))
    res.append(f.createParticipant(6, 7, 5))
    res.append(f.createParticipant(5, 4, 4))
    res.append(f.createParticipant(1, 1, 1))
    return res 
    

  

def Commands(text,participants,back):#from the input of the user we validate if it's true or not ( as command )

    Words = text.split(" ") # space separates the strings into words( like "add , 5 ,4,,1...")
    print (Words)
    if Words[0] == "": # if there is a space at the start of the command it will be wrong 
        print("Wrong Command!")
        return False
        
    if Words[0] == "add":#we  validate add and then it will do the command if the validation returns True
        if v.Validate_add(participants,Words) == True:
            f.copy_elements(participants,back)
            f.add_Participant(participants,Words[1],Words[2],Words[3])

    if Words[0] == "insert":# we validate insert and then it will do the command if the validation returns True
        if v.Validate_insert(participants,Words) == True:
            f.copy_elements(participants, back)
            f.insert_Participant(participants,Words[1],Words[2],Words[3],Words[5])

    if Words[0] == "remove":    # we remove participants 
        if len(Words) > 3 and Words[2] == "to":# if the commands has "to" then it will do the command that has to ("remove int to int ")
            if v.Validate_remove_to(participants,Words):
                f.copy_elements(participants, back)
                f.remove_participants(participants,int(Words[1]),int(Words[3]))
        elif len(Words) >= 3:
            if v.Validate_remove_score(participants,Words) == True:
                f.copy_elements(participants, back)
                f.remove_score(participants,Words[1],Words[2])

        else:
            if v.Validate_remove(participants, Words) == True:  # if it's with "to" then it validates 2 times
                f.copy_elements(participants, back)
                f.remove_participants(participants, int(Words[1]), int(Words[1]))

    if Words[0] == "replace": # it will replace a participant
       if v.Validate_replace(participants,Words) == True:
           f.copy_elements(participants, back)
           f.replace_participant(participants,int(Words[1]),(Words[2]),int(Words[4]))

    if Words[0] == "list": # we validate "list" and we list all the participants with the given command 
        if len(Words) >= 3:
            if v.Validate_list(participants,Words) == True:
                f.avrage_sort(participants,Words)
        elif len(Words)==2 and Words[1] == "sorted":
            f.SortLBoard(participants)
        elif len(Words) == 1:
            f.ShowLboard(participants)
        else:
            print("Wrong command!!")

    if Words[0] == "avg":
        if v.Validate_avg(participants,Words) == True:
            print(str(f.characteristics_avg(participants,int(Words[1]),int(Words[3]))))

    if Words[0] == "min":
        if v.Validate_min(participants, Words) == True:
            print(str(f.characteristics_min(participants, int(Words[1]), int(Words[3]))))
        
    if Words[0] == "top":
        if len(Words)>=3:
            if v.Validate_top_prob(participants,Words) == True:
                f.top_problem(participants,Words[1],Words[2])
        elif v.Validate_top(participants,Words) == True:
           f.top(participants,Words[1])

    if Words[0] == "undo":
        if len(back) ==0:
            print("No more undos!")
        else:
            participants.clear() #it clears participants list
            restore = back.pop()# we take the last element in back and it delets it
            f.clone(restore,participants)# it clons in participants the last value that was in  it 
# from now on  here are the validation of each command 




def start():# main function that dose everything 
    t.Main_Test()
    participants = init_participant() # res is the participants 
    back=[]
    f.characteristics_avg(participants,1,3)
    while True:
        print("Write a command")
        text = input()
        Commands(text,participants,back)



start()
