
class Human:
    def __init__(self,aid,immun,status):
        self.id = aid
        self.immun = immun
        self.status = status
        self.illday = -1
    
    def get_id(self):
        return self.id

    def get_immun(self):
        return self.immun

    def get_status(self):
        return self.status
    
    def get_days(self):
        return self.illday

    def set_id(self,aid):
        self.id = aid

    def set_immun(self,immun):
        self.imun = immun
    
    def set_status(self, status):
        self.status = status
    
    def set_days(self,value):
        self.illday = value
    
    def __str__(self):
        return "ID: " + str(self.get_id()) +" Immun: "+str(self.get_immun()) +" Status: " +self.get_status()

