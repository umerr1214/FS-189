#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    Book(std::string t) : title(t) {
        std::cout << "Book '" << title << "' created." << std::endl;
    }
    ~Book() {
        // Syntax error: missing semicolon after std::endl
        std::cout << "Book '" << title << "' is being destroyed" << std::endl
    }
};

void run_test() {
    {
        Book b1("The Great Gatsby");
    } // b1 goes out of scope, destructor should be called
    {
        Book b2("1984");
    } // b2 goes out of scope, destructor should be called
    std::cout << "End of main scope." << std::endl;
}

int main() {
    run_test();
    return 0;
}