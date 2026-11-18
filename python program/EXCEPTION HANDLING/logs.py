# Configure logging
logging.basicConfig(
    filename="error.log",
    level=logging.ERROR,
    format="%(asctime)s - %(levelname)s - %(message)s"
)

try:
    num1 = int(input("Enter first number: "))
    num2 = int(input("Enter second number: "))

    result = num1 / num2

    print("Result:", result)

except ZeroDivisionError:
    logging.exception("Attempted to divide by zero.")
    print("Error: Cannot divide by zero.")

except ValueError:
    logging.exception("Invalid input entered.")
    print("Error: Please enter valid numbers.")

except Exception:
    logging.exception("An unexpected error occurred.")
    print("An unexpected error occurred.")