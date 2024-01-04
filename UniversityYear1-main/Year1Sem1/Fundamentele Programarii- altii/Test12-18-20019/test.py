import unittest
from orders import Orders
from drivers import Drivers
from orderrepo import OrderRepo
from driverrepo import DriverRepo
class Test(unittest.TestCase):

    def test_add(self):
        list=[]
        order=Orders(1,15)
        list.append(order)
        assert list[0].get_id() == 1 and list[0].get_distance() ==15
    
        
        
        
        
