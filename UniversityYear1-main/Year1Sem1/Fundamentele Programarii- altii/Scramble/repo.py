class Repo:

    def __init__(self):
        self.list=[]

    def getter(self,index):
        return self.list[index]
    
    def setter(self,word):
        self.list.append(word)
    
    def __str__(self):
        string=""
        for i in range(len(self.list)):
            string= string + self.list[i]+" "
        return string
