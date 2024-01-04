# input: we have an integer. With this number we extract his proper factors 
def properfactors(n):# it returns is the product of all proper factors 
    d=2 #divisors
    p=1 # product of all divders
    m=n # a copy of n
    for i in range(d,(n//2)+1,1):# for the prime numbers it will return 1
        if m%i == 0:
            p=p*i
            while m % i == 0:
                 m = m//i
    return p
            
        
    
m = int(input('Give a number to M='))
print(properfactors(m))

# output we print the product of all proper factors
