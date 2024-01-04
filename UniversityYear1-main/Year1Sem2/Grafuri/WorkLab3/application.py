import copy
import random
# show edge cost
INFINITY = float("inf")

class Graph:
    
    #Init: number of edges and number of vertices( muchii si noduri)
    #I used 3 dictionaries: one for the the vedges that come  into vertices, one for the edges that go out from vertices and the price of an edge
    #
    #
    #
    def __init__(self, nr_vertices=0):# nr_vertices=number vertices
        self.edge_number = 0
        self.vertex_number = 0
        self.in_vertices = {}# first dict edges in vertix
        self.out_vertices = {}# second dict edges out the vertix
        self.price = {}# third dict price of the edges that connect 2 vertices 
        for vertex in range(nr_vertices):
            self.add_vertex(vertex)

    # we validate if and edge is well placed
    def valid_edge(self, x, y):
        if x in self.out_vertices and y in self.in_vertices and y in self.out_vertices[x] and x in self.in_vertices[y]:
            return True
        return False

   # Add edge: x and y are the vertices and price is the "cost" of the edge that is added 
   # The give edge will leave from the vertix x and will go into vertix y
    def add_edge(self, x, y, price):
        # self.out_vertices[vertex] <- iti spune care sunt nodurile conectate cu nodul "vertex" (outbound)
        if  x in self.out_vertices ==False or  y in self.in_vertices == False:
            raise Exception("Error Occured: The Vertices do not exist:")
        if  (y in self.out_vertices[x]) == False : # if the edge that leaves x is not connected to y yet then it will be connected 
            self.out_vertices[x].append(y) 
        if  (x in self.in_vertices[y]) == False: # if the edge that goes into y is not connected to x then it will be connected
            self.in_vertices[y].append(x)
        if  (y in self.price[x]) == False: # if it has no price then it will have 
            self.price[x][y] = price
        self.edge_number += 1

    
    def delete_edge(self, x, y):
        if  (x in self.out_vertices and y in self.in_vertices and y in self.out_vertices[x] and x in self.in_vertices[y])== False: 
            raise Exception("Error Occured: One of the vertices does not exist or the vertices are not connected!")
        self.out_vertices[x].remove(y) # removes the edge when the edge leaves the vertix x 
        self.in_vertices[y].remove(x) # removes the edge when the edge  goes into the vertix y
        del self.price[x][y]# the price of the vertices is deleted 
        self.edge_number -= 1

   
    

 
    def add_vertex(self, vertex):
        if vertex in self.out_vertices or vertex in self.in_vertices:
            raise Exception("Error Occured: Vertex exists!")
        self.out_vertices[vertex] = []# the list is empty( izolat)
        self.in_vertices[vertex] = []# the simple vertex(izolat)
        self.price[vertex] = {}
        self.vertex_number += 1

    
    def delete_vertex(self, vertex):
        if (vertex  in self.out_vertices )== False or (vertex  in self.in_vertices)== False:
            raise Exception("Error Occured: Vertex doesn't exist!")
        # the link with other vertices out if him 
        for out_link in self.out_vertices[vertex]:
            self.delete_edge(vertex, out_link) #simpler(deletes the connection)
        # the link wirh other vertices in him 
        for in_link in self.in_vertices[vertex]:
            self.delete_edge(in_link,vertex)
        del self.out_vertices[vertex] # I deleted the list for the vertix the user wants to delete
        del self.in_vertices[vertex]
        del self.price[vertex]
        self.vertex_number -= 1

    
    def get_in_degree_of_vertex(self, vertex): # degree of the edges that go in the vertex
        if (vertex in self.in_vertices)== False:
            raise Exception("Error Occured: The vertex doesn't exist!")
        return len(self.in_vertices[vertex])

  
    def get_out_degree_of_vertex(self, vertex): # degree of the edges that go out of the vertex
        if  (vertex in self.out_vertices)== False:
            raise Exception("Error Occured: The vertex doesn't exist!")
        return len(self.out_vertices[vertex]) # it returns the length of the vertex that go out of the vertices we want


    def get_out_vertices(self, vertex): # list of vertices that have a edge from the vertix as parameter
        if  (vertex in self.out_vertices)== False:
            raise Exception("Error Occured: The vertex doesn't exist!")
        return self.out_vertices[vertex][:]

   
    def get_in_vertices(self, vertex): # list of vertices that have a edge that goes into the vertex as parameter
        if  (vertex in self.in_vertices) ==False:
            raise Exception("Error Occured: The vertex doesn't exist!")
        return self.in_vertices[vertex][:]

    def get_vertices(self):  # list with all the vertices
        list__of_all_vertices = []
        for i in self.in_vertices.keys():
           list__of_all_vertices.append(i)
        return list__of_all_vertices

   
    def price_change(self, x, y, new_price): # change of the "cost"
        if (x in self.out_vertices and y in self.in_vertices and y in self.out_vertices[x]) == False:
            raise Exception("Error Occured: The vertices don't exist or aren't connected together!")
        self.price[x][y] = new_price

