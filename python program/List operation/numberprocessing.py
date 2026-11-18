# Number Processing:
# Create a list of 10 integers.
# Display the list in ascending order.
# Display the list in descending order.
# Add a new number to the list.
# Find and display the max, min, sum and average of all numbers
numbers = [11,21,45,48,0,69,7,8,9,0]
print("This is your orginal arry",numbers)

numbers.sort()
print(numbers)

numbers.sort(reverse=True)

# this is the another method

descending_list = sorted(numbers, reverse=True)
print("Descending order (new list):", descending_list)

# add the list in new number to the list
new_number=70
numbers.append(new_number)
print("new number add",numbers)


# Find and display the max, min, sum and average of all numbers

maxnumber = max(numbers)
print(maxnumber)

minnumber = min(numbers)
print(minnumber)

total_sum = sum(numbers)
print(total_sum)

average = total_sum / len (numbers)
print(average)
