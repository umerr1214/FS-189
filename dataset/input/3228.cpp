#include <iostream>
#include <string>

class Book {
private: // Members are private
    std::string title;
    std::string author;

public:
    Book(std::string t, std::string a) : title(t), author(a) {}

    // SEMANTIC ERROR: operator<< is NOT declared as a friend,
    // so it cannot access private members directly.
};

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "Title: " << book.title << ", Author: " << book.author; // Attempting to access private members
    return os;
}

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams");
    Book book2("1984", "George Orwell");

    std::cout << "Book 1: " << book1 << std::endl;
    std::cout << "Book 2: " << book2 << std::endl;

    return 0;
}