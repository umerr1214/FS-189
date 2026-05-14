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

    // Getter methods (getTitle and getAuthor are correct)
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    
    // SEMANTIC ERROR: getIsbn() returns a non-const reference, allowing external modification.
    // This compiles, but semantically violates the "getter" purpose and encapsulation.
    std::string& getIsbn() { return isbn; } 

    // Display method
    void displayBookInfo() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book book1("1984", "George Orwell", "978-0451524935");
    
    std::cout << "--- Initial Book Info ---" << std::endl;
    book1.displayBookInfo();

    // Demonstrating the semantic error: modifying a private member via a non-const getter
    book1.getIsbn() = "NEW-ISBN-12345";
    std::cout << "\n--- Book Info after modifying ISBN via getter (Semantic Error) ---" << std::endl;
    book1.displayBookInfo();

    return 0;
}