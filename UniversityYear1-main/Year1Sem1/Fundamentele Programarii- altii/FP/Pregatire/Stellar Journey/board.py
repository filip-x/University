from exceptions import OutOfBounds
from texttable import Texttable as T
class Board:
    def __init__(self, translate, height = 8, width = 8):
        self.__Grid = [0] * (height * width)
        self.__Width = width
        self.__Height = height
        self.__Translation = translate
        self.Cheat = False
        self.E = [0, 0]

    @property
    def Height(self):
        return self.__Height
    
    @property
    def Width(self):
        return self.__Width

    @property 
    def Grid(self):
        return self.__Grid

    def Get(self, x, y):
        return self.__Grid[y * self.Height + x]
    
    def Set(self, x, y, v):
        self.__Grid[y * self.Height + x] = v

    def __str__(self):
        Table = T()
        Rows = []
        hRow = ["0"]
        for i in range(0, self.Width):
            hRow.append(str(i+1))
        Rows.append(hRow)
        Letters = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M"]
        for i in range(0, self.Height):
            Row = [Letters[i]]
            for j in range(0, self.Width):
                if self.Get(i, j) == 3:
                    if (i - self.E[0])**2 + (j - self.E[1])**2 <= 2 or self.Cheat == True:
                        Row.append(self.__Translation[self.Get(i, j)])
                    else: Row.append(self.__Translation[0])
                else: Row.append(self.__Translation[self.Get(i, j)])
            Rows.append(Row)
        Table.add_rows(Rows, True)
        return str(Table.draw())


