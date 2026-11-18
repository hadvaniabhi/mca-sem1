print("\n14. FILE HANDLING WITH FINALLY")
print("-" * 50)

file = None

try:
    file = open("student.txt", "r")

    content = file.read()

    print(content)

except FileNotFoundError:
    print("Error: File not found.")

finally:

    # Check whether the file was successfully opened.
    if file is not None:
        file.close()
        print("File closed successfully.")

    print("File operation completed.")