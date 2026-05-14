#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int isbn_numerical; // SEMANTIC ERROR: ISBN should be a string, but is stored as an int

public:
    // Constructor
    Book(const std::string& title, const std::string& author, const std::string& isbn_str)
        : title(title), author(author) {
        // SEMANTIC ERROR: Converts string ISBN to its length for storage, losing actual ISBN data
        this->isbn_numerical = isbn_str.length();
    }

    // Method to display details
    void displayDetails() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn_numerical << std::endl; // Prints the integer length
    }
};

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    book1.displayDetails();
    std::cout << "---" << std::endl;
    Book book2("1984", "George Orwell", "978-0451524935");
    book2.displayDetails();
    return 0;
}