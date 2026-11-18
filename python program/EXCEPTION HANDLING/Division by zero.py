print("\n1. BASIC TRY-EXCEPT")
print("-" * 50)

try:
    number1 = 10
    number2 = 0

    result = number1 / number2

    print("Result =", result)

except ZeroDivisionError:
    print("Error: Cannot divide a number by zero.")