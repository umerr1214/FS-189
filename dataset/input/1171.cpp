#include <iostream>
#include <string>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor
    Book(const std::string& initialTitle = "", const std::string& initialAuthor = "", const std::string& initialIsbn = "")
        : title(initialTitle), author(initialAuthor), isbn(initialIsbn) {}

    // Getter for title
    const std::string& getTitle() const {
        return title;
    }

    // Setter for title - no validation
    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    // Getter for author
    const std::string& getAuthor() const {
        return author;
    }

    // Setter for author - no validation
    void setAuthor(const std::string& newAuthor) {
        author = newAuthor;
    }

    // Getter for ISBN
    const std::string& getIsbn() const {
        return isbn;
    }

    // Setter for ISBN - no validation
    void setIsbn(const std::string& newIsbn) {
        isbn = newIsbn;
    }
};

int main() {
    // Test Case 1: Standard book creation
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565");
    std::cout << "Book 1 Details:" << std::endl;
    std::cout << "Title: " << book1.getTitle() << std::endl;
    std::cout << "Author: " << book1.getAuthor() << std::endl;
    std::cout << "ISBN: " << book1.getIsbn() << std::endl;
    std::cout << "---" << std::endl;

    // Test Case 2: Using setters with valid data
    Book book2;
    book2.setTitle("1984");
    book2.setAuthor("George Orwell");
    book2.setIsbn("978-0451524935");
    std::cout << "Book 2 Details:" << std::endl;
    std::cout << "Title: " << book2.getTitle() << std::endl;
    std::cout << "Author: " << book2.getAuthor() << std::endl;
    std::cout << "ISBN: " << book2.getIsbn() << std::endl;
    std::cout << "---" << std::endl;

    // Test Case 3: Robustness Issue - Setting empty strings
    Book book3("Valid Title", "Valid Author", "Valid ISBN");
    book3.setTitle(""); // Setting title to empty
    book3.setAuthor(" "); // Setting author to whitespace
    book3.setIsbn("");   // Setting ISBN to empty
    std::cout << "Book 3 Details (Robustness Test - Empty/Whitespace Input):" << std::endl;
    std::cout << "Title: '" << book3.getTitle() << "'" << std::endl; // Should be empty
    std::cout << "Author: '" << book3.getAuthor() << "'" << std::endl; // Should be whitespace
    std::cout << "ISBN: '" << book3.getIsbn() << "'" << std::endl;     // Should be empty
    std::cout << "---" << std::endl;

    // Test Case 4: Robustness Issue - Constructor with empty strings
    Book book4("", "", "");
    std::cout << "Book 4 Details (Robustness Test - Empty Constructor Input):" << std::endl;
    std::cout << "Title: '" << book4.getTitle() << "'" << std::endl;
    std::cout << "Author: '" << book4.getAuthor() << "'" << std::endl;
    std::cout << "ISBN: '" << book4.getIsbn() << "'" << std::endl;
    std::cout << "---" << std::endl;

    return 0;
}