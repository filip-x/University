import random


class MatrGraph:
	"""A directed graph, represented by adjacency matrix.
	Vertices are numbers from 0 to n-1"""

	def __init__(self, n):
		"""Creates a graph with n vertices (numbered from 0 to n-1)
		and no edges"""
		self._matr = []
		for i in range(n):
			self._matr.append([])
			for j in range(n):
				self._matr[i].append(False)

	def parseX(self):
		"""Returns an iterable containing all the vertices"""
		nrOfVertices = len(self._matr)
		return range(nrOfVertices)

	def parseNout(self, x):
		"""Returns an iterable containing the outbound neighbours of x"""
		list = []
		for i in range(len(self._matr[x])):
			if self._matr[x][i]:
				list.append(i)
		return list

	def parseNin(self, x):
		"""Returns an iterable containing the inbound neighbours of x"""
		list = []
		for i in range(len(self._matr)):
			if self._matr[i][x]:
				list.append(i)
		return list

	def isEdge(self, x, y):
		"""Returns True if there is an edge from x to y, False otherwise"""
		return self._matr[x][y]

	def addEdge(self, x, y):
		"""Adds an edge from x to y.
		Precondition: there is no edge from x to y"""
		self._matr[x][y] = True


class DictGraph:
	"""A directed graph, represented as a map from each vertex to
	the set of outbound neighbours"""

	def __init__(self, n):
		"""Creates a graph with n vertices (numbered from 0 to n-1)
		and no edges"""
		self._dict = {}
		for i in range(n):
			self._dict[i] = []

	def parseX(self):
		"""Returns an iterable containing all the vertices"""
		return self._dict.keys()

	def parseNout(self, x):
		"""Returns an iterable containing the outbound neighbours of x"""
		return self._dict[x]

	def parseNin(self, x):
		"""Returns an iterable containing the inbound neighbours of x"""
		list = []
		for i in self._dict.keys():
			if x in self._dict[i]:
				list.append(i)
		return list

	def isEdge(self, x, y):
		"""Returns True if there is an edge from x to y, False otherwise"""
		return y in self._dict[x]

	def addEdge(self, x, y):
		"""Adds an edge from x to y.
		Precondition: there is no edge from x to y"""
		self._dict[x].append(y)


class DoubleDictGraph:
	"""A directed graph, represented as two maps,
	one from each vertex to the set of outbound neighbours,
	the other from each vertex to the set of inbound neighbours"""

	def __init__(self, n):
		"""Creates a graph with n vertices (numbered from 0 to n-1)
		and no edges"""
		self._dictOut = {}
		self._dictIn = {}
		for i in range(n):
			self._dictOut[i] = []
			self._dictIn[i] = []

	def parseX(self):
		"""Returns an iterable containing all the vertices"""
		return self._dictOut.keys()

	def parseNout(self, x):
		"""Returns an iterable containing the outbound neighbours of x"""
		return self._dictOut[x]

	def parseNin(self, x):
		"""Returns an iterable containing the inbound neighbours of x"""
		return self._dictIn[x]

	def isEdge(self, x, y):
		"""Returns True if there is an edge from x to y, False otherwise"""
		return y in self._dictOut[x]

	def addEdge(self, x, y):
		"""Adds an edge from x to y.
		Precondition: there is no edge from x to y"""
		self._dictOut[x].append(y)
		self._dictIn[y].append(x)


def accessible(g, s):
	"""Returns the set of vertices of the graph g that are accessible
	from the vertex s"""
	acc = set()
	acc.add(s)
	list = [s]
	while len(list) > 0:
		x = list[0]
		list = list[1:]
		for y in g.parseNout(x):
			if y not in acc:
				acc.add(y)
				list.append(y)
	return acc


