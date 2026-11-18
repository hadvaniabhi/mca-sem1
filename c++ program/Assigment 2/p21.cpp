/*Define a class Figure and use inheritance to define the classes Triangle,
Square, Circle, and Rectangle. Provide a container class Frame to contain any
number of figures, possibly overlapped in position. Provide operations for
drawing frames on the screen and for inserting, modifying, and deleting
frames and the contents of frames. (Actual drawing is not required).*/
#include <iostream>
#include <vector>
using namespace std;

// Base Class
class Figure {
public:
    virtual void draw() {
        cout << "Drawing Figure" << endl;
    }
    virtual ~Figure() {}
};

// Derived Classes
class Triangle : public Figure {
public:
    void draw() override {
        cout << "Drawing Triangle" << endl;
    }
};

class Square : public Figure {
public:
    void draw() override {
        cout << "Drawing Square" << endl;
    }
};

class Circle : public Figure {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Figure {
public:
    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

// Container Class
class Frame {
    vector<Figure*> figures;

public:
    void insert(Figure* fig) {
        figures.push_back(fig);
    }

    void modify(int index, Figure* newFig) {
        if (index >= 0 && index < figures.size()) {
            delete figures[index];
            figures[index] = newFig;
        }
    }

    void remove(int index) {
        if (index >= 0 && index < figures.size()) {
            delete figures[index];
            figures.erase(figures.begin() + index);
        }
    }

    void draw() {
        cout << "--- Drawing Frame Contents ---" << endl;
        for (auto fig : figures) {
            fig->draw();
        }
    }

    ~Frame() {
        for (auto fig : figures) {
            delete fig;
        }
    }
};

int main() {
    Frame frame;

    frame.insert(new Triangle());
    frame.insert(new Square());
    frame.insert(new Circle());

    frame.draw();

    frame.modify(1, new Rectangle());
    frame.remove(0);

    cout << "\nAfter Modification and Deletion:" << endl;
    frame.draw();

    return 0;
}
