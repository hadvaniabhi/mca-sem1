def access_list_element():
    numbers = [10, 20, 30, 40, 50]
    print(f"Current list: {numbers}")
    
    try:
        index_input = input("Enter an index number (0 to 4): ")
        index = int(index_input)
        element = numbers[index]
        
    except IndexError:
        print(f"Error: Index {index_input} is out of range. Please enter an index between 0 and 4 (or -5 to -1).")
    except ValueError:
        print(f"Error: '{index_input}' is not a valid integer. Please enter a numeric index.")
    else:
        print(f"Success: The element at index {index} is {element}.")

if __name__ == "__main__":
    access_list_element()