

class UserInterface:
    def __init__(self, Service, Grid):
        self.Game = Service
        self.Grid = Grid

    def DisplayMap(self):
        print(self.Grid)
    
    def CheatDisplayMap(self):
        self.Grid.Cheat = True
        print(self.Grid)
        self.Grid.Cheat = False
    
    def ReadCommand(self):
        Command = input("> ")
        CommandArgs = Command.split()
        return CommandArgs
    
    def Start(self):
        while True:
            try:
                self.DisplayMap()
                Args = self.ReadCommand()
                if Args[0] == "wrap":
                    self.Game.Wrap(Args[1:])
                else:
                    print("Command not found!")
            except Exception as Error:
                print(str(Error))


