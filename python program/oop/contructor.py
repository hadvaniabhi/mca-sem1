class Student:

    # Constructor
    def __init__(self, name, marks):
        self.name = name
        self.marks = marks
        print("Student object created.")

    # Getter method
    def get_marks(self):
        return self.marks

    # Setter method
    def set_marks(self, marks):
        if marks >= 0 and marks <= 100:
            self.marks = marks
        else:
            print("Invalid marks! Marks must be between 0 and 100.")

    # Destructor
    def __del__(self):
        print("Student object destroyed.")


# Create an object
student1 = Student("Rahul", 75)

# Display student details
print("Student Name:", student1.name)
print("Student Marks:", student1.get_marks())

# Change marks using setter
student1.set_marks(85)

# Display updated marks
print("Updated Marks:", student1.get_marks())

# Try to set invalid marks
student1.set_marks(120)

# Delete the object
del student1