
class Bus:
    def __init__(self,bid,broute_code,bmodel,btimes_route):
        self.id = bid
        self.route_code = broute_code
        self.model = bmodel
        self.times_route  = btimes_route
    
    def get_id(self):
        return self.id

    def get_route_code(self):
        return self.route_code


    def get_model(self):
        return self.model

    def get_times_route(self):
        return self.times_route


    def set_id(self,bid):
        self.id = bid
    
    def set_route_code(self, broute_code):
        self.route_code = broute_code

    def set_model(self,bmodel):
        self.model = bmodel    
    
    def set_times_route(self, btimes_route):
        self.times_route = btimes_route
    
    def __str__(self):
        return "ID: " + str(self.get_id()) + " Route_Code: " + str(self.get_route_code()) +" Model: "+ self.get_model() +" Times_Route: " + str(self.get_times_route())


