print("\n12. TYPEERROR")
print("-" * 50)

try:
    number = 10
    text = "20"

    result = number + text

    print(result)

except TypeError:
    print("Error: Cannot add an integer and a string.")