from board import Board
import random
import exception as ex
class AI:

    def __init__(self,service):
        self.board= service.board # prelucam din service-ul din game care contine board-ul in service 
        self.service = service 
    def moves_left(self):
        moves=[]
        for i in range(6):
            for j in range(6):
                if self.board.getter(i,j) == 0:
                    moves.append([i,j])
        return moves

    def random_free_moves(self):
        free_moves= self.moves_left()
        l = len(free_moves)
        if l != 0:
            rand=random.randint(0,l-1) 
            pair = free_moves[rand] 
            x = pair[0]
            y = pair[1]
            self.board.setter(x,y,-1)
            self.service.makeing_spaces_inaccesable(x, y)
            free_moves = self.moves_left()
            l = len(free_moves)
            if l == 0:
                raise ex.ComputerWon("The Computer has won !!!")
        elif l == 0:
            raise ex.PlayerWon("You Won !")

        

        
