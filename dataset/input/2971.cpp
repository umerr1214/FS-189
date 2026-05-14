#include <iostream>
#include <string>

// Class definition for Book, demonstrating a robustness issue
class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Parameterized constructor:
    // This constructor accepts any string values, including empty ones, for essential fields.
    // From a business logic perspective, a book should ideally have a non-empty title, author, and ISBN.
    // The lack of validation for these crucial fields makes the class less robust,
    // as it allows the creation of "invalid" Book objects that might lead to
    // incomplete or misleading information being displayed.
    Book(std::string t, std::string a, std::string i) {
        title = t;
        author = a;
        isbn = i;
    }

    // Public method to display all book details:
    // This method will faithfully print whatever values are stored,
    // including empty strings if they were passed during construction.
    void displayBookInfo() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    // Demonstrating the robustness issue: creating a book with an empty ISBN.
    // The class allows this "invalid" state without any error or default handling.
    Book book1("The Martian", "Andy Weir", "");
    book1.displayBookInfo();

    std::cout << "\n--- Another book with empty title ---\n";
    // Another example: an empty title is also accepted.
    Book book2("", "Jane Doe", "123-456-7890");
    book2.displayBookInfo();

    return 0;
}