# UI implementations!!!
def read_graph_from_file(): # if we have a pragh in the file we enter the file name in the console and it will give read  the graph from the file
    name_of_the_file = input("Filename: ")
    file_open = open(name_of_the_file, "r")
    line_read_from_file = file_open.readline()
    line_read_from_file= line_read_from_file.split()
    vertex_number = int(line_read_from_file[0])
    edge_number = int(line_read_from_file[1])
    new_graph = Graph(vertex_number)
    line_read_from_file = file_open.readline()
    while len(line_read_from_file) > 0:
        line_read_from_file = line_read_from_file.split()
        x = int(line_read_from_file[0])
        y = int(line_read_from_file[1])
        price = int(line_read_from_file[2])
        new_graph.add_edge(x, y, price)
        line_read_from_file = file_open.readline()
    file_open.close()
    return new_graph

def display_number_of_vertices(my_graph): # display the number of vertice of our graph
    print("The graph has " + str(my_graph.vertex_number) + " vertices")

def valid_edge(my_graph):
    x = int(input("x = "))
    y = int(input("y = "))
    if my_graph.valid_edge(x, y) == True:
        print("There exists the ({0}, {1})={2} edge".format(x, y, my_graph.price[x][y]))
    else:
        print("Error Occured:There doesn't exist an edge from {0} to {1} ".format(x, y))

def get_in_degree(my_graph):
    vertex =int(input("Vertex: "))
    print("The vertex {0} has an indegree of {1}".format(vertex,my_graph.get_in_degree_of_vertex(vertex)))

def get_out_degree(my_graph):
    vertex = int(input("Vertex: "))
    print("The vertex {0} has an outdegree of {1}".format(vertex,my_graph.get_out_degree_of_vertex(vertex))) 

def print_vertices(my_graph):
    vertices = my_graph.get_vertices()
    print_str = ""
    for vertex in vertices:
        print_str += "{0} ".format(vertex)
    print(print_str)

def print_vertices_out(my_graph):
    vertex = int(input("Vertex: "))
    print_str = ""
    vertices = my_graph.get_out_vertices(vertex)
    for vertex in vertices:
        print_str += "{0} ".format(vertex)
    print(print_str)

def print_vertices_in(my_graph):
    vertex = int(input("Vertex: "))
    print_str= ""
    vertices = my_graph.get_in_vertices(vertex)
    for vertex in vertices:
        print_str += "{0} ".format(vertex)
    print(print_str)

def price_change(my_graph):
    x = int(input("x = "))
    y = int(input("y = "))
    price = int(input("New price is = "))
    my_graph.price_change(x, y, price)

def add_edge(my_graph):
    x = int(input("x = "))
    y = int(input("y = "))
    price = int(input("New price is = "))
    my_graph.add_edge(x, y, price)

def add_vertex(my_graph):
    vertex = int(input("vertex: "))
    my_graph.add_vertex(vertex)

def delete_vertex(my_graph):
    vertex = int(input("vertex: "))
    my_graph.delete_vertex(vertex)

def delete_edge(my_graph):
    x = int(input("x = "))
    y = int(input("y = "))
    my_graph.delete_edge(x, y)


def file_graph_saver(my_graph):
    name_of_the_file = input("Filename: ")
    file_open = open(name_of_the_file, "w")
    file_open.write("{0} {1}\n".format(my_graph.vertex_number, my_graph.edge_number))
    for x in my_graph.price.keys():
        for y in my_graph.price[x].keys():
            file_open.write("{0} {1} {2}\n".format(x, y, my_graph.price[x][y]))
    file_open.close()

