from human import Human
from service import Service

class HumanRepo:
    def __init__(self,file_n=None):
        self.human= []
        self.file_n = file_n
        if file_n:
            self.read_repo()

    def append_function(self, element):
        self.human.append(element)

    def get_list(self):
        return self.human

    def human_search(self, id):
        for i in range(len(self.human)):
            if self.human[i] != None and self.human[i].get_id() == id:
                return self.human[i]
        return None

    def __str__(self):
        builder = ""
        for human in self.get_list():
            if human != None:
                builder += (str(human) + "\n")
        return builder


    def read_repo(self):
        print("LalaBand")
        open_file = open(self.file_n, "r")
        # strips it strips the the spaces at the end of an string and at the beginning
        line = open_file.readline().strip()
        while len(line) > 0:
            # it takes the words in the seq apart and then we remove the spaces
            line_items = line.split("-")
            file_human = Human(int(line_items[0]), line_items[1], line_items[2])
            if file_human.get_status() == "ill":
                file_human.set_days(0)
            self.human.append(file_human)  # we got him in the list
            line = open_file.readline().strip()
        open_file.close()
        
