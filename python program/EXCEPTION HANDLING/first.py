# Configure the logging system
logging.basicConfig(
    filename="error.log",
    level=logging.ERROR,
    format="%(asctime)s - %(levelname)s - %(message)s"
)

def divide_numbers(a, b):
    try:
        result = a / b
        print("Result =", result)

    except Exception:
        # Log the complete exception information
        logging.exception("An error occurred while performing division.")
        print("An error occurred. Check error.log for details.")


# Test the function
try:
    num1 = int(input("Enter first number: "))
    num2 = int(input("Enter second number: "))

    divide_numbers(num1, num2)

except ValueError:
    logging.exception("Invalid input entered by the user.")
    print("Please enter valid integer numbers.")