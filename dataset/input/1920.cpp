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
};

int main() {
    Book myBook;
    myBook.setTitle("To Kill a Mockingbird");
    myBook.setAuthor("Harper Lee");
    myBook.setIsbn("978-0061120084");

    // Semantic error: attempting to access private member 'title' directly
    std::cout << "Title: " << myBook.title << std::endl; 
    std::cout << "Author: " << myBook.getAuthor() << std::endl;
    std::cout << "ISBN: " << myBook.getIsbn() << std::endl;

    return 0;
}