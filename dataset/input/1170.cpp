#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor
    Book(std::string t = "", std::string a = "", std::string i = "") : title(t), author(a), isbn(i) {}

    // Getter for title (Semantic Error: Returns a non-const reference, breaking encapsulation)
    std::string& getTitle() { // Should ideally be `const std::string& getTitle() const` or `std::string getTitle() const`
        return title;
    }

    // Setter for title
    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    // Getter for author
    std::string getAuthor() const {
        return author;
    }

    // Setter for author
    void setAuthor(const std::string& newAuthor) {
        author = newAuthor;
    }

    // Getter for ISBN
    std::string getISBN() const {
        return isbn;
    }

    // Setter for ISBN
    void setISBN(const std::string& newISBN) {
        isbn = newISBN;
    }
};

int main() {
    Book myBook("Dune", "Frank Herbert", "978-0441172719");

    std::cout << "Initial Book Details:" << std::endl;
    std::cout << "Title: " << myBook.getTitle() << std::endl;
    std::cout << "Author: " << myBook.getAuthor() << std::endl;
    std::cout << "ISBN: " << myBook.getISBN() << std::endl;

    // Demonstrating the semantic error: modifying a private member via a non-const getter
    myBook.getTitle() = "Dune Messiah"; // This directly modifies the private 'title' member

    myBook.setAuthor("Brian Herbert & Kevin J. Anderson");
    myBook.setISBN("978-0765307301");

    std::cout << "\nUpdated Book Details (after direct modification via getter):" << std::endl;
    std::cout << "Title: " << myBook.getTitle() << std::endl; // Will show "Dune Messiah"
    std::cout << "Author: " << myBook.getAuthor() << std::endl;
    std::cout << "ISBN: " << myBook.getISBN() << std::endl;

    return 0;
}