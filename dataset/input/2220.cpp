#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i) {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getIsbn() const { return isbn; }

    void displayBookInfo() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book myBook("The Lord of the Rings", "J.R.R. Tolkien", "978-0618053267");
    // Semantic error: Attempting to access private member directly
    std::cout << "Book Title (direct access): " << myBook.title << std::endl;
    myBook.displayBookInfo();
    return 0;
}