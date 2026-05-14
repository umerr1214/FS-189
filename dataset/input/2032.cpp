#include <iostream>
#include <string>
#include <vector> // Allowed for storage, not direct management

// Assuming Book class from Q1
class Book {
public:
    std::string title;
    std::string author;
    int publicationYear;

    Book(std::string t = "", std::string a = "", int y = 0)
        : title(t), author(a), publicationYear(y) {}

    void display() const {
        std::cout << "Title: " << title << ", Author: " << author
                  << ", Year: " << publicationYear << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

class Library {
private:
    Book* books;
    int capacity;
    int numBooks;

public:
    Library(int cap) : capacity(cap), numBooks(0) {
        books = new Book[capacity];
    }

    ~Library() {
        delete[] books;
    }

    void addBook(const Book& book) {
        if (numBooks < capacity) {
            books[numBooks++] = book;
        } else {
            std::cout << "Library is full. Cannot add more books." << std::endl;
        }
    }

    void displayAllBooks() const {
        if (numBooks == 0) {
            std::cout << "Library is empty." << std::endl;
            return;
        }
        std::cout << "--- Library Books ---" << std::endl;
        for (int i = 0; i < numBooks; ++i) {
            books[i].display();
        }
        std::cout << "---------------------" << std::endl;
    }
};

int main() {
    Library myLibrary(5); // Capacity of 5 books

    myLibrary.addBook(Book("The Hobbit", "J.R.R. Tolkien", 1937));
    myLibrary.addBook(Book("1984", "George Orwell", 1949));
    myLibrary.addBook(Book("Brave New World", "Aldous Huxley", 1932));

    myLibrary.displayAllBooks();

    myLibrary.addBook(Book("Foundation", "Isaac Asimov", 1951));
    myLibrary.addBook(Book("Dune", "Frank Herbert", 1965));
    myLibrary.addBook(Book("Neuromancer", "William Gibson", 1984));

    myLibrary.displayAllBooks();

    return 0;
}