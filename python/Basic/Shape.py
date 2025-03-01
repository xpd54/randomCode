class Shape:
    """Class is a shape"""

    def __init__(self, color, is_filled):
        self.color = color
        self.is_filled = is_filled


class Circle(Shape):
    def __init__(self, color, is_filled, radius):
        # dunder init method
        super().__init__(color, is_filled)
        self.radius = radius


class Square(Shape):
    def __init__(self, color, is_filled, width):
        super().__init__(color, is_filled)
        self.width = width


class Triangle(Shape):
    def __init__(self, color, is_filled, width, height):
        super().__init__(color, is_filled)
        self.width = width
        self.heigth = height


def main():
    cirle = Circle("red", False, 2)
    print(cirle.color)


if __name__ == "__main__":
    main()
