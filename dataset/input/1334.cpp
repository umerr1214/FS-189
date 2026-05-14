#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;

    // Default constructor - Readability/Efficiency: Initializes in body instead of initializer list
    Book() {
        this->title = "Default Title"; // Verbose 'this->'
        this->author = "Default Author"; // Verbose 'this->'
    }

    // Parameterized constructor - Efficiency: Passes std::string by value, causing an unnecessary copy
    Book(std::string t, std::string a) { // t and a are copies
        this->title = t; // Another copy (assignment)
        this->author = a; // Another copy (assignment)
    }

    // Copy constructor - Readability: Explicitly uses this-> unnecessarily
    Book(const Book& other) {
        this->title = other.title;
        this->author = other.author;
    }

    // Getters (not the primary issue here, but keeping consistent with other versions)
    const std::string& getTitle() const {
        return this->title; // Verbose 'this->'
    }

    const std::string& getAuthor() const {
        return this->author; // Verbose 'this->'
    }

    void print() const {
        std::cout << "Book: \"" << this->title << "\" by " << this->author << std::endl; // Verbose 'this->'
    }
};

int main() {
    // 1. Default constructor
    Book book1;
    std::cout << "Book 1 (Default): ";
    book1.print();

    // 2. Parameterized constructor
    // This will involve extra copies due to passing by value
    Book book2("1984", "George Orwell");
    std::cout << "Book 2 (Parameterized): ";
    book2.print();

    // 3. Copy constructor
    Book book3 = book2; // Calls copy constructor
    std::cout << "Book 3 (Copy of Book 2): ";
    book3.print();

    // Another parameterized constructor call to highlight efficiency issue
    std::cout << "\nCreating another book with parameterized constructor:" << std::endl;
    Book book4("Brave New World", "Aldous Huxley");
    std::cout << "Book 4 (Parameterized): ";
    book4.print();

    return 0;
}