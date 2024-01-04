from service import Service
from validation import Validation
class UI: 

    def __init__(self):
        self.service =Service()
        self.valid = Validation()
    def console(self):
        words=[]
        comand=input("Command: ")
        words=comand.split()
        if words[0]=="swap":
            self.valid.valid_int(words[1])
            self.valid.valid_int(words[2])
            if words[3]=="-":
                self.valid.valid_int(words[4])
                self.valid.valid_int(words[5])
            



            

            

        
    


u = UI()
def start():
    points = u.service.scrumble_the_prop()
    while True:
        try:
            print(points)
            print(u.service.words)
            u.console()

        except Exception as es:
            print(es)

start()
