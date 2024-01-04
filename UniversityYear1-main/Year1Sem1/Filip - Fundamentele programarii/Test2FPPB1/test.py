import unittest
from bus import Bus
from busrepo import BusRepo
from route_code import Route_Code
from reporoute_code import RepoRoute_Code
from service import Service
class Test(unittest.TestCase):

    def test_functi3(self):
        repobus = BusRepo()
        reporoute = RepoRoute_Code()
        bus  = Bus(10,1,"BMW",5)
        route_code = Route_Code(1,10)
        repobus.append_function(bus)
        reporoute.append_function(route_code)
        s=Service(repobus,reporoute)
        self.assertTrue(s.km_travel(10),50)
        #self.assertRaises(Exception,s.km_travel,10) 
        #first error,functia pe careo  caut si parametrii
        #daca functia respectiva apelata cu argumentul respectiv nu da eroare atunci testul esueaza
        # deci nu e bine 

        
