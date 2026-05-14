#include <iostream>
#include <string>
#include <utility> // Required for std::move

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;

    // Default constructor
    Book() : title(""), author(""), isbn("") {}

    // Parameterized constructor with a robustness issue:
    // Parameters are passed by value, leading to an extra copy for lvalue arguments.
    // While std::move is used in the initializer list, the initial copy to the parameter
    // itself is still made, which can be inefficient for large strings.
    Book(std::string t, std::string a, std::string i)
        : title(std::move(t)), author(std::move(a)), isbn(std::move(i)) {
        // The strings t, a, i are already copies of the arguments passed.
        // Moving from them here is fine, but the initial copy to them is the robustness/efficiency concern.
    }

    void display() const {
        std::cout << "Title: " << title << "\n";
        std::cout << "Author: " << author << "\n";
        std::cout << "ISBN: " << isbn << "\n";
    }
};

int main() {
    Book book1("The C++ Programming Language", "Bjarne Stroustrup", "978-0321563842");
    book1.display();

    Book book2("Effective C++", "Scott Meyers", "978-0321334879");
    book2.display();

    return 0;
}