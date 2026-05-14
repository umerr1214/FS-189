#include <iostream>
#include <string>
#include <stdexcept> // Not used for robustness issue, but good practice to include

// Book class from Q1
class Book {
public:
    std::string title;
    std::string author;
    int year;

    // Default constructor
    Book(std::string t = "", std::string a = "", int y = 0) : title(t), author(a), year(y) {}

    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << ", Year: " << year << std::endl;
    }
};

// Library class with robustness issue (buffer overflow)
class Library {
private:
    static const int MAX_BOOKS = 3; // Fixed maximum capacity
    Book books[MAX_BOOKS];          // Simple fixed-size array
    int count;                      // Current number of books

public:
    Library() : count(0) {}

    // Method to add a book - does not check for capacity, leading to buffer overflow
    void addBook(const Book& book) {
        std::cout << "Attempting to add: " << book.title << std::endl;
        books[count++] = book; // Potential buffer overflow if count >= MAX_BOOKS
    }

    // Method to display all books
    void displayAllBooks() const {
        if (count == 0) {
            std::cout << "Library is empty." << std::endl;
            return;
        }
        std::cout << "--- Library Books ---" << std::endl;
        for (int i = 0; i < count; ++i) {
            books[i].display();
        }
        std::cout << "---------------------" << std::endl;
    }
};

int main() {
    Library myLibrary;

    myLibrary.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));
    myLibrary.addBook(Book("1984", "George Orwell", 1949));
    myLibrary.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    
    // This next add will cause a buffer overflow as MAX_BOOKS is 3
    myLibrary.addBook(Book("Brave New World", "Aldous Huxley", 1932)); 

    myLibrary.displayAllBooks();

    return 0;
}