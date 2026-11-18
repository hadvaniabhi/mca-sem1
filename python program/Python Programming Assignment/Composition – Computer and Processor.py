# Create a Processor class with attributes brand and speed and a method display_processor().
# Create a Computer class that contains a Processor object using composition. The Computer
# should also store model and RAM and display complete information.
# Concept: Composition
# ==========================================
# PROGRAM 8 START
# Concept: Composition
# ==========================================

class Processor:
    def __init__(self, brand, speed):
        self.brand = brand
        self.speed = speed

    def display_processor(self):
        print(f"Processor Brand: {self.brand}")
        print(f"Processor Speed: {self.speed}")


class Computer:
    def __init__(self, model, ram, proc_brand, proc_speed):
        self.model = model
        self.ram = ram
        # Composition: Computer owns a Processor object
        self.processor = Processor(proc_brand, proc_speed)

    def display_computer_info(self):
        print(f"Computer Model : {self.model}")
        print(f"RAM           : {self.ram}")
        self.processor.display_processor()


# Execution
if __name__ == "__main__":
    comp = Computer("Dell XPS 15", "16 GB", "Intel Core i7", "3.8 GHz")
    comp.display_computer_info()