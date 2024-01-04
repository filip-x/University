import random as r
from validations import Validation

class Service:
    def __init__(self, board):
        self.__board = board
        self.Valid = Validation()

    @property
    def board(self):
        return self.__board
    
    def placement(self, x, y): # here checks if the placement are placed correctly
        if x not in range(0, self.board.wd) or y not in range(0, self.board.ht):
            return False
        di = [-1, -1, -1, 0, 1, 1, 1, 0, 0]
        dj = [-1, 0, 1, 1, 1, 0, -1, -1, 0]
        for i in range(len(di)):
            i_i = x + di[i]
            j_j = y + dj[i]
            if i_i in range(0, self.board.wd) and j_j in range(0, self.board.ht): # so that the placement of the star will not be over the board 
                if self.board.Get(i_i, j_j) != 0:
                    return False
        
        return True

    
    #it places the enemy ship
    def place_ships_B(self):
        count = 0
        while count < 3:
            x = r.randint(0, self.board.wd - 1)
            y = r.randint(0, self.board.ht - 1)
            if self.board.Get(x, y) == 0:
                count = count + 1
                self.board.Set(x, y, 3) # we place the enemy ship
    # it places the player ship
    def player_ship_E(self):
        placed = False
        x, y = None, None
        while placed == False:
            x = r.randint(0, self.board.wd - 1)
            y = r.randint(0, self.board.ht - 1)
            if self.board.Get(x, y) == 0:
                placed = True
                self.board.Set(x, y, 2) #we place our ship 
        self.board.E = [x, y]
# we place 10 stars 
# we place 10 stars it counts the numbers of stars put if they are 10 they stop 
#  the stars are put randomly on the board 
# it checks if the placement is corrct and then 
    def stars(self, count=10):
        count = 0 # cout for the stars( we check if there are 10 )
        while count < 10:  
            x = r.randint(0, self.board.wd-1)
            y = r.randint(0, self.board.ht-1)
            if self.placement(x,y) == True:
                count = count+ 1
                self.board.Set(x, y, 1) # we place on the board the stars
    
    

    
    
