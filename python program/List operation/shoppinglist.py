# Shopping List:
#       Create a list containing 5 shopping items.
#       Add two new items to the list.
#       Remove 2 items specified by the user.
#        (by index and by value)Check whether a particular item exists in the list.
#       Display the final shopping list.

# 1. Create a list containing 5 shopping items
shopping_list = ["Milk", "Bread", "Eggs", "Apples", "Rice"]
print("1. Initial Shopping List:", shopping_list)

# 2. Add two new items to the list
shopping_list.append("Butter")
shopping_list.append("Bananas")
print("2. List after adding 2 items:", shopping_list)

# 3. Remove 2 items specified by the user
# A) Remove by Index (e.g., index 0 પરથી "Milk" હટાવશે)
removed_by_index = shopping_list.pop(0)
print(f"3A. Removed item at index 0 ('{removed_by_index}'):", shopping_list)

# B) Remove by Value (e.g., "Eggs" વેલ્યુ શોધીને હટાવશે)
shopping_list.remove("Eggs")
print("3B. Removed 'Eggs' by value:", shopping_list)

# 4. Check whether a particular item exists in the list
search_item = "Apples"
if search_item in shopping_list:
    print(f"4. Check Item: Yes, '{search_item}' is in the shopping list.")
else:
    print(f"4. Check Item: No, '{search_item}' is not in the shopping list.")

# 5. Display the final shopping list
print("\n5. --- Final Shopping List ---")
for index, item in enumerate(shopping_list, start=1):
    print(f"{index}. {item}")
