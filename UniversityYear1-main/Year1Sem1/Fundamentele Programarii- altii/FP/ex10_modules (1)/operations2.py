'''
Created on Oct 21, 2018

@author: Arthur
'''
from rational import rationalAsList
from rational import rationalAsDict

def addList(q1, q2):
    return rationalAsList.create(rationalAsList.getNom(q1) * rationalAsList.getDenom(q2) + rationalAsList.getNom(q2) * rationalAsList.getDenom(q1), 
                                 rationalAsList.getDenom(q1) * rationalAsList.getDenom(q2))

def addDict(q1, q2):
    return rationalAsDict.create(rationalAsDict.getNom(q1) * rationalAsDict.getDenom(q2) + rationalAsDict.getNom(q2) * rationalAsDict.getDenom(q1), 
                                 rationalAsDict.getDenom(q1) * rationalAsDict.getDenom(q2))

'''
    Rational number represented as List
'''
q1 = rationalAsList.create(1, 2)
q2 = rationalAsList.create(3, 4)
print(addList(q1, q2))


'''
    Rational number represented as Dict
'''
q1 = rationalAsDict.create(1, 2)
q2 = rationalAsDict.create(3, 4)
print(addDict(q1, q2))