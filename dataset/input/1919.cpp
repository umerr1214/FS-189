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
        // Logical error: setting isbn instead of title
        isbn = t; 
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
};

int main() {
    Book myBook;
    myBook.setTitle("The Great Gatsby"); // This call will incorrectly set the ISBN
    myBook.setAuthor("F. Scott Fitzgerald");
    myBook.setIsbn("978-0743273565"); // This will then overwrite the ISBN set by setTitle

    std::cout << "Title: " << myBook.getTitle() << std::endl; // Title will be empty
    std::cout << "Author: " << myBook.getAuthor() << std::endl;
    std::cout << "ISBN: " << myBook.getIsbn() << std::endl;

    return 0;
}