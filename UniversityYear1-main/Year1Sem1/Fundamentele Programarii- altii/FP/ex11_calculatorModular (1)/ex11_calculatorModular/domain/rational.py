"""
  Utility module to work with rational numbers
"""
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

def add(q1, q2):
    """
    Return the sum of two rational numbers.
    q1, q2 the rational numbers
    return the sum
    """
    return create(getNom(q1) * getDenom(q2) + getNom(q2) * getDenom(q1), getDenom(q1) * getDenom(q2)) 

def test_add():
    """
      Test function for rational_add
    """
    assert add(create(1, 2), create(1, 3)) == create(5, 6)
    assert add(create(1, 2), create(1, 2)) == create(1)


test_add()
