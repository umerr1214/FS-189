#include <iostream>
#include <string>
#include <utility> // For std::move

class Book {
private:
    std::string title;
    std::string author;

public:
    // Constructor
    Book(std::string title, std::string author)
        : title(std::move(title)), author(std::move(author)) {}

    const std::string& getTitle() const { return title; }
    const std::string& getAuthor() const { return author; }

    // No friend declaration needed if operator<< is not a friend
    // but it's good practice to declare it, or make getters public.
    // For this example, we make getters public.
};

// Overload the << operator for Book objects - Readability/Efficiency Issue
std::ostream& operator<<(std::ostream& os, const Book& book) {
    // READABILITY/EFFICIENCY ISSUE:
    // 1. Inefficient string concatenation: Creates a large temporary std::string
    //    by concatenating multiple strings before streaming it to `os`.
    //    Direct streaming (`os << "Title: " << book.getTitle()`) is more efficient.
    // 2. Excessive use of `std::endl`: `std::endl` not only inserts a newline
    //    character but also flushes the output buffer. Flushing on every print
    //    can significantly reduce performance, especially in loops. Using `'\n'`
    //    is generally preferred unless an immediate flush is strictly required.
    os << "Title: " + book.getTitle() + ", Author: " + book.getAuthor() + "." << std::endl;
    return os;
}

int main() {
    // Test case 1: Basic printing
    Book book1("1984", "George Orwell");
    std::cout << "Book 1: " << book1; // operator<< already adds std::endl

    // Test case 2: Another book
    Book book2("To Kill a Mockingbird", "Harper Lee");
    std::cout << "Book 2: " << book2;

    // Test case 3: Yet another book
    Book book3("Pride and Prejudice", "Jane Austen");
    std::cout << "Book 3: " << book3;

    // Test case 4: Book with empty title/author
    Book book4("", "");
    std::cout << "Empty Book: " << book4;

    return 0;
}