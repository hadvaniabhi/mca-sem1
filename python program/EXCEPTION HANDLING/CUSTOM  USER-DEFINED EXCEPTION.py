print("\n16. CUSTOM EXCEPTION")
print("-" * 50)


class InvalidAgeError(Exception):
    """Custom exception for invalid age."""
    pass


try:
    age = int(input("Enter your age: "))

    if age < 18:
        raise InvalidAgeError("Age must be 18 or above.")

    print("You are eligible.")

except InvalidAgeError as e:
    print("Custom Error:", e)