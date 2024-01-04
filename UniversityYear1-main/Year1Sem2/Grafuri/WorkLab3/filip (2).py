import copy
import random
# show edge cost
INFINITY = float("inf")
class Graph:
    # The graph is represented internally as 3 dictionaries:
    # For each vertex we store all outbound vertices connected to it
    # For each vertex we store all inbound vertices connected to it
    # For each edge we store the cost
    def __init__(self, VC = 0):
        self.VertexCount = 0
        self.EdgeCount = 0
        self.Outbound = {}
        self.Inbound = {}
        self.Costs = {}
        for vertex in range(VC):
            self.AddVertex(vertex)
        
    # Function to add an edge:
    # Input: Vertices to add an edge to; The cost of the edge
    # Output: -
    # Effect: Adds an edge
    # Exceptions: If one of the vertices doesn't exist
    def AddEdge(self, x, y, cost):
        if not x in self.Outbound or not y in self.Inbound:
            raise Exception("One of the vertices doesn't exist!")
        if not y in self.Outbound[x]:
            self.Outbound[x].append(y)
        if not x in self.Inbound[y]:
            self.Inbound[y].append(x)
        if not y in self.Costs[x]:
            self.Costs[x][y] = cost
        self.EdgeCount += 1
    
    # Function to remove an edge:
    # Input: Vertices from which to remove the edge
    # Output: -
    # Effect: Removes an edge
    # Exceptions: If one of the vertices doesn't exist, or there doesn't exist an edge between them
    def DeleteEdge(self, x, y):
        if not (x in self.Outbound and y in self.Inbound and y in self.Outbound[x] and x in self.Inbound[y]):
            raise Exception("One of the vertices doesn't exist or the vertices aren't connected!")
        self.Outbound[x].remove(y)
        self.Inbound[y].remove(x)
        del self.Costs[x][y]
        self.EdgeCount -= 1
    
    # Function to check if an edge exists
    # Input: Vertices from which the edge is connected
    # Output: Boolean whether the edge exists
    # Effect: -
    # Exceptions: -
    def CheckEdge(self, x, y):
        if x in self.Outbound and y in self.Inbound and y in self.Outbound[x] and x in self.Inbound[y]:
            return True
        return False

    # Function to get the cost of an edge
    # Input: Vertices from which the edge is connected
    # Output : Integer representing the cost
    # Effect : -
    # Exceptions : If the edge does't exist
    def GetEdgeCost(self, x, y):
        if x in self.Outbound and y in self.Inbound and y in self.Outbound[x] and x in self.Inbound[y]:
            return self.Costs[x][y]
        else:
            raise Exception("There's no edge between the vertices.")
    
    # Function to add a vertex
    # Input: the vertex
    # Output: -
    # Effect: Adds a vertex
    # Exceptions: If the vertex already exists
    def AddVertex(self, vertex):
        if vertex in self.Outbound or vertex in self.Inbound:
            raise Exception("Vertex already exists!")
        self.Outbound[vertex] = []
        self.Inbound[vertex] = []
        self.Costs[vertex] = {}
        self.VertexCount += 1
    
    # Function to add a vertex
    # Input: the vertex
    # Output: -
    # Effect: - Removes a vertex and all edges that are dependent on it
    # Exceptions: If the vertex doesn't exist
    def DeleteVertex(self, vertex):
        if vertex not in self.Outbound or vertex not in self.Inbound:
            raise Exception("Vertex doesn't exist!")
        for OutNeighbor in self.Outbound[vertex]:
            self.Inbound[OutNeighbor].remove(vertex)
            del self.Costs[vertex][OutNeighbor]
            self.EdgeCount -= 1

        for InNeighbor in self.Inbound[vertex]:
            self.Outbound[InNeighbor].remove(vertex)
            del self.Costs[InNeighbor][vertex]
            self.EdgeCount -= 1
        del self.Outbound[vertex]
        del self.Inbound[vertex]
        del self.Costs[vertex]
        self.VertexCount -= 1
    
    # Function to get the indegree
    # Input: Targeted vertex
    # Output: Number of vertices that are inbound of the target vertex
    # Effect: -
    # Exceptions: If the vertex doesn't exist
    def GetIndegree(self, vertex):
        if not vertex in self.Inbound:
            raise Exception("The vertex doesn't exist!")
        return len(self.Inbound[vertex])
    
    # Function to get the outdegree
    # Input: Targeted vertex
    # Output: Number of vertices that are outbound of the target vertex
    # Effect: -
    # Exceptions: If the vertex doesn't exist
    def GetOutdegree(self, vertex):
        if not vertex in self.Outbound:
            raise Exception("The vertex doesn't exist!")
        return len(self.Outbound[vertex])
    
    # Function to get the vertices
    # Input: -
    # Output: Iterable list containing all vertices
    # Effect: -
    # Exceptions: -
    def GetVertices(self):
        return list(self.Outbound.keys())[:]
    
    # Function to get the outbound vertices
    # Input: target vertex
    # Output: Iterable list containing all vertices outbound of the target vertex
    # Effect: -
    # Exceptions: If the vertex doesn't exist
    def GetOutboundVertices(self, vertex):
        if not vertex in self.Outbound:
            raise Exception("The vertex doesn't exist!")
        return self.Outbound[vertex][:]
    
    # Function to get the inbound vertices
    # Input: target vertex
    # Output: Iterable list containing all vertices inbound of the target vertex
    # Effect: -
    # Exceptions: If the vertex doesn't exist
    def GetInboundVertices(self, vertex):
        if not vertex in self.Inbound:
            raise Exception("The vertex doesn't exist!")
        return self.Inbound[vertex][:]
    
    # Function to change the cost associtated to an edge
    # Input: the vertices which form the edge; the new cost
    # Output: -
    # Effect: Changes the cost associated with the edge formed by the input vertices
    # Exceptions: If the vertices don't exist or aren't connected together
    def ChangeCost(self, x, y, NewCost):
        if not (x in self.Outbound and y in self.Inbound and y in self.Outbound[x]):
            raise Exception("The vertices don't exist or aren't connected together!")
        self.Costs[x][y] = NewCost
    
