#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor (optional, but good practice)
    Book(std::string t = "", std::string a = "", std::string i = "") : title(t), author(a), isbn(i) {}

    // Getter for title
    std::string getTitle() const {
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
} // Missing semicolon here, causing a syntax error

int main() {
    Book myBook("The Great Adventure", "Jane Doe", "978-0123456789");

    std::cout << "Initial Book Details:" << std::endl;
    std::cout << "Title: " << myBook.getTitle() << std::endl;
    std::cout << "Author: " << myBook.getAuthor() << std::endl;
    std::cout << "ISBN: " << myBook.getISBN() << std::endl;

    myBook.setTitle("The New Journey");
    myBook.setAuthor("John Smith");
    myBook.setISBN("978-9876543210");

    std::cout << "\nUpdated Book Details:" << std::endl;
    std::cout << "Title: " << myBook.getTitle() << std::endl;
    std::cout << "Author: " << myBook.getAuthor() << std::endl;
    std::cout << "ISBN: " << myBook.getISBN() << std::endl;

    return 0;
}