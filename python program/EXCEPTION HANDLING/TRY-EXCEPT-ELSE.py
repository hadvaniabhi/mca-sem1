print("\n7. TRY-EXCEPT-ELSE")
print("-" * 50)

try:
    number = int(input("Enter an integer: "))

except ValueError:
    print("Error: Invalid input.")

else:
    print("No exception occurred.")
    print("You entered:", number)