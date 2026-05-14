#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;

    // Default constructor to ensure objects can be created without initial parameters.
    Book() : title(""), author(""), isbn("") {}

    // Parameterized constructor:
    // Accepts title, author, and isbn by const reference to avoid unnecessary copies
    // when arguments are lvalues. Members are initialized efficiently using an initializer list.
    Book(const std::string& t, const std::string& a, const std::string& i)
        : title(t), author(a), isbn(i) {
        // All members are directly initialized here.
    }

    // display method is const-qualified, indicating it does not modify the object's state.
    void display() const {
        std::cout << "Title: " << title << "\n";
        std::cout << "Author: " << author << "\n";
        std::cout << "ISBN: " << isbn << "\n";
    }
};

int main() {
    // Demonstrate usage of the parameterized constructor
    Book book1("The C++ Programming Language", "Bjarne Stroustrup", "978-0321563842");
    book1.display();

    Book book2("Effective C++", "Scott Meyers", "978-0321334879");
    book2.display();

    // Demonstrate default constructor (optional but good practice)
    Book book3;
    // book3.display(); // Would print empty strings

    return 0;
}