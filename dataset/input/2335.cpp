#include <iostream>
#include <string>
#include <vector>

// Book class with a pointer to string for ISBN, creating a robustness vulnerability.
// Proper memory management (destructor, copy constructor, copy assignment) is implemented
// for the Book class itself, but the 'operator==' function will expose a vulnerability
// if a Book object with a null isbn_ptr is passed.
class Book {
public:
    std::string* isbn_ptr; // Raw pointer to ISBN string
    std::string title;
    std::string author;

    // Constructor that initializes isbn_ptr
    Book(std::string isbn_val, std::string title_val = "Unknown", std::string author_val = "Unknown")
        : title(std::move(title_val)), author(std::move(author_val)) {
        isbn_ptr = new std::string(std::move(isbn_val));
    }

    // Default constructor that leaves isbn_ptr as nullptr, creating a vulnerable state
    Book() : isbn_ptr(nullptr), title(""), author("") {}

    // Destructor to manage allocated memory
    ~Book() {
        delete isbn_ptr;
    }

    // Copy constructor for proper resource management
    Book(const Book& other) : title(other.title), author(other.author) {
        if (other.isbn_ptr) {
            isbn_ptr = new std::string(*other.isbn_ptr);
        } else {
            isbn_ptr = nullptr;
        }
    }

    // Copy assignment operator for proper resource management
    Book& operator=(const Book& other) {
        if (this == &other) return *this;
        delete isbn_ptr; // Free existing resource
        title = other.title;
        author = other.author;
        if (other.isbn_ptr) {
            isbn_ptr = new std::string(*other.isbn_ptr);
        } else {
            isbn_ptr = nullptr;
        }
        return *this;
    }
};

// Overloaded == operator with a robustness issue:
// It dereferences isbn_ptr without checking if it's nullptr,
// leading to a crash (e.g., segmentation fault) if a Book object
// with a null isbn_ptr (like a default-constructed one) is compared.
bool operator==(const Book& lhs, const Book& rhs) {
    // CRITICAL ROBUSTNESS ISSUE:
    // If lhs.isbn_ptr or rhs.isbn_ptr is nullptr (e.g., from default constructor),
    // dereferencing it here (*lhs.isbn_ptr) will cause a runtime error (segmentation fault).
    return *lhs.isbn_ptr == *rhs.isbn_ptr;
}

int main() {
    Book book1("978-0321992789", "The C++ Programming Language", "Bjarne Stroustrup");
    Book book2("978-0321992789", "C++ Primer", "Stanley B. Lippman"); // Same ISBN as book1
    Book book3("978-1234567890", "Effective C++", "Scott Meyers");
    Book book4("978-1234567890"); // Only ISBN provided

    // Valid comparisons (where isbn_ptr is properly initialized)
    std::cout << (book1 == book2 ? "true" : "false") << std::endl; // Expected: true
    std::cout << (book1 == book3 ? "true" : "false") << std::endl; // Expected: false
    std::cout << (book3 == book4 ? "true" : "false") << std::endl; // Expected: true
    std::cout << (book1 == book1 ? "true" : "false") << std::endl; // Expected: true

    // Robustness issue trigger: comparing with a default-constructed book (isbn_ptr is nullptr)
    Book defaultBook; // isbn_ptr is nullptr
    // This line is expected to cause a runtime error (e.g., segmentation fault)
    // because operator== attempts to dereference defaultBook.isbn_ptr, which is nullptr.
    std::cout << (book1 == defaultBook ? "true" : "false") << std::endl; // EXPECTED CRASH/RUNTIME_ERROR

    return 0;
}