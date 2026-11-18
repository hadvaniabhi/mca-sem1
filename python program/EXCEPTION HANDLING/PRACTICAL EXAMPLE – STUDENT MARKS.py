print("\n24. PRACTICAL EXAMPLE – STUDENT MARKS")
print("-" * 50)

try:

    marks = float(input("Enter marks (0-100): "))

    # Validate marks.
    if marks < 0 or marks > 100:
        raise ValueError(
            "Marks must be between 0 and 100."
        )

    # Determine grade.
    if marks >= 90:
        grade = "A"

    elif marks >= 75:
        grade = "B"

    elif marks >= 60:
        grade = "C"

    elif marks >= 40:
        grade = "D"

    else:
        grade = "F"


except ValueError as e:

    print("Error:", e)


else:

    print("Marks =", marks)
    print("Grade =", grade)
    print("Marks entered successfully.")


finally:

    print("Marks processing completed.")
