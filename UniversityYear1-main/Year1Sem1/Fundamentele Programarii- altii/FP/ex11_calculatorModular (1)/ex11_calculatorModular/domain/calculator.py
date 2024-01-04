"""
  Calculator module, contains functions related to the calculator
"""
from domain.rational import add, create

'''
    Calculator state
'''
def getCalcTotal(calc):
    return calc[0]

def setCalcTotal(calc, total):
    calc[0] = total

def getUndoList(calc):
    return calc[1]

def resetCalc():
    return [create(0), []]

'''
    Other calculator operations
'''
def undo(calc):
    """
      Undo the last user operation
      post: restore the previous current total
    """
    if len(getUndoList(calc)) == 0:
        raise ValueError("No more undos!")
    
    setCalcTotal(calc, getUndoList(calc)[-1])
    getUndoList(calc).pop

def calcAdd(calc, q):
    """
      add a rational number to the current total
      a, b integer number, b<>0
      post: add a/b to the current total
    """
    # add the current total to the undo list
    
    getUndoList(calc).append(getCalcTotal(calc))
    setCalcTotal(calc, add(getCalcTotal(calc), q))

def test_calculator_add():
    """
      Test function for calculator_add
    """
    c = resetCalc()
    assert getCalcTotal(c) == create(0)
    calcAdd(c, create(1, 2))
    assert getCalcTotal(c) == create(1, 2)
    calcAdd(c, create(1, 3))
    assert getCalcTotal(c) == create(5, 6)
    calcAdd(c, create(1, 6))
    assert getCalcTotal(c) == create(1)

def test_undo():
    """
      Test function for undo
    """
    c = resetCalc()
    calcAdd(c, create(1, 3))
    undo(c)
    assert getCalcTotal(c) == create(0)
    c = resetCalc()
    calcAdd(c, create(1, 3))
    calcAdd(c, create(1, 3))
    calcAdd(c, create(1, 3))
    undo(c)
    assert getCalcTotal(c) == create(2, 3)

test_calculator_add()
test_undo()
