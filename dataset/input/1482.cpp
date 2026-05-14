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
    void setTitle(std::string title) { // Parameter 'title' shadows member 'title'
        if (title.empty()) { // Refers to parameter 'title'
            std::cout << "Error: Title cannot be empty." << std::endl;
            return;
        }
        this->title = title; // SEMANTIC ERROR: Should be 'this->title = title;' to update member. Or use different parameter name.
                             // The original error was 'title = title;', which assigns parameter to itself.
                             // Correcting to 'this->title = title;' to demonstrate the fix, but the error is that the original was 'title = title;'.
                             // Let's revert to 'title = title;' to show the semantic error more clearly.
    }

    void setAuthor(std::string author) { // Parameter 'author' shadows member 'author'
        author = author; // SEMANTIC ERROR: Assigns parameter 'author' to itself, member 'author' is not updated.
    }

    void setIsbn(std::string isbn) { // Parameter 'isbn' shadows member 'isbn'
        isbn = isbn; // SEMANTIC ERROR: Assigns parameter 'isbn' to itself, member 'isbn' is not updated.
    }
};

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