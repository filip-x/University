from bus import Bus
from  service import Service


class BusRepo:
    def __init__(self,file_n=None):
        self.bus= []
        self.file_n = file_n# when none we  don't use files ( just in case)
        if file_n:
            self.read_repo()

    def append_function(self,element):
        self.bus.append(element)

    def get_list(self):
        return self.bus

    def bus_search(self,id):
        for i in range(len(self.bus)):
            if self.bus[i] != None and self.bus[i].get_id() == id:
                return self.bus[i]
        return None
    
    def __str__(self):
        builder =""
        for bus in self.get_list():
            if bus != None:
                builder += (str(bus) + "\n")
        return builder

    def read_repo(self):
        open_file = open(self.file_n, "r")
        # strips it strips the the spaces at the end of an string and at the beginning
        line = open_file.readline().strip()
        while len(line) > 0:
            # it takes the words in the seq apart and then we remove the spaces
            line_items = line.split("-")
            file_bus = Bus(int(line_items[0]), int(line_items[1]), line_items[2],int(line_items[3]))
            self.bus.append(file_bus)  # we got him in the list
            line = open_file.readline().strip()
        open_file.close()
