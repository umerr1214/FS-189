#include <string>
#include <iostream>

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;

    // Correct parameterized constructor
    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i) {}

    void display() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book book1("1984", "George Orwell", "978-0451524935");
    // Semantic error in usage demonstration:
    // The ISBN is immediately overwritten after construction.
    // While the constructor correctly initializes 'isbn', this subsequent action
    // makes the 'isbn' parameter passed to the constructor semantically useless
    // for the final displayed state of the object, contradicting the
    // demonstration of the constructor's initialization purpose.
    book1.isbn = "UNKNOWN";

    book1.display();
    return 0;
}