from orders import Orders
from drivers import Drivers
from orderrepo import OrderRepo
from driverrepo import DriverRepo
import validation as v 
class Service:
    def __init__(self,drivers,orders):
        self.drivers = drivers
        self.orders = orders

    
    def add(self,id,distance):# we add an order and  we  validate first 
        if v.add_validation(id,distance,self.drivers.get_list()) == True:
            order=Orders(id,distance)# we enter the oerder into the class order
            self.orders.append_function(order)# we add with the help of the repo
            return True
        else:
            return False

    def compute(self,id):
        price = 0
        driver=self.drivers.get_list()
        order= self.orders.get_list()
        for i in range(len(driver)):
            if driver[i].get_id() == int(id):
                for j in range(len(order)):
                    if order[j].get_id() == int(id):
                        price = float(price+2.5*order[j].get_distance())
        return price 

                    


    
    
