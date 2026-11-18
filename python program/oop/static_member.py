class Student:

    # Static member (Class Variable)
    college = "ABC College"

    # Constructor
    def __init__(self, name, marks):
        self.name = name          # Instance member
        self.marks = marks        # Instance member
        print("Student object created.")

    # Instance method
    def display(self):
        print("Name   :", self.name)
        print("Marks  :", self.marks)
        print("College:", Student.college)

    # Getter method
    def get_marks(self):
        return self.marks

    # Setter method
    def set_marks(self, marks):
        if marks >= 0 and marks <= 100:
            self.marks = marks
        else:
            print("Invalid marks!")

    # Static method
    @staticmethod
    def show_college():
        print("College Name:", Student.college)

    # Destructor
    def __del__(self):
        print("Student object destroyed.")


# Creating objects
student1 = Student("Hardik", 85)
student2 = Student("Jay", 90)

print("\n--- Student 1 ---")
student1.display()

print("\n--- Student 2 ---")
student2.display()

# Using getter
print("\nMarks using getter:", student1.get_marks())

# Using setter
student1.set_marks(95)

print("Updated marks:", student1.get_marks())

# Using static member
print("\nCollege using static member:", Student.college)

# Using static method
Student.show_college()

# Delete objects
del student1
del student2