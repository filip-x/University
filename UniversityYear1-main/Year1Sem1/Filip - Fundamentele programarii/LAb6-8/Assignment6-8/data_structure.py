
class List_collector:

    def __init__(self):
        self._list = []
        self._var=0

    def __setitem__(self,index,value):
        self._list[index] = value
    
    def __getitem__(self,index):
        return self._list[index]


    def __delitem__(self,index):
        self._list.pop(index)

    def __iter__(self):
        self._var=0
        return self
    
    def __next__(self):
        
        if self._var >= len(self._list):
            raise StopIteration
        
        var2=self._list[self._var]
        self._var = self._var +1
        
        return var2

    def append(self,value):
        self._list.append(value)
    
    def __len__(self):
        return len(self._list)


    def gnomeSort(self,compare): # compare is a function that decides  the data type and if the 2 params should be swapped
        pos =0
        while pos <len(self._list):
            if pos == 0 or compare(self._list[pos],self._list[pos-1]):
                pos = pos +1
            else:
                self._list[pos],self._list[pos-1] =self._list[pos-1],self._list[pos]
                pos = pos -1

    def filter(self,compare):
        new_list=[]
        for i in range(len(self._list)):
            if compare(self._list[i]) == True:
                new_list.append(self._list[i])
        return new_list

    
