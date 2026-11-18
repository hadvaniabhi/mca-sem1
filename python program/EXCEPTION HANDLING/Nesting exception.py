try:
    print("Outer try: Opening Outer Resource")
    try:
        print("Inner try: Opening Inner Resource")
        # Simulating an error

    finally:
        print("Inner finally: Closing Inner Resource")  # Runs first
finally:
    print("Outer finally: Closing Outer Resource")  # Runs second