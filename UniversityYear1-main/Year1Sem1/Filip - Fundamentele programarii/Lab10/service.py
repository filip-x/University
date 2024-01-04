
from board import Board
class Service:

    def __init__(self):
        self.board = Board()


    def makeing_spaces_inaccesable(self,x,y):# here we  only put the * around the point that we want to put
        dx= [-1,-1,0,1,1,1,0,-1]
        dy= [0,1,1,1,0,-1,-1,-1] 
        for i in range(len(dx)):
            nx = x+ dx[i]
            ny = y+ dy[i]
            if nx in [0, 1, 2, 3, 4, 5] and ny  in [0, 1, 2, 3, 4, 5]: 
                self.board.setter(nx,ny,9)
        
        


