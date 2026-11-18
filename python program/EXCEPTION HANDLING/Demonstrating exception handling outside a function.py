def divide_numbers(a, b):
    # Exception may occur here
    result = a / b
    return result


# Calling the function inside try block
try:
    num1 = int(input("Enter first number: "))
    num2 = int(input("Enter second number: "))

    result = divide_numbers(num1, num2)

    print("Result =", result)

except ZeroDivisionError:
    print("Error: Cannot divide by zero.")

except ValueError:
    print("Error: Please enter valid numbers.")

print("Program execution completed.")