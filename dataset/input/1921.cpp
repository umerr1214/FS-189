#include <iostream>
#include <string>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book() : title(""), author(""), isbn("") {}
    Book(const std::string& t, const std::string& a, const std::string& i)
        : title(t), author(a), isbn(i) {}

    // Setters - these are generally fine
    void setTitle(const std::string& t) { title = t; }
    void setAuthor(const std::string& a) { author = a; }
    void setIsbn(const std::string& i) { isbn = i; }

    // Getters - Robustness issue: returning non-const reference
    // This allows external code to directly modify private members, breaking encapsulation.
    std::string& getTitle() { return title; }
    std::string& getAuthor() { return author; }
    std::string& getIsbn() { return isbn; }
};

int main() {
    Book myBook("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    std::cout << "Original Book:" << std::endl;
    std::cout << "Title: " << myBook.getTitle() << std::endl;
    std::cout << "Author: " << myBook.getAuthor() << std::endl;
    std::cout << "ISBN: " << myBook.getIsbn() << std::endl;

    // Demonstrate robustness issue: modifying internal state via getter
    myBook.getTitle() = "A New Title"; // Directly modifies 'title'
    myBook.getAuthor().append(" (Modified)"); // Appends to 'author'
    myBook.setIsbn().replace(0, 3, "XXX"); // Replaces part of 'isbn'

    std::cout << "\nModified Book (via 'robustness issue' getters):" << std::endl;
    std::cout << "Title: " << myBook.getTitle() << std::endl;
    std::cout << "Author: " << myBook.getAuthor() << std::endl;
    std::cout << "ISBN: " << myBook.getIsbn() << std::endl;

    return 0;
}