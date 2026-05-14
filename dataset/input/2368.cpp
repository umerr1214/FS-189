#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor - SYNTAX ERROR: 'string' not declared in this scope without 'std::'
    Book(const string& title, const string& author, const string& isbn)
        : title(title), author(author), isbn(isbn) {}

    // Method to display details
    void displayDetails() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    book1.displayDetails();
    return 0;
}