print("\n20. PASS IN EXCEPTION HANDLING")
print("-" * 50)

try:
    number = int("ABC")

except ValueError:
    pass

print("Program continues normally.")