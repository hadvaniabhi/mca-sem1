try:
    num1 = int(input("Enter the first number: "))
    num2 = int(input("Enter the second number: "))

    result = num1 / num2

except ValueError:
    print("Error: Please enter valid integer numbers.")

except ZeroDivisionError:
    print("Error: Cannot divide by zero.")

else:
    # This block executes only when no exception occurs
    print("Division was successful.")
    print("Result =", result)

print("Program execution completed.")