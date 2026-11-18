def divide_numbers():
    try:
        numerator = float(input("Enter the numerator (first number): "))
        denominator = float(input("Enter the denominator (second number): "))

        result = numerator / denominator

    except ZeroDivisionError:
        print("\nError: Cannot divide by zero. Please enter a denominator other than 0.")
    except ValueError:
        print("\nError: Invalid input. Please enter valid numerical values.")
    else:
        print(f"\nResult: {numerator} / {denominator} = {result}")


if __name__ == "__main__":
    divide_numbers()