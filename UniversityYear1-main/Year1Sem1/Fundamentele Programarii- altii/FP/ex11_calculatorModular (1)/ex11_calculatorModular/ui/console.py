"""
  The user interface of the calculator
  Contains functions related to the user interaction (console)
"""
from domain.calculator import calcAdd, undo, getCalcTotal, getUndoList, setCalcTotal, resetCalc
from domain.rational import create

def printMenu():
    """
      Print out the main menu of the calculator
    """
    print ("Calculator menu:")
    print ("   + for adding a rational number")
    print ("   c to clear the calculator")
    print ("   u to undo the last operation")
    print ("   x to close the calculator")

def printCurrent(calc):
    """
      Print the current total
    """
    print ("Total:", getCalcTotal(calc))

def run():
    """
      Implement the user interface
    """
    calc = resetCalc()
    finish = False
    printCurrent(calc)
    while not finish:
        printMenu()
        m = input().strip()
        if (m == 'x'):
            finish = True
        elif (m == '+'):
            m = input("Give nominator:")
            n = input("Give denominator:")
            try:
                calcAdd (calc,create(int(m), int(n)))
                printCurrent(calc)
            except ValueError:
                print ("Enter integers for m, n, with not null n")
        elif (m == 'c'):
            calc = resetCalc()
            printCurrent(calc)
        elif (m == 'u'):
            try:
                undo(calc)
                printCurrent(calc)
            except ValueError as ve:
                print(ve)
        else:
            print ("Invalid command")
