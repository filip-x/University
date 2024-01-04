# the input for this exercise is an integer 
def numbergreater(x):# we add one every time this fuction is called 
    return x+1

def prim(y):# this function returns true if the number is prime and false if not 
    sem = 0
    if y < 2:
        return False
    if y == 2:
        return True
    for i in range(2,y//2,1): 
            if y%i ==0:   
                return False
    return True  
                
def getprimnumber(n):#this functions  gets the first prime number after n 
    sem=0 
    x = n
    while sem == 0:
        sem =1;
        if prim( numbergreater(x))== True:
            return x+1
        else:
             x = numbergreater(x)
             sem = 0
        
m = int(input('give a number to n= '))
print('first prim number given after n is:')
print(getprimnumber(m))

# we print the biggest prime number after the the inserted value


