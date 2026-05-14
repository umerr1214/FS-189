#include <iostream>
#include <string>
#include <utility> // For std::move if using move constructor pattern

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Correct Version:
    // Constructor uses const std::string& for efficiency, avoiding unnecessary copies.
    // Members are initialized using an initializer list for optimal performance and direct initialization.
    Book(const std::string& title_val, const std::string& author_val, const std::string& isbn_val)
        : title(title_val), author(author_val), isbn(isbn_val) {
        // Constructor body can be empty or used for additional validation/logic if needed.
    }

    // displayInfo method is const-qualified as it does not modify the object's state,
    // adhering to const-correctness best practices.
    void displayInfo() const {
        std::cout << "Book Details:" << std::endl;
        std::cout << "  Title:  " << title << std::endl;
        std::cout << "  Author: " << author << std::endl;
        std::cout << "  ISBN:   " << isbn << std::endl;
    }
};

int main() {
    Book book1("The Lord of the Rings", "J.R.R. Tolkien", "978-0618260274");
    book1.displayInfo();
    std::cout << "---" << std::endl;

    Book book2("To Kill a Mockingbird", "Harper Lee", "978-0061120084");
    book2.displayInfo();
    std::cout << "---" << std::endl;

    Book book3("", "Unknown", ""); // Handles empty strings gracefully
    book3.displayInfo();
    std::cout << "---" << std::endl;

    return 0;
}