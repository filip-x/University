from domain import Rational

class Calculator:
    def __init__(self):
        self._total = Rational(0)
        self._history = []

    @property
    def Total(self):
        # Total is a read-only property
        return self._total

    def add(self, r):
        '''
        Add a number to the calculator. Adding 0 will not create an undo point
        param:
            r - the number to add
        '''
        if r == Rational(0):
            return 
        # Record for undo
        self._history.append(self._total)
        # Add the value to calculator total
        self._total += r

    def undo(self):
        if len(self._history) == 0:
            raise ValueError('No more undo steps!')
        self._total = self._history.pop()

    def getNumberCount(self):
        return Rational.getTotalNumberOfInstances()

    def reset(self):
        self._total = Rational(0)