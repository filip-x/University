from orders import Orders
from drivers import Drivers
from orderrepo import OrderRepo
from driverrepo import DriverRepo



def add_validation(id,distance,driver):#  the fvalidation fo the driver id and the distance 
    for  i  in range(len(driver)):
        if driver[i].get_id() != id:
            sem=0 # trebuie cu semador\
    if distance < 1:
        return False
    return True

