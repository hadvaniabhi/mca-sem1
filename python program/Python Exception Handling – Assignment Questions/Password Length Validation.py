# User-defined Exception
class PasswordTooShortError(Exception):
    """Raised when the input password is fewer than 6 characters."""
    def __init__(self, length):
        self.length = length
        super().__init__(f"Password must be at least 6 characters long. Current length: {length}")


def validate_password():
    try:
        password = input("Enter a new password: ")
        
        # Check password length and raise custom exception if invalid
        if len(password) < 6:
            raise PasswordTooShortError(len(password))
            
    except PasswordTooShortError as e:
        print(f"Error: {e}")
    else:
        print("Success: Password set successfully!")


if __name__ == "__main__":
    validate_password()