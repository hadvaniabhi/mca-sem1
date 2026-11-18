print("\n17. CUSTOM EXCEPTION WITH MESSAGE")
print("-" * 50)


class InsufficientBalanceError(Exception):
    """Exception raised when account balance is insufficient."""
    pass


try:
    balance = 5000

    withdrawal = float(
        input("Enter withdrawal amount: ")
    )

    if withdrawal > balance:
        raise InsufficientBalanceError(
            "Insufficient balance for this transaction."
        )

    balance = balance - withdrawal

    print("Withdrawal successful.")
    print("Remaining balance:", balance)

except ValueError:
    print("Error: Enter a valid amount.")

except InsufficientBalanceError as e:
    print("Transaction failed:", e)
