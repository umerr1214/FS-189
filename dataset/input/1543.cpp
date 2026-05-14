#include <iostream>
#include <string>
#include <vector> // Included for potential future use, not directly affecting current logic

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor using initializer list
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {
        // Robustness Issue: Weak ISBN validation.
        // A more robust system would check format, checksum, etc.
        // Here, it only checks if not empty, allowing malformed ISBNs to be stored.
        if (isbn.empty()) {
            std::cout << "Warning: ISBN cannot be empty. Book might be invalid." << std::endl;
        } else if (isbn.length() < 10 || isbn.length() > 17) { // Very basic length check, still non-robust
            std::cout << "Warning: ISBN length seems unusual. Book might be invalid." << std::endl;
        }
    }

    void display() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book b1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    b1.display();
    std::cout << "--------------------" << std::endl;

    // Test case demonstrating the robustness issue: an empty ISBN is allowed
    // and only a warning is printed, but the object is created.
    // A truly robust system might throw an exception or return a null object.
    Book b2("1984", "George Orwell", ""); // Empty ISBN
    b2.display();
    std::cout << "--------------------" << std::endl;

    // Another case: invalid format ISBN is allowed with a weak warning.
    Book b3("Brave New World", "Aldous Huxley", "123"); // Invalid format ISBN
    b3.display();
    std::cout << "--------------------" << std::endl;

    std::cout << "\nExplanation for initializer lists:" << std::endl;
    std::cout << "Initializer lists are preferred for several reasons:" << std::endl;
    std::cout << "1. Efficiency: Direct initialization avoids a default construction followed by an assignment." << std::endl;
    std::cout << "2. Const and Reference Members: They are the *only* way to initialize const data members and reference data members." << std::endl;
    std::cout << "3. Member Objects without Default Constructors: Members of classes that don't have a default constructor *must* be initialized via an initializer list." << std::endl;
    std::cout << "5. Exception Safety: If a member's constructor throws an exception, it happens before the main constructor body, potentially simplifying error handling." << std::endl;
    return 0;
}