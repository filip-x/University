import functionsv2 as fv2
def ShowLboard(participants):  # print leaderboard
    print("=====================================")
    for s in participants:
        print("Problem1: " + str(fv2.Getprob1(s)) + " Problem2: " +
              str(fv2.Getprob2(s)) + " Problem3: " + str(fv2.Getprob3(s)))


def avrage_sort(participants, Words):
    avg = []
    for i in range(len(participants)):
        avg.append(
            (fv2.Getprob1(participants[i])+fv2.Getprob2(participants[i])+fv2.Getprob3(participants[i]))/3)
    for i in range(len(avg)):
        if Words[1] == "<":
            if avg[i] < int(Words[2]):
                print(("Problem1: " + str(fv2.Getprob1(participants[i])) + " Problem2: " + str(
                    fv2.Getprob2(participants[i])) + " Problem3: " + str(fv2.Getprob3(participants[i]))))
        elif Words[1] == "=":
            if avg[i] == int(Words[2]):
                print(("Problem1: " + str(fv2.Getprob1(participants[i])) + " Problem2: " + str(
                    fv2.Getprob2(participants[i])) + " Problem3: " + str(fv2.Getprob3(participants[i]))))
        else:
            if avg[i] > int(Words[2]):
                print(("Problem1: " + str(fv2.Getprob1(participants[i])) + " Problem2: " + str(
                    fv2.Getprob2(participants[i])) + " Problem3: " + str(fv2.Getprob3(participants[i]))))


def SortLBoard(participants):  # this function sorts the leaderboard based on grades
    sum = []  # here we have the avrage of every element
    sort = []
    for i in range(0, len(participants)):
        sum.append(
            (fv2.Getprob1(participants[i])+fv2.Getprob2(participants[i])+fv2.Getprob3(participants[i]))/3)
        sort.append("Problem1: " + str(fv2.Getprob1(participants[i])) + " Problem2: " + str(
            fv2.Getprob2(participants[i])) + " Problem3: " + str(fv2.Getprob3(participants[i])))
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


def top(participants, hmany):  # it makes the top from how many contestants you input
    avg = []
    sort = []
    for i in range(len(participants)):
        avg.append(
            (fv2.Getprob1(participants[i])+fv2.Getprob2(participants[i])+fv2.Getprob3(participants[i]))/3)
        sort.append("Problem1: " + str(fv2.Getprob1(participants[i])) + " Problem2: " + str(
            fv2.Getprob2(participants[i])) + " Problem3: " + str(fv2.Getprob3(participants[i])))
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
            avg.append(fv2.Getprob1(participants[i]))
        elif problem == "p2":
            avg.append(fv2.Getprob2(participants[i]))
        elif problem == "p3":
            avg.append(fv2.Getprob3(participants[i]))
        sort.append("Problem1: " + str(fv2.Getprob1(participants[i])) + " Problem2: " + str(
            fv2.Getprob2(participants[i])) + " Problem3: " + str(fv2.Getprob3(participants[i])))
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
