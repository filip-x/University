
'''1.Give 2 ints a and b, return True if one of them is 10 or if their sum is 10
    Question- what happends if we  enter a 
 '''
def f(x,y):
    if x == 10 or y == 10 or x+y == 10:
       return True
    else:
        return False 
#How do we make  the program user-proof?
a= int(input('Give a='))
b= int(input('Give b='))
print(f(a,b))


