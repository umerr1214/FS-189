#include <iostream>
#include <string>

// A global string that the destructor might try to use.
// Its destruction order relative to other global/static objects is unspecified.
std::string global_suffix = " (Global suffix)";

class Book {
public:
    std::string title;
    Book(std::string t) : title(t) {
        std::cout << "Book '" << title << "' created." << std::endl;
    }
    ~Book() {
        // Semantic error: Accessing 'global_suffix' which might already be destroyed
        // if this Book object is also a global/static object.
        // The order of destruction of static objects is unspecified, leading to
        // potential Undefined Behavior if global_suffix is accessed after its destruction.
        std::cout << "Book '" << title << "' is being destroyed" << global_suffix << std::endl;
    }
};

// Global Book objects to demonstrate the potential semantic error.
// Their constructors run before main(), and destructors run after main() returns.
// The destruction order of global_suffix, global_book1, global_book2 is unspecified.
Book global_book1("The Hobbit");
Book global_book2("Dune");

void run_test() {
    // Local Book objects, their destruction is well-defined (before global objects).
    {
        Book b1("The Great Gatsby");
    } // b1 goes out of scope
    {
        Book b2("1984");
    } // b2 goes out of scope
    std::cout << "End of main scope." << std::endl;
}

int main() {
    run_test();
    return 0;
}