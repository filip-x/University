'''
TicTacToe
Player vs Computer (player moves first)
Validate everything
Computer moves:
Lvl1 always make valid moves 
Lvl2 takes all 1-move wins
Lvl3 prevent player's 1-move wins 
'''
from texttable import Texttable


class Board: #domain
    def __init__(self):
        # empty square-0
        # x-1
        # o--1
        self._data=[0]*9
        self._moves = 0

    def  is_Won(self):
        # check rows and columns
        for i in range(3): # 0,1,2 /
            row = self._data[3*i:3*i+3]# don't understand
            col = self._data[i:i+7:3]
            if abs(sum(row)) == 3 or abs(sum(col))== 3:
                return True
        d = self._data
        if (abs(d[0]+d[4]+d[8]))==3:
            return True
        if (abs(d[2]+d[4]+d[6])) == 3:
            return True
        return False
            # 0,3,6
            # 1,4,7
            # 2,5,8
    
    def is_Tie(self):
        # if 0 not in self._data
        return self.is_Won() == False and self._moves == 9
    
    
    def move(self,x,y,symbol):
        # x,y,in [0,1,2],symbol in [x,o]
        if x not in [0,1,2] or y not in [0,1,2]:
            raise ValueError("Move not inside the board!")
        if self._data[3*x+y] != 0:
            raise ValueError("Square is already taken!")
        if symbol not in ['x','o']:
            raise ValueError("Bad symbol!")
        d = {'x':1,'o':-1}
        self._data[3*x+y] = d[symbol]
        self._moves += 1

    def __str__(self):
        t = Texttable()
        d = {-1: 'o', 0: ' ', 1: 'x'}
        for i in range(0,8,3):
            row = self._data[i:i+3]
            for j in range(3):
                row[j] = d[row[j]]
            t.add_row(row)


        return t.draw()



# decide the computer's next move
class SimpletonComputer: # kind of computer player 
    def  calculateMove(self,board):
        pass

class Game: # a kind of controller/service
    pass
class UI:
    pass

b = Board()
b.move(1,1,'x')
b.move(0,0,'x')
b.move(2,2,'x')
print(b)




    
