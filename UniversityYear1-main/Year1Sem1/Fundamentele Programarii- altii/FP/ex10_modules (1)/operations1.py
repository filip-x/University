'''
Created on Oct 21, 2018

@author: Arthur
'''
X = 5
'''
    Switch the order of the import statements below. What happens?
'''
from rational.rationalAsList import create,getDenom,getNom
# from rational.rationalAsDict import create,getDenom,getNom

import rational.rationalAsDict
import rational.rationalAsList

# print(rational.rationalAsDict.create(1,3))
# print(rational.rationalAsList.create(8,9))

def add(q1, q2):
    return create(getNom(q1) * getDenom(q2) + getNom(q2) * getDenom(q1), getDenom(q1) * getDenom(q2))

# q1 = create(1, 2)
# q2 = create(3, 4)
# print(add(q1, q2))

'''
Let's see what the dir(...) and help(...) functions do
'''
import math
# print(dir(rational.rationalAsDict))
print(help(math))