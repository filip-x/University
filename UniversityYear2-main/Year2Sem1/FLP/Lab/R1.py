# 1 problema. Substitute the i-th element from a list,
# with a value v

class node:
    def __init__(self,value):
        self.value = value
        self.next_node = None


    def set_next(self,next_node):
        self.next_node = next_node

    def get_next(self):
        return self.next_node
    
    def get_value(self):
        return self.value

    def set_value(self,value):
        self.value = value

    
def from_list_to_linked_list(list1):
    if len(list1) == 0:
        return None
    start = node(list1[0]) # first element
    next_element = start
    for i in range(1,len(list1)):
        next_element.set_next(node(list1[i]))
        next_element =next_element.get_next()
    return start
    
    
def display_linked_list(linked_list):
    start = linked_list
    while start != None:
        print(start.get_value())
        start = start.get_next()

def subst(my_list_linked,v,i):
    if my_list_linked == None:
        return None
    if i == 1:
        start= node(v)
        start.set_next(my_list_linked.get_next())
        return start
    if i > 1:
        start = node(my_list_linked.get_value())
        start.set_next(subst(my_list_linked.get_next(),v,i-1))
        return start
        
    return my_list_linked



def main():
    #pb1
    my_list=[1,2,3,4]
    linked_list = from_list_to_linked_list(my_list)
    #display_linked_list(linked_list)
    v=0
    i=3
    display_linked_list(subst(linked_list,v,i))
    #####################
    #pb2
    print("\n")

    list1=[1,2,3,4,5,6,7]
    list2=[2,3,4,5,6]
    linked_list1 = from_list_to_linked_list(list1)
    linked_list2 = from_list_to_linked_list(list2)
    display_linked_list(diff(linked_list1,linked_list2))


    


#2 problem. Determine difference of two sets represented as lists.
def diff(linked_list1,linked_list2):
    if linked_list1 == None and linked_list2 == None:
        return None
    if linked_list1 == None and linked_list2 !=None:
        return None
    if linked_list1 !=None and linked_list2 == None:
        return linked_list1
    if linked_list1 !=None and linked_list2 !=None:
        if (nr_in_list(linked_list1.get_value(),linked_list2)) == 0:
            start = node(linked_list1.get_value())#linked_list[0]
            start.set_next(diff(linked_list1.get_next(),linked_list2))
            return start
        else:
            return diff(linked_list1.get_next(),linked_list2)
           



def nr_in_list(nr,linked_list_to_travel):#here we travel the 2nd 
    if linked_list_to_travel == None:
        return 0
    if nr ==linked_list_to_travel.get_value():
        return 1  
    return nr_in_list(nr,linked_list_to_travel.get_next())


main()