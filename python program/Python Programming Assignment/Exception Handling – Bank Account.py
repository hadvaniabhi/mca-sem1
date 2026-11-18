# Create a BankAccount class with account number and balance. Implement deposit() and
# withdraw() methods. Use exception handling to manage invalid amounts, insufficient balance,
# and non-numeric input. Demonstrate try, except, else, and finally where appropriate.
# Concept: Exception Handling
# ==========================================
# PROGRAM 9 START
# Concept: Exception Handling
# ==========================================

class BankAccount:
    def __init__(self, acc_number, balance=0.0):
        self.acc_number = acc_number
        self.balance = float(balance)

    def deposit(self, amount):
        try:
            amt = float(amount)
            if amt <= 0:
                raise ValueError("Deposit amount must be greater than 0.")
        except ValueError as e:
            print(f"[Deposit Error]: {e}")
        else:
            self.balance += amt
            print(f"Successfully deposited ₹{amt}. New Balance: ₹{self.balance}")
        finally:
            print("Deposit transaction complete.\n")

    def withdraw(self, amount):
        try:
            amt = float(amount)
            if amt <= 0:
                raise ValueError("Withdrawal amount must be greater than 0.")
            if amt > self.balance:
                raise Exception("Insufficient Balance!")
        except ValueError as e:
            print(f"[Withdrawal Error]: Invalid input - {e}")
        except Exception as e:
            print(f"[Withdrawal Error]: {e}")
        else:
            self.balance -= amt
            print(f"Successfully withdrew ₹{amt}. Remaining Balance: ₹{self.balance}")
        finally:
            print("Withdrawal transaction complete.\n")


# Execution
if __name__ == "__main__":
    account = BankAccount("ACC12345", 5000)

    # 1. Valid Deposit
    account.deposit(1500)

    # 2. Invalid Input
    account.deposit("abc")

    # 3. Insufficient Balance
    account.withdraw(10000)

    # 4. Valid Withdrawal
    account.withdraw(2000)