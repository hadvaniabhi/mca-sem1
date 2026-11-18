print("\n22. ATTRIBUTEERROR")
print("-" * 50)

try:
    number = 100

    # Integer objects do not have an attribute called "name".
    print(number.name)

except AttributeError:
    print("Error: Object does not have this attribute.")