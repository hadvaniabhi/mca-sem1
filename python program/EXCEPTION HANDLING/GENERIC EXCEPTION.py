print("\n6. GENERIC EXCEPTION")
print("-" * 50)

try:
    num1 = int(input("Enter first number: "))
    num2 = int(input("Enter second number: "))

    result = num1 / num2

    print("Result =", result)

except Exception as e:
    print("Some error occurred.")
    print("Error:", e)