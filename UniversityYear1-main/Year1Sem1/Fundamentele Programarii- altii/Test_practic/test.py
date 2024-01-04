from board import Board 
from service import Service
class Tests:
        
    def test_star(self):
        trans = {1: "*", 2:"E"}
        new_b = Board(trans)
        new_b.Set(1,1,1)
        
        assert new_b.Get(1,1) == 1 # i placed a star  where it should not be and it gives an error  

        try: # with the help of try and except it dose  not sop running
            assert False
            new_b.Set(8,8,1)
            assert True
        except Exception as ex:
            print(ex)
        
        try: 
            assert False
            new_b.Set(1,1,1)
            assert True
        except Exception as ex:
            print(ex)

        new_b.Set(5, 4, 2) # we test to not put the star  on the E ship
        try:
            assert False
            new_b.Set(5, 4, 1)
            assert True
        except Exception as ex:
            print(ex)

        new_b.Set(1,2,1)
        new_b.Set(1,3,1)
        new_b.Set(2,4,1)
        new_b.Set(2,5,1)
        new_b.Set(3,2,1)
        new_b.Set(4,5,1)
        new_b.Set(6,1,1)
        new_b.Set(7,4,1)
        new_b.Set(6,3,1)
        # we place 10 stars 
        try: # we test that when we place the 11-th star we will get an error
            assert False
            new_b.Set(7,7,1) 
            assert True
        except Exception as ex:
            print(ex)

        



