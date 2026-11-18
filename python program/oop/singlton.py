class StudentDatabase:

    # Static variable to store the single object
    _instance = None

    # Constructor
    def __new__(cls):
        if cls._instance is None:
            print("Creating Student Database object...")
            cls._instance = super().__new__(cls)
        return cls._instance

    # Instance method
    def show_message(self):
        print("This is the Student Database.")


# Creating first object
db1 = StudentDatabase()

# Creating second object
db2 = StudentDatabase()

# Calling method
db1.show_message()

# Checking whether both objects are same
if db1 is db2:
    print("Both objects are the same.")
else:
    print("Both objects are different.")

print("Address of db1:", id(db1))
print("Address of db2:", id(db2))