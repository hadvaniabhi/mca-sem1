def search_student_marks():
    student_marks = {
        "Alice": 85,
        "Bob": 92,
        "Charlie": 78,
        "Diana": 95,
        "Ethan": 88
    }
    
    name = input("Enter the student's name: ").strip().capitalize()
    
    try:
        marks = student_marks[name]
    except KeyError:
        print(f"Error: Student '{name}' not found in the records.")
    else:
        print(f"Success: {name} scored {marks} marks.")

if __name__ == "__main__":
    search_student_marks()