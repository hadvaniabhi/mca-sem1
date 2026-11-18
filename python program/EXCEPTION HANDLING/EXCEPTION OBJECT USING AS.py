print("\n5. EXCEPTION OBJECT USING 'AS'")
print("-" * 50)

try:
    number = int(input("Enter an integer: "))

except ValueError as e:
    print("An exception occurred.")
    print("Error message:", e)