def copy_graph(new_graph, my_graph):
    new_graph.vertex_number = my_graph.vertex_number
    new_graph.edge_number = my_graph.edge_number
    new_graph.in_vertices = copy.deepcopy(my_graph.in_vertices)
    new_graph.out_vertices = copy.deepcopy(my_graph.out_vertices)
    new_graph.price = copy.deepcopy(my_graph.price)

def produce_graph_random():
    vertex_number = int(input("Vertex count: "))
    edge_number = int(input("Edge count: "))
    random_graph = Graph(vertex_number)
    while edge_number != 0:
        x = random.randint(0, vertex_number - 1)
        y = random.randint(0, vertex_number - 1)
        if random_graph.valid_edge(x, y) == False:
            random_graph.add_edge(x, y, random.randint(0,1000))
            edge_number -= 1
    return random_graph


    #EXERCISE 1

def Dijkstra(graph, source):
    distance = {}
    previous = {}
    queue = []
    distance[source] = 0
    for vertex in graph.get_vertices():
        if vertex != source:
            distance[vertex] = INFINITY
            previous[vertex] = None
        queue.append(vertex)
    while queue:
        vertex = min(queue, key=lambda a: distance[a])
        queue.remove(vertex)
        for neighbor in graph.get_out_vertices(vertex):
            if neighbor in queue:
                Newdistance = distance[vertex] + graph.price[vertex][neighbor]
                if Newdistance < distance[neighbor]:
                    distance[neighbor] = Newdistance
                    previous[neighbor] = vertex
    return distance, previous


def GetPath(previous, source, target):
    path = []
    while target != source:
        path.append(target)
        target = previous[target]
    path.append(target)
    path.reverse()
    return path


def Getdistance(SomeGraph):
    x = int(input("x = "))
    y = int(input("y = "))
    distances, previous = Dijkstra(SomeGraph, x)
    if distances[y] == INFINITY:
        print("There's no path from {0} to {1}.".format(x, y))
    else:
        print("The walk cost from {0} to {1} is {2}".format(x, y, distances[y]))
        path = GetPath(previous, x, y)
        print(path)


def display_menu():
    print("Menu:\n")
    print("1. Add a vertex")
    print("2. Add an edge")
    print("3. Delete a vertex")
    print("4. Delete an edge")
    print("5. Verify edge")
    print("6. Display the number of vertices")
    print("7. Display Indegree of vertex")
    print("8. Display Outdegree of vertex")
    print("9. Display all vertices")
    print("10. Display all vertices outbound of a given vertex")
    print("11. Display all vertices inbound of a given vertex")
    print("12. Change price of edge")
    print("13. Copy graph")
    print("14. Save graph to file")# it can without creating the file
    print("15. Read graph from a new created file")
    print("16. Create a random graph")
    print("17. Minimum distance between 2 vertices")
    print("0. Exit")


def start_function():
    new_graph = Graph()
    while True:
        display_menu()
        input_user = input("Enter a number: ")
        try:
            if input_user == "1":
                add_vertex(new_graph)
            elif input_user == "2":
                add_edge(new_graph) 
            elif input_user == "3":
                delete_vertex(new_graph) 
            elif input_user == "4":
                delete_edge(new_graph) 
            elif input_user == "5":
                valid_edge(new_graph)  
            elif input_user == "6":
                display_number_of_vertices(new_graph) 
            elif input_user == "7":
                get_in_degree(new_graph)
            elif input_user == "8":
                get_out_degree(new_graph)
            elif input_user == "9":
                print_vertices(new_graph)
            elif input_user == "10":
                print_vertices_out(new_graph)  
            elif input_user == "11":
                print_vertices_in(new_graph)  
            elif input_user == "12":
                price_change(new_graph)  
            elif input_user == "13":
                CopyG = Graph()
                copy_graph(CopyG, new_graph)
            elif input_user == "14":
                file_graph_saver(new_graph)  
            elif input_user == "15":
                new_graph = read_graph_from_file()  
            elif input_user == "16":
                new_graph = produce_graph_random()  
            elif input_user == "17":
                Getdistance(new_graph)
            elif input_user == "0":
                break
        except Exception as ex:
            print(ex)

start_function()
