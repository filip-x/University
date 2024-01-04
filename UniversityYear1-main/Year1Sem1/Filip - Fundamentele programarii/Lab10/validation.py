import exception as ex
class Validation:


    def validation_enter_matrix(self):
        pass

    def validation_input_x_o(self,x,y,symbol,board):

        if x not in [0, 1, 2, 3, 4, 5] or y not in [0, 1, 2, 3, 4, 5]:# it workswith in range(6)
            raise ex.IncorrectMove("Move not inside the board!")
        if board.getter(x,y) != 0:
            raise ex.SquareTaken("Square is already taken!")
        if symbol not in ['x', 'o']:
            raise ex.IncorrectSymbol("Bad symbol!")
    

    