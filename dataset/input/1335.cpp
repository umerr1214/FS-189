#include <iostream>
#include <string>
#include <vector> // For demonstrating usage with std::vector

class Book {
public:
    std::string title;
    std::string author;

    // Default constructor - uses member initializer list for efficiency and clarity
    Book() : title("Unknown Title"), author("Unknown Author") {
    }

    // Parameterized constructor - uses const std::string& for efficiency and member initializer list
    Book(const std::string& t, const std::string& a) : title(t), author(a) {
    }

    // Copy constructor - uses member initializer list
    Book(const Book& other) : title(other.title), author(other.author) {
    }

    // Getters - return const reference for efficiency and const correctness
    const std::string& getTitle() const {
        return title;
    }

    const std::string& getAuthor() const {
        return author;
    }

    // Print method - const correct
    void print() const {
        std::cout << "Book: \"" << title << "\" by " << author << std::endl;
    }
};

int main() {
    // 1. Default constructor
    Book book1;
    std::cout << "Book 1 (Default): ";
    book1.print();

    // 2. Parameterized constructor
    Book book2("The Hobbit", "J.R.R. Tolkien");
    std::cout << "Book 2 (Parameterized): ";
    book2.print();

    // 3. Copy constructor
    Book book3 = book2; // Calls copy constructor
    std::cout << "Book 3 (Copy of Book 2): ";
    book3.print();

    // Another way to use parameterized constructor
    Book book4("Pride and Prejudice", "Jane Austen");
    std::cout << "Book 4 (Parameterized): ";
    book4.print();

    // Create a vector of books to demonstrate various constructions
    std::cout << "\nCreating a vector of books:" << std::endl;
    std::vector<Book> library;
    library.push_back(Book()); // Default constructor
    library.push_back(Book("Dune", "Frank Herbert")); // Parameterized constructor
    library.push_back(book2); // Copy constructor
    library.emplace_back("To Kill a Mockingbird", "Harper Lee"); // Efficient parameterized construction

    for (size_t i = 0; i < library.size(); ++i) {
        std::cout << "Library Book " << i + 1 << ": ";
        library[i].print();
    }

    return 0;
}