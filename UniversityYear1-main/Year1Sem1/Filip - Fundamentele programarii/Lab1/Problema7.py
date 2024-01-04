def PrimeNumber(n):# this functions return true if the number is prime or false if the number is not prime 
    d=2
    m=n
    sem=1
    if m==2:
        return True
    for i in range(d,n//2+1,1):  
        if m%i==0:
            return False
    return True

def Twins(n):# checks if p and q( both prime numbers are twins) they are twins if  the diff between p and q is 2
    # q and p  and twins are when q-p=2
    p=0
    q=0
    m=n
    i=1
    while q-p!=2:
        m=m+1
        if PrimeNumber(m)== True:
            p=m
            q=p+1
            while PrimeNumber(q)!=True:
                q=p+i
                i=i+1
    return q,p
    
        
n=int(input('Give a number to n='))
print(Twins(n))      
        
