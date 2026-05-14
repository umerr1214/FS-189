#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(std::string title, std::string author, std::string isbn)
        : title(title), author(author), isbn(isbn) {}

    // Getters
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getIsbn() const { return isbn; }

    // Setters
    void setTitle(std::string newTitle) {
        if (newTitle.empty()) {
            std::cout << "Error: Title cannot be empty." << std::endl;
            return;
        }
        title = newTitle;
    }

    void setAuthor(std::string newAuthor) {
        author = newAuthor;
    }

    void setIsbn(std::string newIsbn) {
        isbn = newIsbn;
    }
}; // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Book myBook("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    std::cout << "Initial Book: " << myBook.getTitle() << ", " << myBook.getAuthor() << ", " << myBook.getIsbn() << std::endl;

    myBook.setTitle("New Title");
    myBook.setAuthor("New Author");
    myBook.setIsbn("New ISBN");
    std::cout << "Updated Book: " << myBook.getTitle() << ", " << myBook.getAuthor() << ", " << myBook.getIsbn() << std::endl;

    myBook.setTitle(""); // Attempt to set empty title
    std::cout << "After empty title attempt: " << myBook.getTitle() << std::endl;

    return 0;
}