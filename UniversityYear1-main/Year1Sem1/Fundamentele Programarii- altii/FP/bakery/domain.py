from unittest import TestCase
import unittest

'''
The Happy Bakery is a family-run business that produces and sells bakery and confectionary products. The bakery turns ingredients into delicious products using defined recipes. They need you, yes you! to help them manage their daily workflow. What does this entail?
	a. Manage the list of available ingredients, the recipes and the products that the bakery knows to make. 
	b. Add a production order. This transforms the ingredients into the product.
	c. Keep the stock level for each ingredient and product.
	d. When buying ingredients or selling products, update the amount of cash in the register. Each day, the bakery starts with a fixed sum (e.g. 1000 RON).
	e. Display the list of used ingredients, sorted in descending order of amount used.
	f. Display the list of products sold, sorted descending by generated income.
'''

class BakeryException(Exception):
    '''
    General Exception class used for bakery problem
    '''

    def __init__(self, msg):
        Exception.__init__(self, msg)


class InvalidValueException(BakeryException):
    '''
    Used when trying to set invalid values
    '''

    def __init__(self, msg):
        BakeryException.__init__(self, msg)


class Ingredient:
    '''
    Represents a bakery ingredient
    '''

    def __init__(self, ID, name, price):
        self._id = ID
        self.Name = name
        self.Price = price

    @property
    def Id(self):
        return self._id

    @property
    def Name(self):
        return self._name

    @Name.setter
    def Name(self, value):
        if len(value) < 3:
            raise InvalidValueException(
                "Ingredient name must have at least 3 characters.")
        self._name = value

    @property
    def Price(self):
        return self._price

    @Price.setter
    def Price(self, value):
        if value < 0:
            raise InvalidValueException("Ingredient price < 0!")
        self._price = value

class IngredientTest(unittest.TestCase):
    def testIngredient(self):
        ingr = Ingredient(1, "Wheat Flour 000", 5.50)
        self.assertEqual(ingr.Id, 1)
        self.assertEqual(ingr.Name, "Wheat Flour 000")
        self.assertEqual(ingr.Price, 5.50)

        with self.assertRaises(InvalidValueException):    
            ingr.Price = -1

        with self.assertRaises(BakeryException):
            ingr.Name = "?"
        
        

class Product:
    '''
    Represents a Bakery Product
    '''
    def __init__(self, ID, name, price, recipe):
        self._id = ID
        self.Name = name
        self.Recipe = recipe

    @property
    def Id(self):
        return self._id

    @property
    def Name(self):
        return self._name

    @Name.setter
    def Name(self, value):
        if len(value) < 5:
            raise InvalidValueException(
                "Product name must have at least 5 characters.")
        self._name = value

    @property
    def Price(self):
        return self._price

    @Price.setter
    def Price(self, value):
        if value <= 0:
            raise InvalidValueException("Product price <= 0!")
        self._price = value

    @property
    def Recipe(self):
        return self._recipe

    @Recipe.setter
    def Recipe(self, value):
        if value == None:
            raise InvalidValueException("Product must have a recipe!")
        self._recipe = value

class Stock:
    '''
    Represents a unit of bakery stock
    '''
    def __init__(self, stockItem, quantity):
        self._stockItem = stockItem
        self.Quantity = quantity

    @property
    def Item(self):
        '''
        Ingredient or Product
        '''
        return self._stockItem

    @property
    def Quantity(self):
        '''
        Available quantity
        '''
        return self._quantity

    @Quantity.setter
    def Quantity(self, value):
        if value < 0:
            raise InvalidValueException("Stock cannot fall below 0!")
        self._quantity = value


class Recipe:
    def __init__(self, ID, product, *stockItems):
        self._id = ID
        self.Product = product
        self._stockList = list(stockItems)

    @property
    def Id(self):
        return self._id

    @property
    def Product(self):
        '''
        Cannot change the product this recipe is for.
        '''
        return self._product

    @property
    def Ingr(self):
        '''
        Available quantity
        '''
        return self._quantity

    @property
    def Ingredients(self):
        return self._stockList
    