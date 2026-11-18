# Create a multilevel inheritance hierarchy Student → Marks → Result. Student should store name
# and roll number. Marks should store marks of three subjects. Result should calculate total and
# percentage and display the result.
# Concept: Multilevel Inheritance
# ==========================================
# PROGRAM 4 START
# Concept: Multilevel Inheritance
# ==========================================

class Student:
    def __init__(self, name, roll_number):
        self.name = name
        self.roll_number = roll_number


class Marks(Student):
    def __init__(self, name, roll_number, m1, m2, m3):
        super().__init__(name, roll_number)
        self.m1 = m1
        self.m2 = m2
        self.m3 = m3


class Result(Marks):
    def calculate_and_display(self):
        total = self.m1 + self.m2 + self.m3
        percentage = (total / 300) * 100
        
        print(f"Student Name: {self.name}")
        print(f"Roll Number : {self.roll_number}")
        print(f"Marks       : Subject 1 = {self.m1}, Subject 2 = {self.m2}, Subject 3 = {self.m3}")
        print(f"Total Marks : {total} / 300")
        print(f"Percentage  : {percentage:.2f}%")


# Execution
if __name__ == "__main__":
    res = Result("Neha Sharma", 45, 88, 92, 79)
    res.calculate_and_display()