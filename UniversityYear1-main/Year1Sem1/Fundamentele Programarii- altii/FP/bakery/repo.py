from domain import *

class Repository:
    def __init__(self):
        self._data = []

    def store(self, item):
        '''
        Store a new item into Repository
        '''
        pass

    def delete(self, ID):
        '''
        Delete item with given ID from repository
        '''
        pass

    def find(self, ID):
        '''
        Find item having given ID
        Raises RepositoryException if item not found
        '''
        pass

class RepoTest(unittest.TestCase):
    def testRepo(self):
        repo = Repository()
        self.assertEqual(len(repo),0)
        # Python 3.8 new operator
        repo.store((ing := Ingredient(1,"Flour 01",10)))
        self.assertEqual(len(repo),1)
        self.assertEqual(ing, repo[0])
        # ... more tests here ...




