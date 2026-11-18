def read_file_content():
    filename = input("Enter the filename (with extension): ").strip()

    try:
        with open(filename, 'r', encoding='utf-8') as file:
            content = file.read()
            
    except FileNotFoundError:
        print(f"Error: The file '{filename}' was not found. Please check the path and filename.")
    except PermissionError:
        print(f"Error: Permission denied. You do not have access to read '{filename}'.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
    else:
        print(f"\n--- Contents of '{filename}' ---")
        print(content)

if __name__ == "__main__":
    read_file_content()