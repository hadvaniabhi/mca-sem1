class InvalidMarksError(Exception):
    """Custom exception for invalid marks."""
    pass


def set_marks(marks):
    if marks < 0 or marks > 50:
        raise InvalidMarksError("Marks must be between 0 and 50.")

    print("Marks entered successfully:", marks)


# Main program
try:
    marks = int(input("Enter student marks (0-50): "))
    set_marks(marks)

except InvalidMarksError as e:
    print("Invalid Marks:", e)

except ValueError:
    print("Please enter a valid integer.")