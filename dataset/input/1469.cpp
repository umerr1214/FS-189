#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor
    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i) {}

    // Getter methods
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getIsbn() const { return isbn; }

    // Display method with a logical error
    void displayBookInfo() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << title << std::endl; // LOGICAL ERROR: Prints title instead of author
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    std::cout << "--- Displaying Book Info (Logical Error) ---" << std::endl;
    book1.displayBookInfo();

    std::cout << "\n--- Book details via getters (Correct) ---" << std::endl;
    std::cout << "Title: " << book1.getTitle() << std::endl;
    std::cout << "Author: " << book1.getAuthor() << std::endl;
    std::cout << "ISBN: " << book1.getIsbn() << std::endl;

    return 0;
}