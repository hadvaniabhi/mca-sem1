class Student:

    def __init__(self, name):
        self.name = name

    # Inner class
    class Address:

        def __init__(self, city):
            self.city = city

        def display_address(self):
            print("City:", self.city)

    def display_student(self):
        print("Student Name:", self.name)


# Create Student object
student = Student("Hardik")

# Create Inner Class object
address = Student.Address("Ahmedabad")

# Display student details
student.display_student()

# Display address details
address.display_address()