# by deafault,classes inherit object
#object has  an __str__ defined
#but it has no __len__ defined
class Animal(object):
    def __init__(self,name):
        self._name = name

    def get_name(self):
        return self._name

    def speak(self):
        return None
    
    def __str__(self):
        return "Animal:"+str(self._name) +" says "+str(self.speak())
    
class Cat(Animal): # cat inherits from Animal
    def __init__(self,name):
        super().__init__(name)
    
    def speak(self):
        return "meow"

    def __str__(self):
        return "Cat:"+str(self._name) + " says "+str(self.speak())


'''
1. You can use the code you already have in Animal
2. You can use Animal and cat interchageably

'''
a = Animal("Rex")
print(str(a))

c = Cat("Fluffy")
#1. search Cat.__str__ -> no dice 
#2. search Animal.__str__ -> exists, so it is called
print(str(c))
