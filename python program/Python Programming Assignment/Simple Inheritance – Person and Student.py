# Create a Python program using simple inheritance with a base class Person and a derived class
# Student. The Person class should store a name and age and provide a method to display them.
# The Student class should add roll number and course and display all details. Create at least two
# Student objects.
# Concept: Simple Inheritance
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def display_person(self):
        print(f"Name: {self.name}")
        print(f"Age: {self.age}")


class Student(Person):
    def __init__(self, name, age, roll_number, course):
        super().__init__(name, age)
        self.roll_number = roll_number
        self.course = course

    def display_student(self):
        self.display_person()
        print(f"Roll Number: {self.roll_number}")
        print(f"Course: {self.course}")


if __name__ == "__main__":
    print("--- Student 1 ---")
    s1 = Student("Rahul Sharma", 20, "101", "Computer Science")
    s1.display_student()

    print("\n--- Student 2 ---")
    s2 = Student("Priya Patel", 21, "102", "Information Technology")
    s2.display_student()