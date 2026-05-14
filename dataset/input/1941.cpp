#include <iostream>
#include <string>    // For std::string
#include <vector>    // For std::vector
#include <utility>   // For std::move

// This is the correct and idiomatic C++ version.
// It uses std::string for title management, which handles memory automatically,
// making the code safer, more readable, and more efficient.
class Book {
private:
    std::string title; // Using std::string for automatic memory management
    int id;            // Unique ID for each book instance

public:
    // Constructor using std::string and initializer list
    // std::move is used for efficiency when `t` is a temporary or can be moved from.
    Book(std::string t, int bookId) : title(std::move(t)), id(bookId) {
        std::cout << "Book '" << title << "' (ID: " << id << ") constructed." << std::endl;
    }

    // Destructor as per question
    // No manual memory deallocation is needed for `title` because std::string
    // manages its own memory automatically.
    ~Book() {
        std::cout << "Book '" << title << "' (ID: " << id << ") is being destroyed." << std::endl;
    }

    // No need for user-defined copy constructor, copy assignment operator,
    // or move constructor/assignment operator because `std::string` handles
    // its own resources correctly, and the compiler-generated member-wise
    // copy/move operations will work perfectly. This adheres to the Rule of Zero/Five.

    const std::string& getTitle() const {
        return title;
    }
};

// Function to demonstrate various object lifecycles
void demonstrateBookLifecycles() {
    // Stack-allocated object (destroyed when function exits)
    Book book1("The Lord of the Rings", 201);

    // Block scope destruction
    {
        Book book2("The Hitchhiker's Guide to the Galaxy", 202);
        std::cout << "Inside block scope." << std::endl;
    } // book2 is destroyed here

    // Dynamic allocation (requires explicit delete)
    Book* bookPtr = new Book("Dune", 203);
    std::cout << "Dynamically allocated book created." << std::endl;
    delete bookPtr; // The object pointed to by bookPtr is destroyed here

    // Objects in a container (destroyed when container goes out of scope)
    std::vector<Book> library;
    library.reserve(2); // Pre-allocate to avoid reallocations that might involve extra copies/moves
    library.emplace_back("Foundation", 204); // Constructs Book directly in vector
    library.push_back(Book("I, Robot", 205)); // Constructs temporary Book, then moves/copies into vector
    std::cout << "Vector populated." << std::endl;

} // book1 is destroyed here, then library elements (204, 205) are destroyed in reverse order

int main() {
    std::cout << "--- Starting Correct Version Test ---" << std::endl;
    demonstrateBookLifecycles();
    std::cout << "--- Correct Version Test Ended ---" << std::endl;
    return 0;
}