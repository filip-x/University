from route_code import Route_Code
from service import Service

class RepoRoute_Code:
    
    def __init__(self,file_n=None):
        self.route_code = []
        self.file_n = file_n  # when none we  don't use files ( just in case)
        if file_n:
            self.read_repo()

    def append_function(self, element):
        self.route_code.append(element)

    def get_list(self):
        return self.route_code

    def route_code_search(self,rcode):
        for i in range(len(self.route_code)):
            if self.route_code[i] != None and self.route_code[i].get_route_code() == rcode:
                return self.route_code[i]
        return None
    
    def __str__(self):
        builder = ""
        for route_code in self.get_list():
            if route_code != None:
                builder += (str(route_code) + "\n")
        return builder


    def read_repo(self):
            open_file = open(self.file_n, "r")
            # strips it strips the the spaces at the end of an string and at the beginning
            line = open_file.readline().strip()
            while len(line) > 0:
                # it takes the words in the seq apart and then we remove the spaces
                line_items = line.split("-")
                file_route_code = Route_Code(int(line_items[0]),int(line_items[1]))
                self.route_code.append(file_route_code)  # we got him in the list
                line = open_file.readline().strip()
            open_file.close()


