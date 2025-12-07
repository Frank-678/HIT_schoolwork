def main():
    A = coordinate(8, 9)
    B = coordinate(7, 4)
    print(A.distance(B))

    B.__init__(1, 1)
    print(A.distance(B))

    B.to_origin()
    print(A.distance(B))

    circle1 = circle(A, 5)
    print(circle1.radius, circle1.center, circle1.center.attr_x)


class coordinate(object):  # inherit old object as parameter, but we do not need

    # Methond, is a terminology for functions only tailored for this class
    def __init__(self, xpara, ypara):  # self is placeholder that actually does as real instance
        self.attr_x = xpara  # set data attributes
        self.attr_y = ypara

    def distance(self, other_coordinate):  # Python's Duck Typing: no need to specify type of other_coordinate but to try to determine whether it has the required attributes or raise an error
        x_diff = self.attr_x - other_coordinate.attr_x
        y_diff = self.attr_y - other_coordinate.attr_y
        return (x_diff ** 2 + y_diff ** 2) ** 0.5  # in fact we can call the outside function
    
    def to_origin(self):
        self.attr_x = 0
        self.attr_y = 0


class circle(object):
    def __init__(self, center_coordinate, radius):
        if type(radius) != int or type(center_coordinate) != coordinate:
            raise ValueError("Incorrect Parameter Type")
        self.center = center_coordinate
        self.radius = radius


main()