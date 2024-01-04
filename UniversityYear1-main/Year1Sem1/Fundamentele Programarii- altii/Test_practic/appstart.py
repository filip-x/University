from board import Board
from service import Service
from game import UserInterface as UI
from test import Tests

def start():
    # he have the translator here, we use this to know  which is our ship, stars and the enemy
    trans = {0: " ",1: "*",2: "E",3: "B",}
    # Setting up the game
    tes= Tests()
    tes.test_star()
    board = Board(trans)  
    Game = Service(board)
    Game.stars()  
    Game.player_ship_E()  
    Game.place_ships_B()  
    ui = UI(Game, board)
    ui.Start()
start()