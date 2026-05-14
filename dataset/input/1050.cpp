#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Semantic Error: Setters declare local variables with the same name as the parameters,
    // shadowing the member variables. The member variables remain unassigned.
    void setTitle(std::string newTitle) {
        std::string title = newTitle; // This creates a local variable 'title', not assigning to 'this->title'
    }

    void setAuthor(std::string newAuthor) {
        std::string author = newAuthor; // This creates a local variable 'author'
    }

    void setISBN(std::string newISBN) {
        std::string isbn = newISBN; // This creates a local variable 'isbn'
    }

    void displayBookInfo() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book myBook;
    myBook.setTitle("The Hobbit");
    myBook.setAuthor("J.R.R. Tolkien");
    myBook.setISBN("978-0345339683");

    // Due to the semantic error in setters, these will likely print empty strings
    // or default-constructed strings, not the values passed in setTitle/Author/ISBN.
    myBook.displayBookInfo();

    return 0;
}