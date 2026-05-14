#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Public constructor using const references for efficiency and an initializer list for optimal initialization.
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {
        // Constructor body can be empty as members are initialized in the initializer list.
    }

    // Public method to display book details. Marked const as it does not modify the object's state,
    // ensuring const-correctness. Uses '\n' for efficient line breaks.
    void displayDetails() const {
        std::cout << "Book Details:\n";
        std::cout << "Title: " << title << "\n";
        std::cout << "Author: " << author << "\n";
        std::cout << "ISBN: " << isbn << "\n";
    }
};

int main() {
    // Create a Book object and display its details
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    book1.displayDetails();
    std::cout << "---\n";

    // Create another Book object with different details
    Book book2("Pride and Prejudice", "Jane Austen", "978-0141439518");
    book2.displayDetails();
    std::cout << "---\n";

    // Test with empty strings (should work correctly)
    Book book3("Empty Title", "", "No ISBN");
    book3.displayDetails();

    return 0;
}