print("\n10. INDEXERROR")
print("-" * 50)

numbers = [10, 20, 30, 40, 50]

try:
    index = int(input("Enter list index (0-4): "))
    print("Value =", numbers[index])

except IndexError:
    print("Error: Index is outside the list range.")

except ValueError:
    print("Error: Index must be an integer.")