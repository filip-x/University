from orders import Orders

class OrderRepo:
    def __init__(self, file_n=None):# for if the file is empty
        self.order = []
        self.file_n = file_n 
        if file_n:
            self.read_repo() # we  read  frm  file 

    def append_function(self, element):
        self.order.append(element)

    def get_list(self):
        return self.order

    def order_search(self, id):
        for i in range(len(self.order)):
            if self.order[i] != None and self.order[i].get_id() == id:
                return self.order[i]
        return None

    def __str__(self):
        create = ""
        for order in self.get_list():
            if order != None:
                create += (str(order) + "\n")
        return create

    def read_repo(self):
        open_file = open(self.file_n, "r")
        
        line = open_file.readline().strip()
        while len(line) > 0:
            line_items = line.split("-")
            file_order = Orders(int(line_items[0]), int(line_items[1]))
            self.order.append(file_order)  #
            line = open_file.readline().strip()
        open_file.close()
