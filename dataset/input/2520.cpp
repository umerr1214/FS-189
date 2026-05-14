#include <iostream>
#include <string>

class Book {
// SEMANTIC ERROR: Attributes are public, violating data encapsulation
public:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(const std::string& t, const std::string& a, const std::string& i)
        : title(t), author(a), isbn(i) {}

    void displayDetails() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book myBook("Pride and Prejudice", "Jane Austen", "978-0141439518");
    myBook.displayDetails();

    // Demonstrate the violation of encapsulation
    std::cout << "\nAccessing attributes directly (semantic error demonstration):" << std::endl;
    myBook.title = "New Title"; // Direct modification possible due to public attributes
    std::cout << "Modified Title: " << myBook.title << std::endl;

    return 0;
}