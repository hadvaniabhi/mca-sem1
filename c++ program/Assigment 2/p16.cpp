/*WAP to create base class Book having int id and char name as data members
and respective functionality, show following types of inheritance and display
the details of each kind of books, also calculate the total no of each type of
books in proper format.
Simple inheritance with derived class Sales
Hierarchical inheritance with derived classes academics and thrillers
Show use of constructor and destructor in above examples of inheritance.*/
#include <iostream>
#include <string.h>
using namespace std;
class Book {
protected:
    int id;
    char name[50];
    static int total_books;

public:
    Book(int b_id, const char* b_name) {
        id = b_id;
        strcpy(name, b_name);
        total_books++;
        cout << "Base Constructor Call Thayo" << endl;
    }

    void displayBook() {
        cout << "ID: " << id << ", Name: " << name;
    }

    static int getTotalBooks() {
        return total_books;
    }

    ~Book() {
        cout << "Base Destructor Call Thayo" << endl;
    }
};

int Book::total_books = 0;


class Sales : public Book {
private:
    int sales_count;
    static int total_sales;

public:
    Sales(int b_id, const char* b_name, int count) : Book(b_id, b_name) {
        sales_count = count;
        total_sales++;
        cout << "Sales Constructor Call Thayo" << endl;
    }

    void displaySales() {
        displayBook();
        cout << ", Sales: " << sales_count << endl;
    }

    static int getTotalSales() {
        return total_sales;
    }

    ~Sales() {
        cout << "Sales Destructor Call Thayo" << endl;
    }
};

int Sales::total_sales = 0;


class Academics : public Book {
private:
    char subject[30];
    static int total_academic;

public:
    Academics(int b_id, const char* b_name, const char* sub) : Book(b_id, b_name) {
        strcpy(subject, sub);
        total_academic++;
        cout << "Academics Constructor Call Thayo" << endl;
    }

    void displayAcademic() {
        displayBook();
        cout << ", Subject: " << subject << endl;
    }

    static int getTotalAcademic() {
        return total_academic;
    }

    ~Academics() {
        cout << "Academics Destructor Call Thayo" << endl;
    }
};

int Academics::total_academic = 0;


class Thrillers : public Book {
private:
    char genre[30];
    static int total_thriller;

public:
    Thrillers(int b_id, const char* b_name, const char* g) : Book(b_id, b_name) {
        strcpy(genre, g);
        total_thriller++;
        cout << "Thrillers Constructor Call Thayo" << endl;
    }

    void displayThriller() {
        displayBook();
        cout << ", Genre: " << genre << endl;
    }

    static int getTotalThriller() {
        return total_thriller;
    }

    ~Thrillers() {
        cout << "Thrillers Destructor Call Thayo" << endl;
    }
};

int Thrillers::total_thriller = 0;


int main() {
    cout << "\n--- Creating Objects ---" << endl;
    Sales s1(101, "Business Book", 500);
    Academics a1(201, "C++ Book", "Computer");
    Thrillers t1(301, "Mystery Book", "Suspense");

    cout << "\n--- Book Details ---" << endl;
    s1.displaySales();
    a1.displayAcademic();
    t1.displayThriller();

    cout << "\n--- Total Counts ---" << endl;
    cout << "Total Sales Books     : " << Sales::getTotalSales() << endl;
    cout << "Total Academic Books  : " << Academics::getTotalAcademic() << endl;
    cout << "Total Thriller Books  : " << Thrillers::getTotalThriller() << endl;
    cout << "Grand Total Books     : " << Book::getTotalBooks() << endl;

    cout << "\n--- Program Ends (Destructors Call) ---" << endl;
    return 0;
}
