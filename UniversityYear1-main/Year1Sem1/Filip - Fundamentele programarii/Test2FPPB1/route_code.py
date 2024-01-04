
class Route_Code:
    
    def __init__(self, rroute_code, rlen_km):
        self.route_code = rroute_code
        self.len_km = rlen_km

    def get_route_code(self):
        return self.route_code
    
    def get_len_km(self):
        return self.len_km

    def set_route_code(self, rroute_code):
        self.route_code = rroute_code

    def set_len_km(self, rlen_km):
        self.len_km = rlen_km

    def __str__(self):
        return " Route_Code: " + str(self.get_route_code()) + " Len_Km : "+ str(self.get_len_km())
