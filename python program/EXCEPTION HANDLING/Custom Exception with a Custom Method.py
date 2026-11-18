class InvalidMarksError(Exception):

    def __init__(self, marks):
        self.marks = marks

    def show_error(self):
        print("Invalid Marks:", self.marks)
        print("Marks must be between 0 and 50.")


def set_marks(marks):
    if marks < 0 or marks > 50:
        raise InvalidMarksError(marks)

    print("Marks entered successfully:", marks)


# Main program
try:
    marks = int(input("Enter student marks (0-50): "))
    set_marks(marks)

except InvalidMarksError as e:
    e.show_error()

except ValueError:
    print("Please enter a valid integer.")