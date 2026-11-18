# Design a small Online Course System. Create a base class User and derive Student and Instructor
# from it. Use multiple inheritance to create a TeachingAssistant class combining suitable features
# of Student and Instructor. Create an abstract class CourseComponent with an abstract method
# display(). Use composition so that a Course contains CourseComponent objects. Include
# exception handling for invalid course registration, such as duplicate registration or an
# unavailable course.
# Concepts: Simple Inheritance, Multiple Inheritance, Abstract Method, Composition, and
# Exception Handling
# ==========================================
# PROGRAM 10 START
# Concepts: Simple & Multiple Inheritance, Abstract Methods,
# Composition, and Exception Handling
# ==========================================

# ==========================================
# PROGRAM 10 START
# Concepts: Simple & Multiple Inheritance, Abstract Methods,
# Composition, and Exception Handling
# ==========================================

from abc import ABC, abstractmethod


# Abstract Class
class CourseComponent(ABC):
    @abstractmethod
    def display(self):
        pass


class LectureModule(CourseComponent):
    def __init__(self, module_title):
        self.module_title = module_title

    def display(self):
        print(f" - Module: {self.module_title}")


# Base Class
class User:
    def __init__(self, name, email):
        self.name = name
        self.email = email


class Student(User):
    def __init__(self, name, email, student_id):
        super().__init__(name, email)
        self.student_id = student_id


class Instructor(User):
    def __init__(self, name, email, employee_id):
        super().__init__(name, email)
        self.employee_id = employee_id


# Multiple Inheritance
class TeachingAssistant(Student, Instructor):
    def __init__(self, name, email, student_id, employee_id):
        Student.__init__(self, name, email, student_id)
        Instructor.__init__(self, name, email, employee_id)

    def display_ta_info(self):
        print(f"TA Name       : {self.name}")
        print(f"TA Email      : {self.email}")
        print(f"Student ID    : {self.student_id}")
        print(f"Employee ID   : {self.employee_id}")


# Composition & Exception Handling
class Course:
    def __init__(self, course_name):
        self.course_name = course_name
        self.components = []  # Composition: Stores CourseComponent objects
        self.registered_students = []

    def add_component(self, component: CourseComponent):
        self.components.append(component)

    def register_student(self, student: Student):
        if student in self.registered_students:
            raise Exception(f"Registration Error: Student '{student.name}' is already registered!")
        self.registered_students.append(student)
        print(f"Student '{student.name}' registered successfully for {self.course_name}.")

    def display_course_details(self):
        print(f"\nCourse Title: {self.course_name}")
        print("Course Content Modules:")
        for comp in self.components:
            comp.display()


# Execution
if __name__ == "__main__":
    # Create TA
    ta = TeachingAssistant("Karan Dave", "karan@univ.edu", "ST202", "EMP88")
    print("--- Teaching Assistant Details ---")
    ta.display_ta_info()

    # Composition Setup
    python_course = Course("Python OOP Masters")
    python_course.add_component(LectureModule("Classes and Objects"))
    python_course.add_component(LectureModule("Inheritance & Polymorphism"))
    python_course.display_course_details()

    # Exception Handling Demonstration
    s1 = Student("Aman Kumar", "aman@mail.com", "S100")

    print("\n--- Course Registration ---")
    try:
        python_course.register_student(s1)
        # Attempting duplicate registration to trigger Exception
        python_course.register_student(s1)
    except Exception as err:
        print(f"Caught Exception: {err}")