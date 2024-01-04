#Assignment: <assignmentID>, <description>, <deadline>.
class Assignment:

    new_id =  0
    def __init__(self, sdescription, sdeadline,aid=None):
        if aid != None:
            self.id= aid
            if aid >= Assignment.new_id:
                Assignment.new_id = aid+1
        else:
            self.id =Assignment.new_id
            Assignment.new_id += 1

        self.description = sdescription
        self.deadline = sdeadline
         

    def get_aid(self):
        return self.id

    def get_description(self):
        return self.description

    def get_deadline(self):
        return self.deadline

    def set_aid(self, said):
        self.aid = said

    def set_description(self, sdescription):
        self.description = sdescription

    def set_deadline(self, sdeadline):
        self.deadline = sdeadline

    def __str__(self):
        return "ID: " + str(self.get_aid()) + " Assignment: " + self.get_description() + " Deadline: " + str(self.get_deadline())
