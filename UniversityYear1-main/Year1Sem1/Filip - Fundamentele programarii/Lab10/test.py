import unittest
from validation import Validation
from exception import *
from service import Service
from ai import AI
from board import Board
class Test(unittest.TestCase):
    
    def test_validation(self):
        valid= Validation()
        self.assertRaises(IncorrectMove,valid.validation_input_x_o,6,6,None,None)
        self.assertRaises(IncorrectMove,valid.validation_input_x_o,-1,-1,None,None)
        new_board = Board()
        new_board.setter(0,0,1)
        self.assertRaises(SquareTaken,valid.validation_input_x_o,0,0,'x',new_board)
        self.assertRaises(IncorrectSymbol,valid.validation_input_x_o,4,4,'>',new_board)
        valid.validation_input_x_o(2,2,'x',new_board)
    
    def test_board(self):
        new_board = Board()
        self.assertEqual(new_board.getter(1,1),0)
        new_board.setter(2,2,1)
        self.assertEqual(new_board.getter(2,2),1)
        self.assertEqual(new_board.get_row(2),[0,0,1,0,0,0])
    
    def test_service(self):
        new_service =Service()
        new_service.makeing_spaces_inaccesable(1,1)
        dx = [-1, -1, 0, 1, 1, 1, 0, -1]
        dy = [0, 1, 1, 1, 0, -1, -1, -1]
        for i in range(len(dx)):
            nx = 1 + dx[i]
            ny = 1 + dy[i]
            if nx in [0, 1, 2, 3, 4, 5] and ny in [0, 1, 2, 3, 4, 5]:
               self.assertEqual(new_service.board.getter(nx,ny),9)
        self.assertEqual(new_service.board.getter(4,4),0)
        self.assertEqual(new_service.board.getter(1,1), 0)
    def test_ai(self):
        new_service = Service()
        new_ai = AI(new_service)
        moves=new_ai.moves_left()
        for i in range(6):
            for j in range(6):
                self.assertTrue([i,j] in moves)# verifica daca chestia aia ii egala cu true
        
        new_ai.random_free_moves()
        moves=new_ai.moves_left()
        self.assertNotEqual(len(moves),36)
        
