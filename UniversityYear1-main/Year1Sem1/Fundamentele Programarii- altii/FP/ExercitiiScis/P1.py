'''a=1
b = [str(a),1]
c ={ a: a, str(b[1]): b}
print(type(a)== type(c[1]))
a=["1"]
c=
print(type(a)==type(c[1]))
print(type(b[0])==type(a))
print(str(a)in c )
''' 
#Ex1

 # Divide and conquer
'''
v = [1, 2, 3, 4, 6, 6, 7, 8, 9]


def prob3(st, dr):
    if st == dr:
        if st % 2 == 0:
            if v[st] % 2 == 0:
                return v[st]
        return 0
    else:
        mij = (st+dr)//2
        return prob3(st, mij)+prob3(mij+1, dr)


print(prob3(0, len(v)-1))


Data entry: st ,dr which are the positions in the array 
Return value: is the sum 
Side effect : none
Exceptions: none
Description....


'''

#Ex3


'''
class matrix:
    def __init__(self,x,y):
        self.x=x
        self.y=y
        self.a=[]
    
    def set(self,x,y,value):
        sem=0
        if x < 0 or x >= self.x or y < 0 or y >= self.y:
            raise ValueError
        for i in range(len(self.a)):
            # din ceva fac o alta chestie 
            if self.a[i][0]==x and self.a[i][1]==y and value!=0:
                self.a[i][2]=value
                sem=1
        if sem == 0:
            self.a.append([x,y,value])           
            # am pus ceva in lista 
    def get(self,x,y):
        if x < 0 or x >= self.x or y < 0 or y >= self.y:
            raise ValueError
        for i in range(len(self.a)):
            if self.a[i][0]==x and self.a[i][1] == y :
                return self.a[i][2]
        return 0 

    def __str__(self):
        matricie=""
        for i in range(self.x):
            var= ""
            for j in range(self.y):
                var=var +" "+ str(self.get(i,j))
            matricie=matricie +"\n"+ var
        return matricie


m1=matrix(3,3)
m1.set(1,1,2)
m1.set(2,2,4)
print(m1)
try:
    m1.set(3,3,99)
except Exception as e:
        print(type(e))
m1.set(1,1,m1.get(1,1)+1)
print(m1)
'''
#Ex2
'''
Se citeste un vector cu n elemente numere naturale.
Sa se determine elementul minim din vector folosind 
divide et impera.

'''
'''
v=[7,8,9,10,4,493,48023,321,1]
#9
def probdiv(st,dr):
    if st==dr:
        return v[st]
    else:
        mij=(st+dr)//2
        return min(probdiv(st,mij),probdiv(mij+1,dr))

print(probdiv(0,len(v)-1))
'''
'''
#Ex suplimentar divide
l=[2,4,6,8,10,4,5,7,10]
def f(l):
    if l==None:
        raise ValueError()
    for e in l:
        if e%2==1:
            return True
    return False
print(f(l))

try:
    f(None)
    assert False # asta ne zice daca programul nu da eroare asa cum am vrut si orpeste totul     
except ValueError as ve:
    assert True    
v=[2,4,6,8]
m=[2,1,3,4,5]
assert f(v) == False
assert f(m) == True
'''

v=[1,2,3,4,5,6,7,8,9]
def conq(st,dr):
    if st == dr:
        if v[st]%2==0:
            return 1
        return 0
    else:
        mij=(st+dr)//2
        return conq(st,mij)+conq(mij+1,dr)

print(conq(0,len(v)-1))

class Pizza:
    def __init__(self):
        self.__price =10
        self.__choice=[]

    def get_price(self):
        return self.__price
    
    def add(self,Obiect):
        if isinstance(Obiect,Topping) or isinstance(Obiect,Ingrediente):
            self.__choice.append(Obiect)
            if isinstance(Obiect,Topping):
                self.__price=self.__price+1
            elif isinstance(Obiect,Ingrediente):
                self.__price=self.__price+3

    def __str__(self):
        toate=""
        for i in range(len(self.__choice)):
            toate=toate+str(self.__choice[i])+","
        return str("Pizza "+toate)

class Topping:
    def __init__(self, top):
        self.__topping = top

    def __str__(self):
        return str(self.__topping)


class Ingrediente:

    def __init__(self,ingred):
        self.__ingrediente = ingred
    
    def __str__(self):
        return str(self.__ingrediente)
        
    


def start():
    p=Pizza()
    p.add(Ingrediente("ham"))
    p.add(Topping("milk"))
    print(p.get_price())
    print(p)

start()