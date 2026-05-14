#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {}

    // Method to display details - LOGICAL ERROR: Swapping author and ISBN in output
    void displayDetails() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << isbn << std::endl; // Should print 'author'
        std::cout << "ISBN: " << author << std::endl; // Should print 'isbn'
    }
};

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    book1.displayDetails();
    std::cout << "---" << std::endl;
    Book book2("1984", "George Orwell", "978-0451524935");
    book2.displayDetails();
    return 0;
}