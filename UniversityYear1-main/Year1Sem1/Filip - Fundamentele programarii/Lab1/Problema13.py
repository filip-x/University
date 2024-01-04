#input: we have an integer.We will extract all prime factors. We count them, after that we will print the number n-th number of the sequence

def NumbersPrinted(x): 
    ct=0 #how many numbers are in the sequence 
    i=1  #the number that we divide 
    p_ct = 0 #for me (how many  prime-divisors has the current i)
    while ct < x:
        p_ct = PrimeFactors(i)
        ct = ct + p_ct
        i=i+1
        
    print(PrimeFactors2(i-1,x-(ct-p_ct))) # aici apelam primefactors2 cu i-ul format
        

def PrimeFactors(n):# PrimeFactors counts the prime factors of  each number 
    d=2
    m=n
    ct2=0
    sem=1 # we assume that the number is prime if sem=1 
    for i in range(d,(n//2)+1,1): 
        if(m%i==0):
            ct2=ct2+1
        while m%i == 0:
            sem=0
            m=m//i        
    if sem == 1 or n == 1:
        ct2=ct2+1
    return ct2 # we return the prime numbers of each number Ex for me: 1:1,2:1,3:1,4:1,5:1,6:2,7:1....

# Primefactors2 is a copy of PrimeFactors1 but in this second Function we return the number that we need from the sequence

def PrimeFactors2(n,k):#PrimeFactors2 counts the prime factors but it returns the number witch we need in order to finish the problem.
    d=2
    m=n
    ct2=0
    sem=1 # we assume that the number is prime if sem=1 
    for i in range(d,(n//2)+1,1): 
        if(m%i==0):
            ct2=ct2+1
            if ct2 == k:
                return i
        while m%i == 0:
            sem=0
            m=m//i        
    if sem == 1 or n == 1:
        ct2=ct2+1
        if ct2==k:
            return n
    
x=int(input('Give a number to X='))
NumbersPrinted(x)


#output: we print the proper factors o every number
# for the prime numbers we will print  them as  they are ( they don't have proper factors)

