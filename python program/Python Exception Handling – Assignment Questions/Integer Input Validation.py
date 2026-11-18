def get_integer_input():
    try:
        user_input = input("Enter an integer: ")
        number = int(user_input)
    except ValueError:
        print(f"Error: '{user_input}' is not a valid integer. Please enter numeric digits only.")
    else:
        print(f"Success: You entered the integer {number}.")

if __name__ == "__main__":
    get_integer_input()