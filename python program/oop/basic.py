class Student:

    name='Hardik'
    marks=0

    # Getter method
    def get_marks(self):
        return self.marks

    # Setter method
    def set_marks(self, marks):
        if marks >= 0 and marks <= 100:
            self.marks = marks
        else:
            print("Invalid marks! Marks must be between 0 and 100.")


# Create an object
student1 = Student()

# Display student details
print("Student Name:", student1.name)
print("Student Marks:", student1.get_marks())


# Public data member
student1.name = "Rahul"
student1.marks = 75

# Display student details
print("Student Name:", student1.name)
print("Student Marks:", student1.get_marks())

# Change marks using setter
student1.set_marks(85)

# Display updated marks using getter
print("Updated Marks:", student1.get_marks())

# Try to set invalid marks
student1.set_marks(120)