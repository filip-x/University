from domain import Rational
from calculator import Calculator

class UI:
    def __init__(self, calculator):
        self._calculator = calculator

    def _printMenu(self):
        """
        Print out the calculator menu
        """
        print ("Calculator:")
        print ("   + for adding a rational number")
        print ("   c to clear the calculator")
        print ("   u to undo the last operation")
        print ("   ? to count the rational numbers created")
        print ("   x to close the calculator")

    def addNumber(self):
        a = int(input("Give numerator:"))
        b = int(input("Give denominator:"))
        q = Rational(a,b)
        self._calculator.add(q)

    def undo(self):
        self._calculator.undo()

    def clear(self):
        self._calculator.reset()

    def count(self):
        print("Number of rational instances created so far: " + str(self._calculator.getNumberCount()))

    def start(self):
        self._commands = {'+':self.addNumber,'c':self.clear,'u':self.undo, '?':self.count}

        self._calculator.reset()
        while True:
            self._printMenu()
            print("Total: " + str(self._calculator.Total))
            m = input().strip()
            # Exit program
            if (m == 'x'):
                return 
            # Invalid option
            if m not in self._commands:
                print("Bad command")
            # Run user option
            try:
                self._commands[m]()
            except ValueError as ve:
                print("error - "+str(ve))

calc = Calculator()
ui = UI(calc)
ui.start()