def ReadGraph():
    FileName = input("Filename: ")
    File = open(FileName, "r")
    Line = File.readline()
    VertexCount = 0
    EdgeCount = 0
    EdgeCount += 0 # so we get rid of the warning
    Line = Line.split()
    VertexCount = int(Line[0])
    EdgeCount = int(Line[1])
    G = Graph(VertexCount)
    Line = File.readline()
    while len(Line) > 0:
        Line = Line.split()
        X = int(Line[0])
        Y = int(Line[1])
        Cost = int(Line[2])
        G.AddEdge(X, Y, Cost)    
        Line = File.readline()
    File.close()
    return G

def PrintVertexCount(SomeGraph):
    print("The graph contains " + str(SomeGraph.VertexCount) + " vertices")

def CheckEdge(SomeGraph):
    X = int(input("x = "))
    Y = int(input("y = "))
    if SomeGraph.CheckEdge(X, Y) == True:
        print("There exists the ({0}, {1}) edge and it's cost is {2}".format(X, Y, SomeGraph.GetEdgeCost(X, Y)))
    else:
        print("There doesn't exist an edge from {0} to {1} ".format(X, Y))

def GetIndegree(SomeGraph):
    Vertex = int(input("Vertex: "))
    print("The vertex {0} has an indegree of {1}".format(Vertex, SomeGraph.GetIndegree(Vertex)))

def GetOutdegree(SomeGraph):
    Vertex = int(input("Vertex: "))
    print("The vertex {0} has an outdegree of {1}".format(Vertex, SomeGraph.GetOutdegree(Vertex)))

def GetVertices(SomeGraph):
    Vertices = SomeGraph.GetVertices()
    String = ""
    for Vertex in Vertices:
        String += "{0} ".format(Vertex)
    print(String)

def VerticesOutbound(SomeGraph):
    Vertex = int(input("Vertex: "))
    String = ""
    Vertices = SomeGraph.GetOutboundVertices(Vertex)
    for Vertex in Vertices:
        String += "{0} ".format(Vertex)
    print(String)

def VerticesInbound(SomeGraph):
    Vertex = int(input("Vertex: "))
    String = ""
    Vertices = SomeGraph.GetInboundVertices(Vertex)
    for Vertex in Vertices:
        String += "{0} ".format(Vertex)
    print(String)

def ChangeCost(SomeGraph):
    X = int(input("x = "))
    Y = int(input("y = "))
    Cost = int(input("New cost = "))
    SomeGraph.ChangeCost(X, Y, Cost)

def AddEdge(SomeGraph):
    X = int(input("x = "))
    Y = int(input("y = "))
    Cost = int(input("New cost = "))
    SomeGraph.AddEdge(X, Y, Cost)

def AddVertex(SomeGraph):
    Vertex = int(input("vertex: "))
    SomeGraph.AddVertex(Vertex)

def DeleteVertex(SomeGraph):
    Vertex = int(input("vertex: "))
    SomeGraph.DeleteVertex(Vertex)

def DeleteEdge(SomeGraph):
    X = int(input("x = "))
    Y = int(input("y = "))
    SomeGraph.DeleteEdge(X, Y)

def SaveGraph(SomeGraph):
    FileName = input("Filename: ")
    File = open(FileName, "w")
    File.write("{0} {1}\n".format(SomeGraph.VertexCount, SomeGraph.EdgeCount))
    for A in SomeGraph.Costs.keys():
        for B in SomeGraph.Costs[A].keys():
            File.write("{0} {1} {2}\n".format(A, B, SomeGraph.Costs[A][B]))
    File.close()

