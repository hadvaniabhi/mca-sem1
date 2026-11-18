class Student:
    def __init__(self, name, marks):
        self.name = name
        self.__marks = marks       # Private attribute

    # Getter method
    def get_marks(self):
        return self.__marks

    # Setter method
    def set_marks(self, marks):
        if marks >= 0 and marks <= 100:
            self.__marks = marks
        else:
            print("Invalid marks! Marks must be between 0 and 100.")


# Create a Student object
student1 = Student("Rahul", 75)

# Using getter method
print("Student Name:", student1.name)
print("Student Marks:", student1.get_marks())

# Using setter method to change marks
student1.set_marks(85)

# Using getter again
print("Updated Marks:", student1.get_marks())

# Trying to set invalid marks
student1.set_marks(120)