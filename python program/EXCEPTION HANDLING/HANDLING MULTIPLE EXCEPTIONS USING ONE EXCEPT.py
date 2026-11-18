print("\n4. MULTIPLE EXCEPTIONS WITH ONE EXCEPT")
print("-" * 50)

try:
    num1 = int(input("Enter first number: "))
    num2 = int(input("Enter second number: "))

    result = num1 / num2

    print("Result =", result)

except (ValueError, ZeroDivisionError):
    print("Error: Invalid input or division by zero.")
    
    
    