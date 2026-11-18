# Program to demonstrate finally block in file handling

file = None

try:
    # Open the file
    file = open("student.txt", "r")

    # Read the contents of the file
    data = file.read()

    print("File contents:")
    print(data)

except FileNotFoundError:
    print("Error: File not found.")

except PermissionError:
    print("Error: Permission denied.")

finally:
    # This block always executes
    if file is not None:
        file.close()
        print("File has been closed.")

    print("Finally block executed.")