# Create a diamond-shaped inheritance structure: Person is the base class, Student and Employee
# inherit from Person, and TeachingAssistant inherits from both Student and Employee. Use
# super() and a suitable method to demonstrate Python&#39;s Method Resolution Order (MRO). Print
# the MRO of TeachingAssistant.
# Concept: Multiple Inheritance and MRO
# ==========================================
# PROGRAM 6 START
# Concept: Multiple Inheritance and MRO
# ==========================================

class Person:
    def display(self):
        print("Class: Person")


class Student(Person):
    def display(self):
        print("Class: Student")
        super().display()


class Employee(Person):
    def display(self):
        print("Class: Employee")
        super().display()


class TeachingAssistant(Student, Employee):
    def display(self):
        print("Class: TeachingAssistant")
        super().display()


# Execution
if __name__ == "__main__":
    ta = TeachingAssistant()
    print("--- Calling display() method ---")
    ta.display()

    print("\n--- Method Resolution Order (MRO) ---")
    for cls in TeachingAssistant.__mro__:
        print(cls.__name__)