#include <iostream>
#include <string>

// Define a C++ class named Book
class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Implement public methods to setTitle, setAuthor, setISBN
    // Robustness Issue: No input validation in setters.
    // Allows setting empty strings or malformed ISBNs, which might be
    // considered invalid data in a robust system.
    void setTitle(std::string t) {
        title = t;
    }

    void setAuthor(std::string a) {
        author = a;
    }

    void setISBN(std::string i) {
        isbn = i;
    }

    // Implement displayBookInfo which prints all details.
    // This method simply prints whatever is stored, even if it's invalid or empty,
    // without any special handling or indication of data quality.
    void displayBookInfo() const {
        std::cout << "Title: " << title << "\n";
        std::cout << "Author: " << author << "\n";
        std::cout << "ISBN: " << isbn << "\n";
    }
};

int main() {
    Book myBook;
    myBook.setTitle("The Hitchhiker's Guide to the Galaxy");
    myBook.setAuthor("Douglas Adams");
    myBook.setISBN("978-0345391803");
    myBook.displayBookInfo();

    std::cout << "\n"; // Separator for clarity in output

    Book anotherBook;
    anotherBook.setTitle("1984");
    anotherBook.setAuthor("George Orwell");
    anotherBook.setISBN("978-0451524935");
    anotherBook.displayBookInfo();

    // Demonstrating the robustness issue: setting problematic data
    std::cout << "\n";
    Book problematicBook;
    problematicBook.setTitle(""); // Empty title allowed
    problematicBook.setAuthor("Unknown");
    problematicBook.setISBN("INVALID-ISBN"); // Malformed ISBN allowed
    problematicBook.displayBookInfo();

    return 0;
}