# this is the UI where the board is shown and the moves are printed ( shown)
#   -first we will have a board shown and then we will enter some moves to see if they work
#   -secand we will create the 2 player( one the human and the secand computer) and they will play
#==================================================================================================
from texttable import Texttable
from service import Service
from validation import Validation
from ai import AI
import exception as ex

class Game:
    
    def __init__(self):
        #self.nr_board=[0]*36
        self.service = Service()
        self.board =self.service.board
        self.ai = AI(self.service)
        

    def dict_xo(self):
        d={0:' ',-1:'o',1:'x',9:'*'}# we use this dictonary to make the matrix look  empty
        return d 
    def dict_inversxo(self): # the invers of the dictonary we need it 
        di = {' ':0, 'o':-1,'x':1,'*':9}
        return di

    def input_x_o(self): # the nput from the keyboard 
        x = int(input("Write the x :"))
        y = int(input("Write the y :"))
        symbol = 'x'
        Validation().validation_input_x_o(x,y,symbol,self.board)
        self.service.makeing_spaces_inaccesable(x,y)
        self.board.setter(x,y,self.dict_inversxo()[symbol])
        self.ai.random_free_moves()



    def __str__(self):# the display of the board 
        d=self.dict_xo()
        table= Texttable()
        for i in range(6):
            row = self.board.get_row(i)
            for j in range(6):# acest for  il avem pentru a face din dictionar 'spatiul ' gol atunci cand da de 0 
                v = d[row[j]]
                row[j]=v
            table.add_row(row)
        return table.draw()

    def start_the_game(self):# srart of the game 
        print("The board is 6 X 6 you  must enter  the  x on the board to start ")
        print(g)
        while True:
            try:
                self.input_x_o()
                print(g)
            except ex.PlayerWon as error:
                print("\n"+str(error)+"\n")
                break
            except ex.ComputerWon as error:
                print("\n"+str(error)+"\n")
                break
            except Exception as error:
                print("\n"+str(error)+"\n")
                
g = Game()
g.start_the_game()











# 00 11 22 
# 10 11 12 
# 20 21 22 
#primul ii 0 0  
# in rows baga pe row avem prima data pentru ca i merge de la 0 pana 2
# intra in j si merge pana la 2 =>rows 

'''
    def enter_matrix(self,x,y,symbol):# this functions is to enter x and o into the matrix and see if it works 
        # x,y,in [0,1,2,4,5,6],symbol in [x,o]
        d={'x':1,'o':-1}# this is a revers dictionary for the implementation in the matrix
        if x not in [0, 1, 2, 3, 4, 5, 6] or y not in [0, 1, 2, 3, 4, 5, 6]:
            raise ValueError("Move not inside the board!")
        if self.service.nr_board[6*x+y] != 0:
            raise ValueError("Square is already taken!")
        if symbol not in ['x', 'o']:
            raise ValueError("Bad symbol!")
        self.service.nr_board[6*x+y] = d[symbol]
'''

''' Something to understand the matrix (board)
    def board2(self):
        table =Texttable()
        for i in range(0,36,6):# de cate ori iterm aici atatea linii o sa avem
            row = self.nr_board[i:i+6]# inidica cate elemente sunt pe linie
            table.add_row(row)# aici adauga 3 randuri la prima "coloana!!!!"
        # pentru prima iterati o sa avem direct o matricie de 3 pe 3  
        return table.draw()
    # board 2 este bun, dar nu foloseste dictionar pentru a mentine casutele  gai 
    # pentru aceasta mai avem nevoide de un for in forul pentru a merge pe linia formata si sa putem face  spatii in fiecare ele
    '''
