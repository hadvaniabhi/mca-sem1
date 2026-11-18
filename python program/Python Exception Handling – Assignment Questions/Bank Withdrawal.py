class InsufficientFundsError(Exception):
    """Raised when withdrawal amount exceeds available balance."""
    pass

class InvalidAmountError(Exception):
    """Raised when withdrawal amount is zero or negative."""
    pass

def simulate_bank_withdrawal():
    account_balance = 5000.0  # Initial account balance

    print(f"Welcome to the ATM system.")
    print(f"Current Account Balance: ${account_balance:.2f}\n")

    try:
        raw_input = input("Enter withdrawal amount: ")
        amount = float(raw_input)

        if amount <= 0:
            raise InvalidAmountError("Withdrawal amount must be greater than $0.00.")

        if amount > account_balance:
            raise InsufficientFundsError(
                f"Insufficient balance. Tried to withdraw ${amount:.2f}, "
                f"but account only has ${account_balance:.2f}."
            )

    except ValueError:
        print("Error: Invalid numeric input. Please enter valid numbers only.")
    except (InvalidAmountError, InsufficientFundsError) as e:
        print(f"Transaction Failed: {e}")
    else:
        account_balance -= amount
        print(f"\nTransaction Successful!")
        print(f"Withdrawn: ${amount:.2f}")
        print(f"Remaining Balance: ${account_balance:.2f}")

if __name__ == "__main__":
    simulate_bank_withdrawal()