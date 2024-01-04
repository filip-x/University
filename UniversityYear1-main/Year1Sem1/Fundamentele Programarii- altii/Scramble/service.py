import random
from repo import Repo

class Service:
    def __init__(self):
        self.sentance=[]
        self.words =Repo()

    def read_file(self):
        try:
            f = open("file.txt","r")
            text_file=f.readline()
            while text_file != "":
                self.sentance.append(text_file)
                text_file=f.readline()
            r = random.randint(0,len(self.sentance)-1)
            final_prop=self.sentance[r]
            return final_prop

            f.close()
        except Exception as es:
            print(es)

    def scrumble_the_prop(self):
        lista=[]
        litere=[]
        prop=self.read_file()
        lista = prop.split()
        for i in range(len(lista)):
            for j in range( 1 ,len(lista[i])-1):
                litere.append(lista[i][j])
        nr =len(litere)+2*(len(lista))
        for i in range(len(lista)):
            screm=lista[i][0]
            l=len(lista[i])
            for _ in range(l-2):
                r= random.randint(0,len(litere)-1)
                screm=screm+ litere.pop(r)
            screm= screm + lista[i][-1]
            lista[i]=screm
        for i in range(len(lista)):
            self.words.setter(lista[i])
        return nr

        