from exceptions import Out_of_bounds
from texttable import Texttable as t
class Board:
    def __init__(self, translate, ht = 8, wd = 8):
        self.__board = [0] * (ht * wd)
        self.__wd = wd
        self.__ht = ht
        self.__trans = translate
        self.E=[0, 0] # 

    @property
    def ht(self):
        return self.__ht
    
    @property
    def wd(self):
        return self.__wd

    @property 
    def board(self):
        return self.__board

    def Get(self, x, y):
        return self.__board[y*self.ht+x]
    
    def Set(self, x, y, v):
        self.__board[y* self.ht +x]=v

    def __str__(self): # we   make the board
        table = t()
        rows = []
        h_row = ["0"]
        for i in range(0, self.wd):
            h_row.append(str(i+1))
        rows.append(h_row)
        Letters = ["A","B","C","D","E","F","G","H"]
        for i in range(0, self.ht):
            row = [Letters[i]]
            for j in range(0, self.wd):
                if self.Get(i, j) == 3:
                    if (i - self.E[0])**2+(j -self.E[1])**2<=2:
                        row.append(self.__trans[self.Get(i, j)])
                    else: row.append(self.__trans[0])
                else: row.append(self.__trans[self.Get(i, j)])
            rows.append(row)
        table.add_rows(rows, True)
        return str(table.draw())


