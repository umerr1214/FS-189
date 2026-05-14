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
    // Correct Version: Pass std::string by const reference for efficiency and best practice.
    // Use descriptive parameter names.
    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    void setAuthor(const std::string& newAuthor) {
        author = newAuthor;
    }

    void setISBN(const std::string& newISBN) {
        isbn = newISBN;
    }

    // Implement displayBookInfo which prints all details.
    // Correct Version: Uses '\n' for newlines for efficiency, and is marked 'const'
    // as it does not modify the object's state.
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

    return 0;
}