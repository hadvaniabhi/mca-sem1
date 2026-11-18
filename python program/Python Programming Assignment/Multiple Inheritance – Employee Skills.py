# Create two base classes TechnicalSkills and CommunicationSkills. Each class should provide
# suitable methods for displaying skills. Create an Employee class that inherits from both classes.
# Create an Employee object and demonstrate both sets of skills.
# Concept: Multiple Inheritance
# ==========================================
# PROGRAM 5 START
# Concept: Multiple Inheritance
# ==========================================

class TechnicalSkills:
    def show_technical_skills(self):
        print("Technical Skills: Python, C++, Data Structures, SQL")


class CommunicationSkills:
    def show_communication_skills(self):
        print("Communication Skills: Fluent English, Team Collaboration, Presentation")


class Employee(TechnicalSkills, CommunicationSkills):
    def __init__(self, name):
        self.name = name

    def display_all_details(self):
        print(f"Employee Name: {self.name}")
        self.show_technical_skills()
        self.show_communication_skills()


# Execution
if __name__ == "__main__":
    emp = Employee("Rohan Mehta")
    emp.display_all_details()