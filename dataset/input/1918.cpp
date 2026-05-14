#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Setters
    void setTitle(const std::string& t) {
        title = t;
    }
    void setAuthor(const std::string& a) {
        author = a;
    }
    void setIsbn(const std::string& i) {
        isbn = i;
    }

    // Getters
    std::string getTitle() const {
        return title;
    }
    std::string getAuthor() const {
        return author;
    }
    std::string getIsbn() const {
        return isbn;
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    Book myBook;
    myBook.setTitle("1984");
    myBook.setAuthor("George Orwell");
    myBook.setIsbn("978-0451524935");

    std::cout << "Title: " << myBook.getTitle() << std::endl;
    std::cout << "Author: " << myBook.getAuthor() << std::endl;
    std::cout << "ISBN: " << myBook.getIsbn() << std::endl;

    return 0;
}