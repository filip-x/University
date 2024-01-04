def arraycounts(n):
    v=[]
    uc=0
    for i in range(0,10,1):
        v.append(0)
    while n != 0:
        uc=n%10
        n = n // 10
        v[uc] = v[uc] + 1
    return v
def numberconstruction(n):
    m=0
    for i in range(1,10,1):
        if n[i] > 0:
            m=m*10+i
            n[i]=n[i]-1
            while n[0] > 0:
                m=m*10+0
                n[0]=n[0]-1
            while n[i] > 0:
                m=m*10+i
                n[i]=n[i]-1
    return m
            
        
n=int(input('Give a number to N=' ))
print(numberconstruction(arraycounts(n)))
