def calculator():
    print("Select Operation:")
    print("1. Addition (+)")
    print("2. Subtraction (-)")
    print("3. Multiplication (*)")
    print("4. Division (/)")

    choice = input("Enter choice (1-4): ").strip()

    if choice not in ('1', '2', '3', '4'):
        print("Error: Invalid operation choice. Please select a number from 1 to 4.")
        return

    try:
        num1 = float(input("Enter first number: "))
        num2 = float(input("Enter second number: "))

        if choice == '1':
            result = num1 + num2
            op = '+'
        elif choice == '2':
            result = num1 - num2
            op = '-'
        elif choice == '3':
            result = num1 * num2
            op = '*'
        elif choice == '4':
            if num2 == 0:
                raise ZeroDivisionError("Cannot divide by zero.")
            result = num1 / num2
            op = '/'

    except ValueError:
        print("Error: Invalid numeric input. Please enter valid numbers.")
    except ZeroDivisionError as e:
        print(f"Error: {e}")
    else:
        print(f"\nResult: {num1} {op} {num2} = {result}")


if __name__ == "__main__":
    calculator()