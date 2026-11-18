print("\n23. PERMISSIONERROR")
print("-" * 50)

try:
    file = open("restricted_file.txt", "r")

    print(file.read())

    file.close()

except PermissionError:
    print("Error: Permission denied.")

except FileNotFoundError:
    print("File does not exist.")