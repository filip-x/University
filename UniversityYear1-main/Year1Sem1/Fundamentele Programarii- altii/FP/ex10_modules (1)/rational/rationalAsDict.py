'''
Created on Oct 21, 2018

@author: Arthur
'''
import math

def create(nom, den=1):
    '''
    create a rational no.
    '''
    if den == 0:
        raise ValueError("Denominator cannot be 0")

    d = math.gcd(nom, den)
    return {"nom":nom // d, "denom":den // d}

def getNom(q):
    return q["nom"]

def getDenom(q):
    return q["denom"]
