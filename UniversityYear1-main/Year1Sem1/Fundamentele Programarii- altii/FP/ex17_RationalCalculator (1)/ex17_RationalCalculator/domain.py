'''
Created on Oct 30, 2019

@author: Arthur
'''
from math import gcd

class Rational:
    """
      Abstract data type rational numbers
      Domain: {a/b  where a,b integer numbers, b!=0, greatest common divisor a, b =1}
    """

    # Class field is shared by all instances
    _numberOfInstances = 0

    def __init__(self, a, b=1):
        """
          Initialise a rational number
          a,b integers
        """
        if b == 0:
            raise ValueError("Denominator cannot be 0!")

        d = gcd(a, b)
        self.Num = a // d
        self.Denom = b // d
        Rational._numberOfInstances += 1

    @property
    def Num(self):
        return self._numerator

    @Num.setter
    def Num(self, value):
        self._numerator = value

    @property
    def Denom(self):
        return self._denominator

    @Denom.setter
    def Denom(self, value):
        if value == 0:
            raise ValueError("Denominator cannot be 0!")
        self._denominator = value

    @staticmethod
    def getTotalNumberOfInstances():
        """
          Get the number of created rational number instances
          return integer
        """
        return Rational._numberOfInstances

    def add(self, a):
        """
        add 2 rational numbers
        a is a rational number
        Return the sum of two rational numbers as an instance of rational number.
        Raise ValueError if the denominators are zero.
        """
        return Rational(self.Num * a.Denom + self.Denom * a.Num, self.Denom * a.Denom)

    def __add__(self, other):
        """
          Overload + operator
          other  - rational number
          return a rational number, the sum of self and other
        """
        return self.add(other)

    def getFloat(self):
        """
          Get the real value for the rational number
          return a float
        """
        return float(self.Num) / self.Denom

    def __lt__(self, ot):
        """
          Compare 2 rational numbers (less than)
          self the current instance
          ot a rational number
          return True if self<ot, False otherwise
        """
        return self.getFloat() < ot.getFloat()

    def __str__(self):
        """
          provide a string representation for the rational number
          return a string
        """
        return str(self.Num)+"/"+str(self.Denom)

    def __eq__(self, other):
        """
          Verify if 2 rational numbers are equals
          other - a rational number
          return True if the instance is equal with other
        """
        return self.Num == other.Num and self.Denom == other.Denom


def test_rational_add():
    r1 = Rational(1, 2)
    r2 = Rational(1, 3)
    r3 = r1.add(r2)
    assert r3.Num == 5
    assert r3.Denom == 6
    assert r3 == Rational(5, 6)


def testEqual():
    """
      test function for testing == for 2 rational numbers
    """
    r1 = Rational(1, 3)
    assert r1 == r1
    r2 = Rational(1, 3)
    assert r1 == r2
    r1 = Rational(1, 3)
    r1 = r1.add(Rational(2, 3))
    r2 = Rational(1, 1)
    assert r1 == r2


def testCompareOperator():
    """
    Test function for < >
    """
    r1 = Rational(1, 3)
    r2 = Rational(2, 3)
    assert r2 > r1
    assert r1 < r2


def testAddOperator():
    """
      Test function for the + operator
    """
    r1 = Rational(1, 3)
    r2 = Rational(1, 3)
    r3 = r1+r2
    assert r3 == Rational(2, 3)

def testCreate():
    """
      Test function for creating rational numbers
    """
    r1 = Rational(1, 3)  # create the rational number 1/3
    assert r1.Num == 1
    assert r1.Denom == 3
    r1 = Rational(4, 3)  # create the rational number 4/3
    assert r1.Num == 4
    assert r1.Denom == 3

testCreate()
testEqual()
test_rational_add()
testAddOperator()
testCompareOperator()
