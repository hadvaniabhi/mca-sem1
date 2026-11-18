def calculate_percentage():
    marks = []
    
    for i in range(1, 6):
        while True:
            try:
                user_input = input(f"Enter marks for Subject {i} (0–100): ")
                subject_mark = float(user_input)
                
                if subject_mark < 0 or subject_mark > 100:
                    raise ValueError(f"Marks must be between 0 and 100. Entered: {subject_mark}")
                
                marks.append(subject_mark)
                break  # Exit retry loop for current subject on valid input
                
            except ValueError as e:
                if "could not convert string to float" in str(e):
                    print("Error: Invalid input. Please enter numeric digits only.\n")
                else:
                    print(f"Error: {e}\n")

    # Calculations
    total_marks = sum(marks)
    percentage = (total_marks / 500) * 100

    print("\n" + "=" * 25)
    print(f"Total Marks: {total_marks:.2f} / 500")
    print(f"Percentage : {percentage:.2f}%")
    print("=" * 25)

if __name__ == "__main__":
    calculate_percentage()