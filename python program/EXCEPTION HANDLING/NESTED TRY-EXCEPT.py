print("\n18. NESTED TRY-EXCEPT")
print("-" * 50)

try:

    # Inner try-except block
    try:
        number = int(input("Enter a number: "))

        result = 100 / number

        print("Result =", result)

    except ZeroDivisionError:
        print("Inner block: Cannot divide by zero.")

except ValueError:
    print("Outer block: Invalid input.")
