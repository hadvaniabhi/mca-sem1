def validate_age():
    try:
        # Prompt user for input and convert to an integer
        age = int(input("Please enter your age: "))

        # Check bounds and raise ValueError if out of valid range
        if age < 0 or age > 120:
            raise ValueError(f"Age must be between 0 and 120. You entered: {age}")

    except ValueError as e:
        # Catch both non-numeric input and manually raised range errors
        if "invalid literal for int()" in str(e):
            print("Error: Invalid input. Please enter a valid numerical digit.")
        else:
            print(f"Error: {e}")
    else:
        # Executes only if no exception occurred
        print(f"Success! Age recorded as {age}.")


if __name__ == "__main__":
    validate_age()