def CopyGraph(NewGraph, SomeGraph):
    NewGraph.VertexCount = SomeGraph.VertexCount
    NewGraph.EdgeCount = SomeGraph.EdgeCount
    NewGraph.Inbound = copy.deepcopy(SomeGraph.Inbound)
    NewGraph.Outbound = copy.deepcopy(SomeGraph.Outbound)
    NewGraph.Costs = copy.deepcopy(SomeGraph.Costs)
    print("Copy was made succesfully!")

def GenerateGraph():
    VertexCount = int(input("Vertex count: "))
    EdgeCount = int(input("Edge count: "))
    RandomGraph = Graph(VertexCount)
    if EdgeCount > VertexCount*VertexCount:
        EdgeCount = VertexCount*VertexCount
    while EdgeCount != 0:
        x = random.randint(0, VertexCount - 1)
        y = random.randint(0, VertexCount - 1)
        if RandomGraph.CheckEdge(x, y) == False:
            RandomGraph.AddEdge(x, y, random.randint(-100, 100))
            EdgeCount -= 1
    return RandomGraph

# Exercise 1

def Dijkstra(Graph, Source):
    Distance = {}
    Previous = {}
    Queue = []
    Distance[Source] = 0
    for Vertex in Graph.GetVertices():
        if Vertex != Source:
            Distance[Vertex] = INFINITY
            Previous[Vertex] = None
        Queue.append(Vertex)
    while Queue:
        Vertex = min(Queue, key=lambda a: Distance[a])
        Queue.remove(Vertex)
        for Neighbor in Graph.GetOutboundVertices(Vertex):
            if Neighbor in Queue:
                NewDistance = Distance[Vertex] + Graph.GetEdgeCost(Vertex, Neighbor)
                if NewDistance < Distance[Neighbor]:
                    Distance[Neighbor] = NewDistance
                    Previous[Neighbor] = Vertex
    return Distance, Previous

def GetPath(Previous, Source, Target):
    Path = []
    while Target != Source:
        Path.append(Target)
        Target = Previous[Target]
    Path.append(Target)
    Path.reverse()
    return Path


def GetDistance(SomeGraph):
    x = int(input("x = "))
    y = int(input("y = "))
    Distances, Previous = Dijkstra(SomeGraph, x)
    if Distances[y] == INFINITY:
        print("There's no path from {0} to {1}.".format(x, y))
    else:
        print("The walk cost from {0} to {1} is {2}".format(x, y, Distances[y]))
        Path = GetPath(Previous, x, y)
        print(Path)



def ShowMenu():
    print("\n== Main Menu ==\n")
    print("1. Read graph from file")
    print("2. Print the number of vertices")
    print("3. Check edge")
    print("4. Indegree of vertex")
    print("5. Outdegree of vertex")
    print("6. Print all vertices")
    print("7. Print all vertices outbound of a given vertex")
    print("8. Print all vertices inbound of a given vertex")
    print("9. Change cost of edge")
    print("10. Add a vertex")
    print("11. Add an edge")
    print("12. Copy graph")
    print("13. Save graph to file")
    print("14. Create a random graph")
    print("15. Delete a vertex")
    print("16. Delete an edge")
    print("17. Minimum distance between 2 vertices")
    print("0. Exit")

if __name__ == "__main__":
    NewGraph = 0
    while True:
        ShowMenu()
        Input = input("> ")
        try:
            if Input == "1":
                NewGraph = ReadGraph()
            elif Input == "2":
                PrintVertexCount(NewGraph)
            elif Input == "3":
                CheckEdge(NewGraph)
            elif Input == "4":
                GetIndegree(NewGraph)
            elif Input == "5":
                GetOutdegree(NewGraph)
            elif Input == "6":
                GetVertices(NewGraph)
            elif Input == "7":
                VerticesOutbound(NewGraph)
            elif Input == "8":
                VerticesInbound(NewGraph)
            elif Input == "9":
                ChangeCost(NewGraph)
            elif Input == "10":
                AddVertex(NewGraph)
            elif Input == "11":
                AddEdge(NewGraph)
            elif Input == "12":
                CopyG = Graph()
                CopyGraph(CopyG, NewGraph)
            elif Input == "13":
                SaveGraph(NewGraph)
            elif Input == "14":
                NewGraph = GenerateGraph()
            elif Input == "15":
                DeleteVertex(NewGraph)
            elif Input == "16":
                DeleteEdge(NewGraph)
            elif Input == "17":
                GetDistance(NewGraph)
            elif Input == "0":
                break
        except Exception as Error:
            print(Error)