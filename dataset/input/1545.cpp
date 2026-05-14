#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Correct Version: Constructor using initializer list for all members.
    // Parameters are passed by const reference for efficiency, and have descriptive names.
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title),   // Direct initialization of title
          author(author), // Direct initialization of author
          isbn(isbn)      // Direct initialization of isbn
    {
        // The constructor body is empty as all initialization is handled efficiently
        // and correctly in the initializer list.
    }

    void display() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book b1("The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565");
    b1.display();
    std::cout << "--------------------" << std::endl;

    Book b2("To Kill a Mockingbird", "Harper Lee", "978-0446310789");
    b2.display();
    std::cout << "--------------------" << std::endl;

    std::cout << "\nExplanation for why initializer lists are often preferred:" << std::endl;
    std::cout << "1. Efficiency: Members are directly constructed with the provided values. Without an initializer list, " << std::endl;
    std::cout << "   objects with default constructors would first be default-constructed, then assigned, leading to " << std::endl;
    std::cout << "   redundant operations (e.g., for `std::string`, an empty string is created then replaced)." << std::endl;
    std::cout << "2. Mandatory for Const and Reference Members: `const` data members and reference data members " << std::endl;
    std::cout << "   *must* be initialized in an initializer list because they cannot be assigned to after construction." << std::endl;
    std::cout << "3. Mandatory for Members Without Default Constructors: If a member object's class does not have " << std::endl;
    std::cout << "   a default constructor, it can only be initialized via an initializer list." << std::endl;
    std::cout << "4. Order of Initialization: Members are initialized in the order they are declared in the class, " << std::endl;
    std::cout << "   not in the order they appear in the initializer list. This is a subtle but important rule to be aware of." << std::endl;
    std::cout << "5. Exception Safety: Initialization happens before the constructor body. If a member's constructor " << std::endl;
    std::cout << "   throws an exception, the object's construction fails cleanly before the main constructor logic runs." << std::endl;
    std::cout << "In summary, initializer lists provide a more efficient, correct, and robust way to initialize class members." << std::endl;
    return 0;
}