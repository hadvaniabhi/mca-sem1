print("\n8. TRY-EXCEPT-FINALLY")
print("-" * 50)

try:
    number = int(input("Enter an integer: "))
    print("Number =", number)

except ValueError:
    print("Error: Invalid input.")

finally:
    print("Finally block executed.")