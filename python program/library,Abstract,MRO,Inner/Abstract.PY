from abc import ABC, abstractmethod

# Abstract class
class Animal(ABC):

    @abstractmethod
    def sound(self):
        pass


# Child class
class Dog(Animal):

    def sound(self):
        print("Dog says: Woof!")


# Creating object of child class
# a = Animal()
d = Dog()

# Calling the implemented method
d.sound()