class GoatStatus:
	def __init__(self, i):
		self._status = i

	def __str__(self):
		return self.strX(~self._status) + "/" + self.strX(self._status)

	def __eq__(self, other):
		if isinstance(other, self.__class__):
			return self.__dict__ == other.__dict__
		else:
			return False

	def __ne__(self, other):
		return not self.__eq__(other)

	def __hash__(self):
		return self._status

	def isValid(self):
		"""True if nobody eats nobody in this state"""
		return self.isValidBank(self._status) and self.isValidBank(~self._status)

	def parseN(self):
		ret = []
		for i in range(4):
			if (self._status & 1) == ((self._status >> i) & 1):
				ns = self._status ^ ((1 << i) | 1)
				s = GoatStatus(ns)
				if s.isValid():
					ret.append(s)
		return ret

	def isValidBank(self, i):
		return (i & 4) == 0 or (i & 1) == 1 or ((i & 2) == 0 and (i & 8) == 0)

	def strX(self, i):
		ret = "("
		for j in range(4):
			if (i & (1 << j)) != 0:
				ret = ret + " " + self.names[j]
		return ret + ")"

	names = ("boat", "cabbage", "goat", "wolf")


class GoatGraph:
	def parseX(self):
		ret = []
		for i in range(16):
			s = GoatStatus(i)
			if s.isValid():
				ret.append(s)
		return ret

	def parseNout(self, s):
		return s.parseN()

	def parseNin(self, s):
		return s.parseN()


def initMyGraph(ctor):
	"""Constructs and returns a hard-coded sample graph.
	ctor must be a callable that gets the number of vertices and
	creates a graph with the given number of vertces and with no edges"""
	g = ctor(8)
	g.addEdge(0, 2)
	g.addEdge(0, 4)
	g.addEdge(2, 3)
	g.addEdge(4, 5)
	g.addEdge(4, 6)
	g.addEdge(6, 7)
	g.addEdge(4, 3)
	return g


def initRandomGraph(ctor, n, m):
	"""Constructs and returns a randomly generated graph
	with n vertices and m edges.
	ctor must be a callable that gets the number of vertices and
	creates a graph with the given number of vertces and with no edges"""
	g = ctor(n)
	addedEdges = 0
	while addedEdges < m:
		x = random.randrange(0, n)
		y = random.randrange(0, n)
		if not g.isEdge(x, y):
			g.addEdge(x, y)
			addedEdges += 1
	return g


def run():
	g = initMyGraph(DoubleDictGraph)
	for x in g.parseX():
		print("%s:" % x)
		for y in g.parseNin(x):
			print("%s <- %s" % (x, y))


def get_root(graph):
	for vertex in graph.parseX():
		if len(graph.parseNin(vertex)) == 0:
			return vertex


def get_tree(graph, start_vertex):
    tree = {}
    root = start_vertex
    visited_vertices = set()
    queue = []

    tree[root] = []
    visited_vertices.add(start_vertex)
    queue.append(start_vertex)

    while len(queue) != 0:

        source_vertex = queue.pop(0)  # First element in the queue

        for neighbor_vertex in graph.parseNout(source_vertex):
            if neighbor_vertex not in visited_vertices:
                tree[neighbor_vertex] = []
                visited_vertices.add(neighbor_vertex)
                queue.append(neighbor_vertex)
                tree[source_vertex].append(neighbor_vertex)

    return tree, root

def print_tree(tree, root, tab):
    print(tab + str(root))
    for children in tree[root]:
        print_tree(tree, children, tab + "    ")


def get_parent(tree, node):
    if (len(tree.parseNin(node)) != 1):
        return None
    return tree.parseNin(node)[0]


def get_path(tree, start, end):
    Path = [end]
    parent = get_parent(tree, end)
    while parent != start and parent != get_root(tree) and parent != None:
        Path.append(parent)
        parent = get_parent(tree, parent)
    if (parent != start):
        print("The path doesn't exist")
    else:
        Path.append(parent)
        Path.reverse()
        print(Path)
#run()

g = initMyGraph(DoubleDictGraph)
root_of_tree = get_root(g)
output_the_tree = get_tree(g, root_of_tree)
print_tree(output_the_tree[0], output_the_tree[1], "")
get_path(g, 0, 7)
#s = 0
#print(accessible(g, s))
