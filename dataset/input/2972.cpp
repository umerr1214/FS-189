#include <iostream> // Required for std::cout
#include <string>   // Required for std::string

// Class definition for Book, demonstrating readability and efficiency issues
class Book {
private:
    // Member names are short and not very descriptive, impacting readability.
    std::string _t; // Represents title
    std::string _a; // Represents author
    std::string _i; // Represents ISBN

public:
    // Parameterized constructor:
    // Passes string parameters by value, which creates temporary copies for each argument.
    // Then, these temporary copies are assigned to the member variables (using 'this->'),
    // leading to another copy operation. This results in two copy operations for each string,
    // which is less efficient than passing by const reference and using an initializer list,
    // or using pass-by-value with std::move.
    Book(std::string title, std::string author, std::string isbn) {
        this->_t = title;
        this->_a = author;
        this->_i = isbn;
    }

    // Public method to display all book details:
    // Uses 'this->' explicitly for member access, which is often considered redundant
    // and can slightly reduce readability in simple cases.
    // Uses std::endl for each line, which flushes the output buffer on every call.
    // This can be less efficient than using '\n' for newlines, especially in loops
    // or when printing many lines, as flushing is an expensive operation.
    void displayBookInfo() {
        std::cout << "Title: " << this->_t << std::endl;
        std::cout << "Author: " << this->_a << std::endl;
        std::cout << "ISBN: " << this->_i << std::endl;
    }
};

int main() {
    // Create an instance of the Book class
    Book book1("The Martian", "Andy Weir", "978-0553448138");

    // Call the method to display its information
    book1.displayBookInfo();

    return 0;
}