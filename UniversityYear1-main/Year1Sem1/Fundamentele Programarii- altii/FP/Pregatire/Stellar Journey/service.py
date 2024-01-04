import random as r
class Validation:
    def ValidateCoordinates(self, Coord):
        if str(Coord[0]) not in ["A", "B", "C", "D", "E", "F", "G", "H"] or int(Coord[1]) not in range(1, 8+1):
            raise Exception("Bad command!")
    
    def ValidateArgumentsCount(self, Args, Count):
        if len(Args) != Count:
            raise Exception("Wrong arguments!")

class Service:
    def __init__(self, Grid):
        self.__Grid = Grid
        self.Valid = Validation()

    @property
    def Grid(self):
        return self.__Grid
    
    def CheckPlacement(self, x, y):
        if x not in range(0, self.Grid.Width) or y not in range(0, self.Grid.Height):
            return False
        di = [-1, -1, -1, 0, 1, 1, 1, 0, 0]
        dj = [-1, 0, 1, 1, 1, 0, -1, -1, 0]
        for i in range(len(di)):
            ii = x + di[i]
            jj = y + dj[i]
            if ii in range(0, self.Grid.Width) and jj in range(0, self.Grid.Height):
                if self.Grid.Get(ii, jj) != 0:
                    return False
        
        return True

    def PlaceStars(self, Count = 10):
        Count = 0
        while Count < 10:
            x = r.randint(0, self.Grid.Width - 1)
            y = r.randint(0, self.Grid.Height - 1)
            if self.CheckPlacement(x, y) == True:
                Count += 1
                self.Grid.Set(x, y, 1)
    
    def PlacePlayerShip(self):
        Placed = False
        x, y = None, None
        while Placed == False:
            x = r.randint(0, self.Grid.Width - 1)
            y = r.randint(0, self.Grid.Height - 1)
            if self.Grid.Get(x, y) == 0:
                Placed = True
                self.Grid.Set(x, y, 2)
        self.Grid.E = [x, y]

    def PlaceEnemyShips(self):
        Count = 0
        while Count < 3:
            x = r.randint(0, self.Grid.Width - 1)
            y = r.randint(0, self.Grid.Height - 1)
            if self.Grid.Get(x, y) == 0:
                Count += 1
                self.Grid.Set(x, y, 3)
    
    def DecipherCoordinates(self, Coord):
        x = ord(Coord[0]) - ord("A")
        y = int(Coord[1]) - 1
        return x, y

    
    def Wrap(self, Arguments):
        self.Valid.ValidateArgumentsCount(Arguments, 1)
        self.Valid.ValidateCoordinates(Arguments[0])
        x, y = self.DecipherCoordinates(Arguments[0])
        decX = self.Grid.E[0] - x
        decY = self.Grid.E[1] - y
        NonZero = max(abs(decX), abs(decY))
        stepX = decX / NonZero
        stepY = decY / NonZero
        nextX = self.Grid.E[0]
        nextY = self.Grid.E[1]
        if (stepX, stepY) in [(0, 1), (0, -1), (1, 0), (-1, 0), (-1, 1), (1, -1), (1, 1), (-1, -1)]:
            stepX = int(stepX)
            stepY = int(stepY)
            Sum = 0
            for _ in range(NonZero):
                nextX -= stepX
                nextY -= stepY
                Sum += self.Grid.Get(nextX, nextY)
            if Sum == 0:
                self.Grid.Set(*self.Grid.E, 0)
                self.Grid.E = [x, y]
                self.Grid.Set(*self.Grid.E, 2)
