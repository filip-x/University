'''
        Assignment02
        Complex Numbers
'''
import math

def CreateComplexNumbers(rnr = 0,inr = 0):#this function returns the numbers that are introduced if there is no number
    return {"realnr":rnr,"irealnr": inr}# it will show is 0 to real number and 0 to ireal numbers 
    #in vector normal avem v[ un indice (nr)] in dictionar putem sa avem chiar si sir de caractere gen realnr 
def GetRealNumber(number):# we get the real number 
    return number["realnr"]

def GetIrealNumber(number):# we get the ireal number 
    return number["irealnr"]

def SetRealNumber(number,rnr):# we set the real number
    number["realnr"]= rnr
    
def SetIrealNumber(number,inr):# we set the ireal number 
    number["irealnr"]= inr
    

                                  
def ShowNumber(numbers):# this function will print the numbers from number(init_numbers) 
    print("List of Numbers:")
    for s in numbers:# we convert the nr to strings so that we can print them as strings
        if(GetIrealNumber(s)<0):
            print("realnr: " +str(GetRealNumber(s)) +" irealnr: "+ str(GetIrealNumber(s))+"*i " +str(GetRealNumber(s))+str(GetIrealNumber(s))+"i")
        else:
            print("realnr: " +str(GetRealNumber(s)) +" irealnr: "+ str(GetIrealNumber(s))+"*i " +str(GetRealNumber(s))+"+"+str(GetIrealNumber(s))+"i")
    
def ReadNumber():# we read the numbers so that we can add them to the list 
    rnr = int(input('realn number='))# we can input even a negative number so we can work with it 
    inr = int(input('ireal number='))# same  here 
    return CreateComplexNumbers(rnr,inr)

#def ValidComplexNumber(Number, NumberList):

def Add_Numbers(NumbersList):
    # we need  to read  the  numbers from keyboard
    # we need to validate( maybe)
    # we need to add
    Number = ReadNumber()
    NumbersList.append(Number)
    print("Number added to the lsit")
    

def Init_Numbers():# we give some exemples to work with 
    res=[]
    res.append(CreateComplexNumbers(1,2))
    res.append(CreateComplexNumbers(2,1))
    res.append(CreateComplexNumbers(2,2))
    res.append(CreateComplexNumbers(1,-2))
    res.append(CreateComplexNumbers(3,-12))
    res.append(CreateComplexNumbers(4,9))
    res.append(CreateComplexNumbers(6,-45))
    res.append(CreateComplexNumbers(-9,31))
    res.append(CreateComplexNumbers(18,56))
    return res

def PrintMenu():#The menu for this problem 
    print("\n1. Show numbers")
    print("2.Add Complex number")
    print("3.Sequence Properties1")
    print("4.Sequence Properties3")
    print("5.Exit")

def SequenceProp_1(numbers): # for the 1st sequence we will print the longest sequence with strictly increasing numbers 
    numbersarray=[] # we put all real numbers in a list and work on the list 
    n=0 # we use 4 variables to get the longest seqence, the 4 variables determine the first index of the sequence and the last index of the sequence
    i_init=0  
    i_final=0
    i_initaf=0
    i_finalaf=0
    for s in numbers:
        n = n + 1
        numbersarray.append(GetRealNumber(s))
    for i in range(0,n+1,1):
        i_init=i
        for j in range(i+1,n,1):
            if numbersarray[j] > numbersarray[j-1]:
                i_final=j
            elif i_final-i_init > i_finalaf-i_initaf:
                i_finalaf=i_final
                i_initaf=i_init
                break
            else:
                break
    return [i_initaf, i_finalaf]

def PrintSequence(init,final,numbers):# we  print the sequence that we get  from sequence_1 and sequenceprop_3
    for i in range(init,final+1,1): 
        if(GetIrealNumber(numbers[i])<0):
            print("realnr: " +str(GetRealNumber(numbers[i])) +" irealnr: "+ str(GetIrealNumber(numbers[i]))+"*i " +str(GetRealNumber(numbers[i]))+str(GetIrealNumber(numbers[i]))+"i")
        else:
            print("realnr: " +str(GetRealNumber(numbers[i])) +" irealnr: "+ str(GetIrealNumber(numbers[i]))+"*i " +str(GetRealNumber(numbers[i]))+"+"+str(GetIrealNumber(numbers[i]))+"i")
            
def SequenceProp_3(numbers):# 
    modulusarray=[]#we use a list to determine the same mudulus 
    n=0
    i_init=0
    i_final=0
    i_initaf=0
    i_finalaf=0
    for s in range(0,len(numbers)):
        n = n + 1
        modulusarray.append(ModulusComplexNr(GetRealNumber(numbers[s]),GetIrealNumber(numbers[s])))
    modulusarray.append(-1) # ( introducem un element in plus pentru ca algoritmul sa intre in elif la final pentru a lua si o posibila noua secventa )
    n += 1
    for i in range(0,n,1):
        i_init=i
        for j in range(i+1,n,1):
            if modulusarray[j] == modulusarray[j-1]:
                i_final=j
            elif i_final - i_init > i_finalaf - i_initaf:
                i_finalaf = i_final
                i_initaf = i_init
                break
            else:
                break # it has reached the end of  the sequence
    return [i_initaf, i_finalaf]

def ModulusComplexNr(real,ireal):
    modulus= math.sqrt(real*real+ireal*ireal)# we calculete the modulus of  the complex numbers 
    return modulus
    
    
def Start():# main function
    numbers=Init_Numbers()
    while True:
        PrintMenu()
        choice = input(">")
        if choice == "1":
           #print("\nThere are no students yet\n")
            ShowNumber(numbers)
        elif choice == "2":
            Add_Numbers(numbers)
        elif choice == "3":
            print("Numbers with a strictly increasing real part")
            seq=SequenceProp_1(numbers)
            init=seq[0]
            final=seq[1]
            PrintSequence(init,final,numbers)
        elif choice == "4":
            seq=SequenceProp_3(numbers)
            init=seq[0]
            final=seq[1]
            PrintSequence(init,final,numbers)
        elif choice == "5":
            return 
        else:
            print("\nInvalid command\n")
Start()

        
#print(Init_Numbers())( works)
