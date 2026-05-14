#include <iostream>
#include <cstring> // For strlen, strcpy
#include <vector>  // To demonstrate potential issues with containers

// This version demonstrates a robustness issue due to shallow copying
// when managing raw pointers without implementing the Rule of Three/Five.
class Book {
private:
    char* title; // Using char* to introduce manual memory management
    int id;      // Unique ID for each book instance

public:
    // Constructor
    Book(const char* t, int bookId) : id(bookId) {
        if (t) {
            title = new char[strlen(t) + 1];
            strcpy(title, t);
        } else {
            title = new char[1];
            title[0] = '\0';
        }
        std::cout << "Book '" << title << "' (ID: " << id << ") constructed." << std::endl;
    }

    // Destructor as per question
    // This destructor correctly frees the memory pointed to by 'title'.
    ~Book() {
        std::cout << "Book '" << title << "' (ID: " << id << ") is being destroyed." << std::endl;
        delete[] title; // Clean up dynamically allocated memory
    }

    // CRITICAL ROBUSTNESS ISSUE:
    // No user-defined copy constructor, copy assignment operator, or move operators.
    // The compiler will generate a default shallow copy constructor and assignment operator.
    // When a Book object is copied, both the original and the copy will point to the same 'title' memory.
    // This leads to double-free errors when both objects are destroyed.

    const char* getTitle() const {
        return title;
    }
};

// Function to demonstrate shallow copy leading to double-free
void createAndCopyBook() {
    Book book1("The Great Gatsby", 1);
    // book2 is created using the default copy constructor, which performs a shallow copy.
    // Both book1.title and book2.title now point to the same memory location.
    Book book2 = book1;
    std::cout << "Created book1 (ID: " << book1.getTitle() << ") and book2 (ID: " << book2.getTitle() << ") via shallow copy." << std::endl;
    // When book2 goes out of scope, its destructor frees the memory.
    // When book1 goes out of scope, its destructor tries to free the *same* memory again, causing a double-free crash.
}

int main() {
    std::cout << "--- Starting Robustness Test ---" << std::endl;

    // This call will likely cause a runtime crash (double-free)
    // due to the shallow copy in Book book2 = book1;
    createAndCopyBook();

    std::cout << "--- Robustness Test Ended (if program didn't crash before this) ---" << std::endl;

    // Another scenario for double-free or undefined behavior:
    // std::vector<Book> library;
    // library.push_back(Book("1984", 3)); // This also involves copying/moving, triggering shallow copy issues.
    // library.push_back(Book("Brave New World", 4));
    // The destructor for the temporary Book object in push_back will free memory.
    // Then, when the vector elements are destroyed, they will try to free the same memory again.

    // A dynamically allocated book that is correctly deleted (this part is safe)
    Book* ptrBook = new Book("Dynamic Book", 5);
    std::cout << "Dynamically allocated book created." << std::endl;
    delete ptrBook; // The destructor is called and frees memory once.

    return 0;
}