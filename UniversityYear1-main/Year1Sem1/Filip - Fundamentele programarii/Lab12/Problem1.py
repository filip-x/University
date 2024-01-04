  
def citire_n():
    n = int(input("How many coins:"))
    return n 
def citire_s():
    s = int(input("Value:"))
    return s
def citire_values(n):
    a = []
    for _ in range(n):
        a.append(int(input("Cost of coins:")))

    return a

def afisare_valori(n,v):
    for i in range(n):
        print("a["+ str(i) +"] = "+ str(v[i]))

def rec_back(n,s,v,stiva):
    
    for i in range(n):
        stiva.append(i)
        if validare(stiva,v,s) == True:
            if validare_suma(stiva,v,s) == True:
                tipar(stiva,v)
            else:
                rec_back(n,s,v,stiva)
        stiva.pop()

def iter_back(n,s,v,stiva):
    stiva.append(-1) # ca sa nu fie goala list de la inceput 
    while len(stiva)>0:
        if stiva[len(stiva)-1]<n-1:
            stiva[len(stiva)-1]+=1
            if validare(stiva,v,s) == True:
                if validare_suma(stiva,v,s) == True:
                    tipar(stiva,v)
                else:
                    stiva.append(-1)
        else:
            stiva.pop()


def validare(stiva,v,s):# ma asigur ca problema indeplineste cerinta
    suma=0
    for i in range(len(stiva)):
        suma = suma+v[stiva[i]]
        if (i > 0 and stiva[i] < stiva[i-1]):
            return False
    if suma <= s: # verificam daca suma elementelor introduse in stiva  este mai mica ca s
        return True 
    
    return False

def validare_suma(stiva,v,s):
    suma=0
    for i in range(len(stiva)):
        suma = suma+v[stiva[i]]
    if suma == s:  # verificam daca suma elementelor introduse in stiva  este mai mica ca s
        return True
    return False

def tipar(stiva,v):
    final=""
    for i  in range(len(stiva)):
        final+=str(v[stiva[i]]) + " "
    print(final)
        



def start():
    n = citire_n()
    s = citire_s()
    v = citire_values(n)
    stiva=[]
    afisare_valori(n,v)
    rec_back(n,s,v,stiva)
    print("")
    iter_back(n,s,v,stiva)

start()