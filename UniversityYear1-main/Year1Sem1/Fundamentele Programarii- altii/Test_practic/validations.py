
class Validation:
    def validate_coordinates(self, coordonate):
        if str(coordonate[0]) not in ["A", "B", "C", "D", "E", "F", "G", "H"] or int(coordonate[1]) not in range(1, 8+1):
            raise Exception("Bad command!")
