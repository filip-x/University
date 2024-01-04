from bus import Bus

class Service:
    def __init__(self,buses,route_code):
        self.buses= buses
        self.route_code= route_code

    def routes_buses1(self,routine):
        new_list = []
        bus=self.buses.get_list()
        for i in range(len(bus)):
            if bus[i].get_route_code()== routine:
                new_list.append(bus[i])
        return new_list

    def km_travel(self,id):
        km=0
        rout=self.route_code.get_list()
        bus=self.buses.get_list()
        for i in range(len(bus)):
            if bus[i].get_id() == id:
                for j in range(len(rout)):
                    if bus[i].get_route_code() == rout[j].get_route_code():
                        km = bus[i].get_times_route() * rout[j].get_len_km()
                        
        return km 
