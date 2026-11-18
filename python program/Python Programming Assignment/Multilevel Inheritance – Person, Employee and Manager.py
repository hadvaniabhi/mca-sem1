# Create three classes using multilevel inheritance: Person → Employee → Manager. Person
# should contain name and age, Employee should add employee_id and salary, and Manager
# should add department and team_size. Use constructors and methods to display all information.
# Use super() where appropriate.
# Concept: Multilevel Inheritance
# ==========================================
# PROGRAM 3 START
# Concept: Multilevel Inheritance
# ==========================================

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def display_person(self):
        print(f"Name: {self.name}")
        print(f"Age: {self.age}")


class Employee(Person):
    def __init__(self, name, age, employee_id, salary):
        super().__init__(name, age)
        self.employee_id = employee_id
        self.salary = salary

    def display_employee(self):
        super().display_person()
        print(f"Employee ID: {self.employee_id}")
        print(f"Salary: ₹{self.salary}")


class Manager(Employee):
    def __init__(self, name, age, employee_id, salary, department, team_size):
        super().__init__(name, age, employee_id, salary)
        self.department = department
        self.team_size = team_size

    def display_manager(self):
        super().display_employee()
        print(f"Department: {self.department}")
        print(f"Team Size: {self.team_size}")


# Execution
if __name__ == "__main__":
    mgr = Manager("Amit Shah", 40, "MGR1001", 85000, "IT Operations", 12)
    mgr.display_manager()