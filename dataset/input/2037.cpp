#include <iostream>
#include <string>
#include <vector> // For std::string, not for collection management directly

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

// Library class - Correct Version using dynamic C-style array with proper management
class Library {
private:
    Book* books;    // Pointer to dynamically allocated array of Book objects
    int count;      // Current number of books in the library
    int capacity;   // Current allocated capacity of the array

    // Helper function to resize the internal array
    void resize() {
        // Double the capacity, or set to 1 if currently 0
        capacity = (capacity == 0) ? 1 : capacity * 2;
        Book* newBooks = new Book[capacity];

        // Copy existing books to the new array
        for (int i = 0; i < count; ++i) {
            newBooks[i] = books[i];
        }

        // Delete the old array and update the pointer
        delete[] books;
        books = newBooks;
    }

public:
    // Constructor
    Library() : books(nullptr), count(0), capacity(0) {}

    // Destructor to free dynamically allocated memory
    ~Library() {
        delete[] books;
    }

    // Copy constructor (Rule of Three/Five)
    Library(const Library& other) : count(other.count), capacity(other.capacity) {
        books = new Book[capacity];
        for (int i = 0; i < count; ++i) {
            books[i] = other.books[i];
        }
    }

    // Copy assignment operator (Rule of Three/Five)
    Library& operator=(const Library& other) {
        if (this != &other) {
            delete[] books; // Free existing resources

            count = other.count;
            capacity = other.capacity;
            books = new Book[capacity];
            for (int i = 0; i < count; ++i) {
                books[i] = other.books[i];
            }
        }
        return *this;
    }

    // Method to add a book - efficient and robust
    void addBook(const Book& book) { // Pass by const reference to avoid unnecessary copies
        std::cout << "Adding: " << book.title << std::endl;
        if (count == capacity) {
            resize(); // Resize if capacity is full
        }
        books[count++] = book; // Add the book and increment count
    }

    // Method to display all books
    void displayAllBooks() const {
        if (count == 0) {
            std::cout << "Library is empty." << std::endl;
            return;
        }
        std::cout << "--- Library Books (Count: " << count << ", Capacity: " << capacity << ") ---" << std::endl;
        for (int i = 0; i < count; ++i) {
            books[i].display();
        }
        std::cout << "----------------------------------------------------" << std::endl;
    }
};

int main() {
    Library myLibrary;

    myLibrary.addBook(Book("The Lord of the Rings", "J.R.R. Tolkien", 1954));
    myLibrary.addBook(Book("Pride and Prejudice", "Jane Austen", 1813));
    myLibrary.addBook(Book("Moby Dick", "Herman Melville", 1851));
    myLibrary.addBook(Book("War and Peace", "Leo Tolstoy", 1869)); // Triggers resize
    myLibrary.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 1951)); // Triggers resize

    myLibrary.displayAllBooks();

    // Test copy constructor and assignment operator for completeness
    Library anotherLibrary = myLibrary; // Copy constructor
    std::cout << "\n--- Another Library (copy of myLibrary) ---" << std::endl;
    anotherLibrary.displayAllBooks();

    Library thirdLibrary;
    thirdLibrary.addBook(Book("Frankenstein", "Mary Shelley", 1818));
    thirdLibrary = myLibrary; // Copy assignment
    std::cout << "\n--- Third Library (assigned from myLibrary) ---" << std::endl;
    thirdLibrary.displayAllBooks();


    return 0;
}