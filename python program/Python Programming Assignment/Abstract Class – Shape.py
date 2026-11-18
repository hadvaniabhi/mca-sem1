# Using Python&#39;s abc module, create an abstract class Shape containing an abstract method area().
# Derive Circle and Rectangle from Shape and implement area() in both classes. Create objects
# and display their areas. Also demonstrate why an object of Shape cannot be created directly.
# Concept: Abstract Class and Abstract Method
# ==========================================
# PROGRAM 7 START
# Concept: Abstract Class and Abstract Method
# ==========================================

from abc import ABC, abstractmethod
import math


class Shape(ABC):
    @abstractmethod
    def area(self):
        pass


class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return math.pi * self.radius * self.radius


class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height


# Execution
if __name__ == "__main__":
    # Object Creation
    c = Circle(5)
    r = Rectangle(4, 6)

    print(f"Area of Circle (Radius 5)   : {c.area():.2f}")
    print(f"Area of Rectangle (4x6)    : {r.area()}")

    # Demonstrating Shape instantiation restriction
    print("\nAttempting to instantiate Abstract Class 'Shape':")
    try:
        s = Shape()
    except TypeError as e:
        print(f"Error Caught: {e}")