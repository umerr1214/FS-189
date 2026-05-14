#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Semantic Error: Constructor parameters shadow member variables.
    // The member variables 'title', 'author', 'isbn' are default-constructed (empty strings)
    // and are not initialized with the constructor arguments due to shadowing.
    Book(std::string title, std::string author, std::string isbn) {
        title = title;   // Assigns parameter 'title' to itself
        author = author; // Assigns parameter 'author' to itself
        isbn = isbn;     // Assigns parameter 'isbn' to itself
    }

    void displayInfo() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    book1.displayInfo();
    std::cout << "---" << std::endl;
    Book book2("1984", "George Orwell", "978-0451524935");
    book2.displayInfo();
    return 0;
}