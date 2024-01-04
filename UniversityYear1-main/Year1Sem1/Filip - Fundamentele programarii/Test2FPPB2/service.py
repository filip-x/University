

class Service:

    def __init__(self,human):
       self.human = human
    
    def one_day(self):
        humans=self.human.get_list()
        for i in range(len(humans)):
            if humans[i].get_immun() == "nonvaccinated" and humans[i].get_status() == "healthy":
                humans[i].set_status("ill") 
                humans[i].set_days(0)
                break
        for j in  range(len(humans)):
            if humans[j].get_status() == "ill":
                humans[j].set_days(humans[j].get_days()+1)
            if humans[j].get_days() == 3:
                humans[j].set_status("healthy")
                humans[j].set_days(-1)

    def vaccine(self):
        






       
            

    
    


