try:
    # Taking input from the user
    num1 = int(input("Enter the first number: "))
    num2 = int(input("Enter the second number: "))

    # Performing division
    result = num1 / num2

    print("Result =", result)

except ValueError:
    # Handles invalid input such as letters or decimal values
    print("Error: Please enter valid integer numbers.")

#except ZeroDivisionError:
    # Handles division by zero
 #   print("Error: Cannot divide a number by zero.")

except TypeError:
    # Handles incorrect data types
    print("Error: Invalid data type.")

except Exception as e:
    # Handles any other unexpected exception
    print("An unexpected error occurred:", e)

else:
    # Executes when no exception occurs
    print("Division completed successfully.")

finally:
    # Always executes whether an exception occurs or not
    print("Program execution completed.")