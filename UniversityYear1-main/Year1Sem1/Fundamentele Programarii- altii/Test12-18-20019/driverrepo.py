from drivers import Drivers


class DriverRepo:
    def __init__(self, file_n=None):
        self.driver = []
        self.file_n = file_n  # when none we  don't use files ( just in case)
        if file_n:
            self.read_repo()

    def append_function(self, element):
        self.driver.append(element)

    def get_list(self):
        return self.driver

    def driver_search(self, id):
        for i in range(len(self.driver)):
            if self.driver[i] != None and self.driver[i].get_id() == id:
                return self.driver[i]
        return None

    def __str__(self):
        builder = ""
        for driver in self.get_list():
            if driver != None:
                builder += (str(driver) + "\n")
        return builder

    def read_repo(self):
        open_file = open(self.file_n, "r")
        # strips it strips the the spaces at the end of an string and at the beginning
        line = open_file.readline().strip()
        while len(line) > 0:
            # it takes the words in the seq apart and then we remove the spaces
            line_items = line.split("-")
            file_driver = Drivers(int(line_items[0]), line_items[1])
            self.driver.append(file_driver)  # we got him in the list
            line = open_file.readline().strip()
        open_file.close()
