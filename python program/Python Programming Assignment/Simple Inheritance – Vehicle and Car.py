#Create a base class Vehicle with attributes brand and speed and a method display_vehicle().
#Derive a class Car from Vehicle and add model and fuel_type. Display complete car information
#using the inherited and derived members.
#Concept: Simple Inheritance
# ==========================================
# PROGRAM 2 START
# Concept: Simple Inheritance
# ==========================================

class Vehicle:
    def __init__(self, brand, speed):
        self.brand = brand
        self.speed = speed

    def display_vehicle(self):
        print(f"Brand: {self.brand}")
        print(f"Speed: {self.speed} km/h")


class Car(Vehicle):
    def __init__(self, brand, speed, model, fuel_type):
        super().__init__(brand, speed)
        self.model = model
        self.fuel_type = fuel_type

    def display_car_info(self):
        self.display_vehicle()
        print(f"Model: {self.model}")
        print(f"Fuel Type: {self.fuel_type}")


# Execution
if __name__ == "__main__":
    my_car = Car("Toyota", 180, "Camry", "Petrol")
    my_car.display_car_info()