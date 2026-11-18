#Method Resolution Order
#Diamond Problem

class A:
    def show(self):
        print("Method of class A")


class B(A):
    def show(self):
        print("Method of class B")
        super().show()


class C(A):
    def show(self):
        print("Method of class C")
        super().show()


class D(B, C):
    def show(self):
        print("Method of class D")
        super().show()


# Create object of D
obj = D()

# Call show()
obj.show()

# Display Method Resolution Order
print("\nMRO:")
print(D.mro())