from board import Board
from service import Service
from UserInterface import UserInterface as UI
if __name__ == "__main__":
    Translation = {
        0: " ",
        1: "*",
        2: "E",
        3: "B", 
    }
    # Setting up the game
    Grid = Board(Translation) # 0.5p
    Game = Service(Grid)
    Game.PlaceStars()    # 1p
    Game.PlacePlayerShip() # 0.5p
    Game.PlaceEnemyShips() # 1p
    ui = UI(Game, Grid)
    ui.Start()