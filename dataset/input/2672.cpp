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
    // Readability/Efficiency Issue: Passing std::string by value causes unnecessary copying.
    // Also, parameter names (t, a, i) are not very descriptive.
    void setTitle(std::string t) { // Passes by value (inefficient)
        title = t;
    }

    void setAuthor(std::string a) { // Passes by value (inefficient)
        author = a;
    }

    void setISBN(std::string i) { // Passes by value (inefficient)
        isbn = i;
    }

    // Implement displayBookInfo which prints all details.
    // Readability/Efficiency Issue: Uses std::endl for every line, causing
    // unnecessary buffer flushes, which can be less efficient than using '\n'.
    // Also, the method is not marked 'const' despite not modifying member variables.
    void displayBookInfo() { // Not marked const (minor quality issue)
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
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