import copy
import random
# show edge cost


class Graph:
    
    #Init: number of edges and number of vertices( muchii si noduri)
    #I used 3 dictionaries: one for the the vedges that come  into vertices, one for the edges that go out from vertices and the price of an edge
    #
    #
    #
    def __init__(self, nr_vertices=0):# nr_vertices=number vertices
        self.edge_number = 0
        self.vertex_number = 0
        self.price = {}# third dict price of the edges that connect 2 vertices 
        for vertex in range(nr_vertices):
            self.add_vertex(vertex)

    # we validate if and edge is well placed
    def valid_edge(self, x, y):
        if x in self.price and y in self.price and y in self.price[x] and x in self.price[y]:
            return True
        return False

   # Add edge: x and y are the vertices and price is the "cost" of the edge that is added 
   # The give edge will leave from the vertix x and will go into vertix y
    def add_edge(self, x, y, price):
        # self.out_vertices[vertex] <- iti spune care sunt nodurile conectate cu nodul "vertex" (outbound)
        if  x in self.price ==False or  y in self.price== False or x == y:
            raise Exception("Error Occured: The Vertices do not exist:")
        if  (y in self.price[x]) == False : # if it has no price then it will have 
            self.price[x][y] = price
            self.price[y][x] = price
            self.edge_number += 1

    
    def delete_edge(self, x, y):
        if  (x in self.price and y in self.price and y in self.price[x] and x in self.price[y])== False: 
            raise Exception("Error Occured: One of the vertices does not exist or the vertices are not connected!")
        del self.price[x][y]# the price of the vertices is deleted 
        del self.price[y][x]
        self.edge_number -= 1

   
    

 
    def add_vertex(self, vertex):
        if vertex in self.price :
            raise Exception("Error Occured: Vertex exists!")
        self.price[vertex] = {}
        self.vertex_number += 1

    
    def delete_vertex(self, vertex):
        if (vertex  in self.price)== False:
            raise Exception("Error Occured: Vertex doesn't exist!")
        # the link with other vertices out if him 
        vertices = self.get_vertices_connected(vertex)
        for out_link in vertices:# out_link is from lab1
            self.delete_edge(vertex, out_link) #simpler(deletes the connection)
        # the link wirh other vertices in him 
        del self.price[vertex]
        self.vertex_number -= 1

    
    
  
    def get_degree_of_vertex(self, vertex): # degree of the edges that go out of the vertex
        if  (vertex in self.price)== False:
            raise Exception("Error Occured: The vertex doesn't exist!")
        return len(list(self.price[vertex].keys())) # it returns the length of the vertex that go out of the vertices we want


    def get_vertices_connected(self, vertex): # list of vertices that have a edge from the vertix as parameter
        if  (vertex in self.price)== False:
            raise Exception("Error Occured: The vertex doesn't exist!")
        return list(self.price[vertex].keys())[:]

    def get_vertices(self):  # list with all the vertices
        return list(self.price.keys())

    def price_change(self, x, y, new_price): # change of the "cost"
        if (x in self.price and y in self.price and y in self.price[x] and x in self.price[y]) == False:
            raise Exception("Error Occured: The vertices don't exist or aren't connected together!")
        self.price[x][y] = new_price
        self.price[y][x] = new_price

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


def get_degree(my_graph):
    vertex = int(input("Vertex: "))
    print("The vertex {0} has an degree of {1}".format(vertex,my_graph.get_degree_of_vertex(vertex))) 

def print_vertices(my_graph):
    vertices = my_graph.get_vertices()
    print_str = ""
    for vertex in vertices:
        print_str += "{0} ".format(vertex)
    print(print_str)



def print_vertices_connected(my_graph):
    vertex = int(input("Vertex: "))
    print_str= ""
    vertices = my_graph.get_vertices_connected(vertex)
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
            if x<=y:
                file_open.write("{0} {1} {2}\n".format(x, y, my_graph.price[x][y]))
    file_open.close()

def copy_graph(new_graph, my_graph):
    new_graph.vertex_number = my_graph.vertex_number
    new_graph.edge_number = my_graph.edge_number
    new_graph.price = copy.deepcopy(my_graph.price)

def produce_graph_random():
    vertex_number = int(input("Vertex count: "))
    edge_number = int(input("Edge count: "))
    random_graph = Graph(vertex_number)
    while edge_number != 0:
        x = random.randint(0, vertex_number - 1)
        y = random.randint(0, vertex_number - 1)
        if random_graph.valid_edge(x, y) == False and x !=y:
            random_graph.add_edge(x, y, random.randint(0,1000))
            edge_number -= 1
    return random_graph

def display_components(my_graph):
    component = find_components(my_graph)
    for i in range(len(component)):
        print("Component"+ str(component[i].get_vertices()))

def find_components(my_graph):
    component_list = []
    vertices = my_graph.get_vertices()
    while len(vertices)> 0:
        component = depth_first_search(my_graph,vertices[0])
        component_list.append(component)
        for v in component.get_vertices():
            vertices.remove(v)
    return component_list


def depth_first_search(my_graph,vertex,component = None):
    if component == None:
        component = Graph()
    component.add_vertex(vertex)
    vertex_connected = my_graph.get_vertices_connected(vertex)
    for v in vertex_connected:
        if v not in component.get_vertices():
            component = depth_first_search(my_graph,v,component)
    return component

#WORKLAB4 -BONUS-1
#===============================================================

class BinaryTree:
    def __init__(self, root):
        self.left_child = None
        self.right_child = None
        self.root = root
