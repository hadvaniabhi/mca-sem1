print("\n11. KEYERROR")
print("-" * 50)

student = {
    "name": "Rahul",
    "age": 20,
    "course": "Computer Science"
}

try:
    key = input("Enter dictionary key: ")

    print("Value =", student[key])

except KeyError:
    print("Error: The specified key does not exist.")
