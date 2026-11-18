print("\n21. NAMEERROR")
print("-" * 50)

try:
    print(undefined_variable)

except NameError:
    print("Error: Variable has not been defined.")