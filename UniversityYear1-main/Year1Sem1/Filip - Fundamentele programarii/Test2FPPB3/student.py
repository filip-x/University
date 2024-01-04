
class Student:
    def __init__(self, sid, name, count, grade):
        self.id = sid
        self.name = name
        self.count = count
        self.grade = grade

    def get_id(self):
        return self.id

    def get_name(self):
        return self.name

    def get_count(self):
        return self.count

    def get_grade(self):
        return self.grade

    def set_id(self, sid):
        self.id = sid

    def set_name(self, name):
        self.name = name

    def set_count(self, count):
        self.count = count

    def set_grade(self, grade):
        self.grade = grade

    def __str__(self):
        return "ID: " + str(self.get_id()) + " name: " + self.get_name() + " count: " + str(self.get_count()) + " grade: " + str(self.get_grade())




