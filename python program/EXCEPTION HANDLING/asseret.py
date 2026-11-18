# Simple program demonstrating assert

marks = int(input("Enter student marks: "))

# Check whether marks are within valid range
assert 0 <= marks <= 50, "Marks must be between 0 and 50"

print("Valid marks:", marks)