from student import Student



class StudentRepo:
    def __init__(self, file_n=None):
        self.student = []
        self.file_n = file_n  # when none we  don't use files ( just in case)
        if file_n:
            self.read_repo()

    def append_function(self, element):
        self.student.append(element)

    def get_list(self):
        return self.student

    def student_search(self, id):
        for i in range(len(self.student)):
            if self.student[i] != None and self.student[i].get_id() == id:
                return self.student[i]
        return None

    def __str__(self):
        builder = ""
        for student in self.get_list():
            if student != None:
                builder += (str(student) + "\n")
        return builder

    def read_repo(self):
        open_file = open(self.file_n, "r")
        # strips it strips the the spaces at the end of an string and at the beginning
        line = open_file.readline().strip()
        while len(line) > 0:
            # it takes the words in the seq apart and then we remove the spaces
            line_items = line.split("-")
            file_student = Student(int(line_items[0]), line_items[1], int(line_items[2]), int(line_items[3]))
            self.student.append(file_student)  # we got him in the list
            line = open_file.readline().strip()
        open_file.close()
