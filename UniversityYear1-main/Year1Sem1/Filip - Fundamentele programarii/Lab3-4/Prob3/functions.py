# this function dose the avrage of all 3 problems. We print the scors of  the problems that have the avrage <, =, > then what was given
# creats a dict with "keys:" prob1,prob2,prob3


def createParticipant(p1=0, p2=0, p3=0):
    return {"prob1": p1, "prob2": p2, "prob3": p3}


def Getprob1(participant):  # participant is  variable to so  that we know what it will get us
    return participant["prob1"]


def Getprob2(participant):
    return participant["prob2"]


def Getprob3(participant):
    return participant["prob3"]


def Setprob1(participant, p1):
    participant["prob1"] = p1


def Setprob2(participant, p2):
    participant["prob2"] = p2


def Setprob3(participant, p3):
    participant["prob3"] = p3


def ShowLboard(participants):  # print leaderboard
    print("=====================================")
    for s in participants:
        print("Problem1: " + str(Getprob1(s)) + " Problem2: " +
              str(Getprob2(s)) + " Problem3: " + str(Getprob3(s)))
def avrage_sort(participants, Words):
    avg = []
    for i in range(len(participants)):
        avg.append(
            (Getprob1(participants[i])+Getprob2(participants[i])+Getprob3(participants[i]))/3)
    for i in range(len(avg)):
        if Words[1] == "<":
            if avg[i] < int(Words[2]):
                print(("Problem1: " + str(Getprob1(participants[i])) + " Problem2: " + str(
                    Getprob2(participants[i])) + " Problem3: " + str(Getprob3(participants[i]))))
        elif Words[1] == "=":
            if avg[i] == int(Words[2]):
                print(("Problem1: " + str(Getprob1(participants[i])) + " Problem2: " + str(
                    Getprob2(participants[i])) + " Problem3: " + str(Getprob3(participants[i]))))
        else:
            if avg[i] > int(Words[2]):
                print(("Problem1: " + str(Getprob1(participants[i])) + " Problem2: " + str(
                    Getprob2(participants[i])) + " Problem3: " + str(Getprob3(participants[i]))))


def SortLBoard(participants):  # this function sorts the leaderboard based on grades
    sum = []  # here we have the avrage of every element
    sort = []
    for i in range(0, len(participants)):
        sum.append(
            (Getprob1(participants[i])+Getprob2(participants[i])+Getprob3(participants[i]))/3)
        sort.append("Problem1: " + str(Getprob1(participants[i])) + " Problem2: " + str(
            Getprob2(participants[i])) + " Problem3: " + str(Getprob3(participants[i])))
    for i in range(0, len(sum)-1):
        for j in range(i+1, len(sum)):
            if sum[i] < sum[j]:
                aux = sum[i]
                sum[i] = sum[j]
                sum[j] = aux
                aux2 = sort[i]
                sort[i] = sort[j]
                sort[j] = aux2
    print(sum)
    print("")
    for q in sort:
        print(q)


# wi insert a participant with the place allready taken
def insert_Participant(participants, p1, p2, p3, pos):
    participants.insert(int(pos), createParticipant(int(p1), int(p2), int(p3)))
    #return createParticipant(p1,p2,p3)


def add_Participant(participants, p1, p2, p3):  # we add a new participant
    participants.append(createParticipant(int(p1), int(p2), int(p3)))


# we remove a participant/s depends on the command
def remove_participants(participants, start, stop):
    for i in range(start, stop+1, 1):
        Setprob1(participants[i], 0)
        Setprob2(participants[i], 0)
        Setprob3(participants[i], 0)


# we replace a grade from a participant to another
def replace_participant(participants, old, problem, new):
    if problem == "p1":
        Setprob1(participants[old], new)
    if problem == "p2":
        Setprob2(participants[old], new)
    if problem == "p3":
        Setprob3(participants[old], new)


def characteristics_avg(participants, start, stop):#we make the avrage of the avrage for the characteristics 
    avg = []
    sum = 0
    for i in range(len(participants)):
        avg.append(
            (Getprob1(participants[i])+Getprob2(participants[i])+Getprob3(participants[i]))/3)
    for i in range(start, stop+1, 1):
        sum = sum+avg[i]
    sum = sum/(stop-start+1)
    return sum


def characteristics_min(participants, start, stop): # we print the minim from a specific avrage starting from start and all the way to stop
    avg = []
    for i in range(len(participants)):
        avg.append(
            (Getprob1(participants[i])+Getprob2(participants[i])+Getprob3(participants[i]))/3)
    min = avg[start]
    for i in range(start, stop+1, 1):
        if min > avg[i]:
            min = avg[i]
    return min


def top(participants, hmany): # it makes the top from how many contestants you input
    avg = []
    sort = []
    for i in range(len(participants)):
        avg.append(
            (Getprob1(participants[i])+Getprob2(participants[i])+Getprob3(participants[i]))/3)
        sort.append("Problem1: " + str(Getprob1(participants[i])) + " Problem2: " + str(
            Getprob2(participants[i])) + " Problem3: " + str(Getprob3(participants[i])))
    for i in range(0, len(avg)-1):
        for j in range(i+1, len(avg)):
            if avg[i] < avg[j]:
                aux = avg[i]
                avg[i] = avg[j]
                avg[j] = aux
                aux2 = sort[i]
                sort[i] = sort[j]
                sort[j] = aux2
    for i in range(0, int(hmany)):
        print(sort[i])


def top_problem(participants, hmany, problem):
    avg = []
    sort = []
    for i in range(len(participants)):
        if problem == "p1":
            avg.append(Getprob1(participants[i]))
        elif problem == "p2":
            avg.append(Getprob2(participants[i]))
        elif problem == "p3":
            avg.append(Getprob3(participants[i]))
        sort.append("Problem1: " + str(Getprob1(participants[i])) + " Problem2: " + str(
            Getprob2(participants[i])) + " Problem3: " + str(Getprob3(participants[i])))
    for i in range(0, len(avg)-1):
        for j in range(i+1, len(avg)):
            if avg[i] < avg[j]:
                aux = avg[i]
                avg[i] = avg[j]
                avg[j] = aux
                aux2 = sort[i]
                sort[i] = sort[j]
                sort[j] = aux2
    for i in range(0, int(hmany)):
        print(sort[i])


def remove_score(participants, sign, number): # it removes score (it makes 0 to all the problems)
    sum = []  # here we have the avrage of every element
    for i in range(0, len(participants)):
        sum.append(
            (Getprob1(participants[i])+Getprob2(participants[i])+Getprob3(participants[i]))/3)
    for i in range(len(participants)):
        if sign == "<":
            if sum[i] < int(number):
                Setprob1(participants[i], 0)
                Setprob2(participants[i], 0)
                Setprob3(participants[i], 0)
        elif sign == ">":
            if sum[i] > int(number):
                Setprob1(participants[i], 0)
                Setprob2(participants[i], 0)
                Setprob3(participants[i], 0)
        elif sign == "=":
            if sum[i] == int(number):
                Setprob1(participants[i], 0)
                Setprob2(participants[i], 0)
                Setprob3(participants[i], 0)
        


def clone(list1, list2):# this function clones one list into the other 
    for i in range(len(list1)):
        list2.append(createParticipant(Getprob1(list1[i]), Getprob2(list1[i]), Getprob3(list1[i])))


def copy_elements(participants, back):# we use the clone function to copy the element for the undo command
    new = []
    clone(participants, new)
    back.append(new)
