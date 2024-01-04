
class Orders:
    def __init__(self, id,distnace):
        self.id = id
        self.distance = distnace
       

    def get_id(self):
        return self.id

    def get_distance(self):
        return self.distance


    def set_id(self, id):
        self.id = id

    def set_distance(self, distance):
        self.distance = distance

    

    def __str__(self):
        return "ID: " + str(self.get_id()) + " Distance: " + str(self.get_distance()) 
