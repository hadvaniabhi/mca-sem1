print("\n9. TRY-EXCEPT-ELSE-FINALLY")
print("-" * 50)

try:
    num1 = int(input("Enter first number: "))
    num2 = int(input("Enter second number: "))

    result = num1 / num2

except ValueError:
    print("Error: Enter valid integers.")

except ZeroDivisionError:
    print("Error: Cannot divide by zero.")

else:
    print("Division successful.")
    print("Result =", result)

finally:
    print("Calculation completed.")