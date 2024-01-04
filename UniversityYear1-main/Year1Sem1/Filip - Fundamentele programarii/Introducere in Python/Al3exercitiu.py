def stringSplosion(s):
    res = ''
    for i in range(0,len(s)):
        res += s[0:i+1]
    return res
s='python'
print(s[::2])# afiseaza din 2 in 2 
#print(stringSplosion('python'))
