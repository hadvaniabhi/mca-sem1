print("\n13. FILENOTFOUNDERROR")
print("-" * 50)

try:
    file = open("student.txt", "r")

    content = file.read()

    print(content)

    file.close()

except FileNotFoundError:
    print("Error: File does not exist.")