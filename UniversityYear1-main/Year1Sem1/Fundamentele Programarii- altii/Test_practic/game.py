

class UserInterface:
    def __init__(self, service, board):
        self.Game = service
        self.board = board

    def DisplayMap(self):
        print(self.board)
        
    def Start(self):
        while True:
            try:
                self.DisplayMap()
                break
            except Exception as Error:
                print(str(Error))
