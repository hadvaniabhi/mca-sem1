print("\n19. EXCEPTION PROPAGATION")
print("-" * 50)


def function1():
    # This generates ZeroDivisionError.
    number = 10 / 0

    print(number)


def function2():
    # function2 calls function1.
    function1()


try:
    # The exception eventually reaches this try block.
    function2()

except ZeroDivisionError:
    print("Exception was handled in the main program.")