from collections import Counter
import time
def mod(a, b):
    return a - (a // b) * b

def thatManNamedEuclidWhoInventedCmmdcButNotWithSubstraction(nr1,nr2):
    while nr2 !=0:
        res = mod(nr1, nr2)
        nr1 = nr2
        nr2 = res
    return nr1

def inSearchOfTheCmmdc(nr1,nr2):
    maxim =1
    for i in range(1,min(nr1,nr2)+1):
        if mod(nr1, i) == 0 and mod(nr2, i) == 0:
            maxim = i
    return maxim


def descompunereInfactoriPrimiPentruProblemaPeCareNuOSaOFolosescPreaCurand(nr1):
    d=2
    lista =[]
    while nr1!= 1:
        while(mod(nr1, d) == 0):
            nr1 =nr1/d
            lista.append(d)
        d+=1
    return lista


def theCmmdcThatNoOneKnowsBcsWeAllLearnEuclidOrSubstraction(nr1,nr2):
    vector1 = descompunereInfactoriPrimiPentruProblemaPeCareNuOSaOFolosescPreaCurand(nr1)
    vector2 = descompunereInfactoriPrimiPentruProblemaPeCareNuOSaOFolosescPreaCurand(nr2)
    intersectionVector = list((Counter(vector1) & Counter(vector2)).elements())# counter trasnforma vectorul intr-un dictonar care retine de cate ori apare fiecare numar ( cheia ii valoarea si  valorarea ii de cate ori apare) cand fac & imi ia doar alea comune si apoi o fac o lista 
    product = 1
    for i in intersectionVector:
        product = product*i
    return product

def test():
    elems = [[11, 12], [8, 12], [50, 24]]
    for e in elems:
        t = time.time_ns()
        r1 = thatManNamedEuclidWhoInventedCmmdcButNotWithSubstraction(e[0], e[1])
        print("Euclid took", time.time_ns() - t, "nano seconds to run with", e)
        t = time.time_ns()
        r2 = inSearchOfTheCmmdc(e[0], e[1])
        print("Linear search took", time.time_ns() - t, "nano seconds to run with", e)
        t = time.time_ns()
        r3 = theCmmdcThatNoOneKnowsBcsWeAllLearnEuclidOrSubstraction(e[0], e[1])
        print("Prime factors took", time.time_ns() - t, "nano seconds to run with", e)
        if r1 == r2 and r2 == r3:
            print("All 3 algorithms got the same result for", e, ":", r3)
        else: 
            print("Different results for gcd between the 3 algorithms with input", e)
        print()
        
test()