#bonus1


def build_tree_pre(inorder, preorder, inorderstart, inorderend):
    if inorderstart > inorderend:
        return None
    # Pick current node from Preorder traversal using preIndex and increment preIndex
    node = BinaryTree(preorder.pop(0))
    # If this node has no children then return
    if inorderstart == inorderend:
        return node
    # Else find the index of this node in Inorder traversal
    inorderindex = inorder.index(node.root)
    # Using index in Inorder traversal, construct left and right subtrees
    node.left_child = build_tree_pre(
        inorder, preorder, inorderstart, inorderindex - 1)
    node.right_child = build_tree_pre(
        inorder, preorder, inorderindex + 1, inorderend)
    return node


def build_tree_post(inorder, postorder, inorderstart, inorderend):
    if inorderstart > inorderend:
        return None
    # Pick current node from Preorder traversal
    node = BinaryTree(postorder.pop())
    # If this node has no children then return
    if inorderstart == inorderend:
        return node
    # Else find the index of this node in Inorder traversal
    inorderindex = inorder.index(node.root)
    # Using index in Inorder traversal, construct left and right subtrees
    node.right_child = build_tree_post(
        inorder, postorder, inorderindex + 1, inorderend)
    node.left_child = build_tree_post(
        inorder, postorder, inorderstart, inorderindex - 1)
    return node


def build_tree_pre_post(preorder, postorder, left, right):
    # Base case
    if len(preorder) == 0 or left > right:
        return None
    # The first node in preorder traversal is root. So take the node at first from preorder and make it root, and remove it from preorder
    node = BinaryTree(preorder.pop(0))
    # If the current subarry has only one element, no need to recur
    if left == right:
        return node
    # Search the next element of preorder in postorder
    next_index = right + 1
    if preorder:
        next_index = postorder.index(preorder[0])
    # Use the index of element found in postorder to divide postorder array in two parts. Left subtree and right subtree
    if next_index <= right:
        node.left_child = build_tree_pre_post(preorder, postorder, left, next_index)
        node.right_child = build_tree_pre_post(
            preorder, postorder, next_index + 1, right)
    return node


def display_tree(tree, Level=0):
    tab_string = ""
    for _ in range(Level):
        tab_string += "- "
    print(tab_string, tree.root)
    if tree.left_child:
        display_tree(tree.left_child, Level + 1)
    if tree.right_child:
        display_tree(tree.right_child, Level + 1)
    #BONU-1-DISPLAY
def tree_from_in_pre():
    print("The files must contain the traversals on the first line, separated by spaces.")
    inorderfile = input("File Inorder: ")
    preorderfile = input("File Preorder: ")
    file = open(inorderfile)
    line = file.readline()
    inorder = line.split()
    file = open(preorderfile)
    line = file.readline()
    preorder = line.split()
    tree = build_tree_pre(inorder, preorder, 0, len(preorder) - 1)
    display_tree(tree)

def tree_from_in_post():
    print("The files must contain the traversals on the first line, separated by spaces.")
    inorderfile = input("File Inorder: ")
    postorderfile = input("File Postorder: ")
    file = open(inorderfile)
    Line = file.readline()
    inorder = Line.split()
    file = open(postorderfile)
    line = file.readline()
    postorder = line.split()
    tree = build_tree_post(inorder, postorder, 0, len(postorder) - 1)
    display_tree(tree)


def tree_from_pre_post():
    print("The files must contain the traversals on the first line, separated by spaces.")
    print("The input binary tree must be complete.")
    preorderfile = input("File Preorder: ")
    postorderfile = input("File Postorder: ")
    file = open(preorderfile)
    line = file.readline()
    preorder = line.split()
    file = open(postorderfile)
    line = file.readline()
    postorder = line.split()
    tree = build_tree_pre_post(preorder, postorder, 0, len(postorder) - 1)
    display_tree(tree)
#=================================================
def display_menu():
    print("Menu:\n")
    print("1. Add a vertex")
    print("2. Add an edge")
    print("3. Delete a vertex")
    print("4. Delete an edge")
    print("5. Verify edge")
    print("6. Display the number of vertices")
    print("7. Display degree of vertex")
    print("8. Display all vertices")
    print("9. Display all vertices connected with a given vertex")
    print("10. Change price of edge")
    print("11. Copy graph")
    print("12. Save graph to file")# it can without creating the file
    print("13. Read graph from a new created file")
    print("14. Create a random graph")
    print("15.Depth first search")
    print("16. Tree from inorder and preorder")
    print("17. Tree from inorder and postorder")
    print("18. Tree from preorder and postorder")
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
                get_degree(new_graph)
            elif input_user == "8":
                print_vertices(new_graph)
            elif input_user == "9":
                print_vertices_connected(new_graph)  
            elif input_user == "10":
                price_change(new_graph)  
            elif input_user == "11":
                CopyG = Graph()
                copy_graph(CopyG, new_graph)
            elif input_user == "12":
                file_graph_saver(new_graph)  
            elif input_user == "13":
                new_graph = read_graph_from_file()  
            elif input_user == "14":
                new_graph = produce_graph_random()  
            elif input_user == "15":
                display_components(new_graph)
            elif input_user == "16":
                tree_from_in_pre()
            elif input_user == "17":
                tree_from_in_post()
            elif input_user == "18":
                tree_from_pre_post()
            elif input_user == "0":
                break
        except Exception as ex:
            print(ex)

start_function()
