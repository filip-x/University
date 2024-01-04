'''
Created on Oct 21, 2018

@author: Arthur
'''
from math import gcd

def create(nom, den=1):
    if den == 0:
        raise ValueError("Denominator cannot be 0")
    d = gcd(nom, den)
    return [nom // d, den // d ]

def getNom(q):
    return q[0]

def getDenom(q):
    return q[1]

q = create(1,2)
q[1] = 0