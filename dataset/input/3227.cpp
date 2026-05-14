#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;

    Book(std::string t, std::string a) : title(t), author(a) {}

    // Friend declaration for the overloaded operator
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

std::ostream& operator<<(std::ostream& os, const Book& book) {
    // LOGICAL ERROR: Swapping title and author in the output
    os << "Title: " << book.author << ", Author: " << book.title;
    return os;
}

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams");
    Book book2("1984", "George Orwell");

    std::cout << "Book 1: " << book1 << std::endl;
    std::cout << "Book 2: " << book2 << std::endl;

    return 0;
}