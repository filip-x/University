
class Board:

    def __init__(self):
         self.board = [0]*36
    
    def getter(self,x,y):
        return self.board[6*x+y]

    def setter(self,x,y,symbol):
        self.board[6*x+y]=symbol
    
    def get_row(self,x):# IT gets the rows from the matrix 
        return self.board[6*x:6*x+6]


        

        
