#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Parameterized constructor using initializer list and const references for efficiency
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {}

    // Public method to display book details, marked const as it doesn't modify object state
    void displayDetails() const {
        std::cout << "Book Details:" << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    book1.displayDetails();
    std::cout << "---" << std::endl;

    Book book2("1984", "George Orwell", "978-0451524935");
    book2.displayDetails();
    std::cout << "---" << std::endl;

    Book book3("The Lord of the Rings", "J.R.R. Tolkien", "978-0618260274");
    book3.displayDetails();
    std::cout << "---" << std::endl;

    return 0;
}