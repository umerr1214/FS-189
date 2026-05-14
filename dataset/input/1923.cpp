#include <iostream>
#include <string>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Default constructor
    Book() : title(""), author(""), isbn("") {}

    // Parameterized constructor - uses const reference for efficiency
    Book(const std::string& t, const std::string& a, const std::string& i)
        : title(t), author(a), isbn(i) {}

    // Setters - pass by const reference for efficiency
    void setTitle(const std::string& t) {
        title = t;
    }
    void setAuthor(const std::string& a) {
        author = a;
    }
    void setIsbn(const std::string& i) {
        isbn = i;
    }

    // Getters - return by const reference for efficiency, const-qualified for correctness
    const std::string& getTitle() const {
        return title;
    }
    const std::string& getAuthor() const {
        return author;
    }
    const std::string& getIsbn() const {
        return isbn;
    }

    // Optional: A display method for convenience, also const-qualified
    void displayBookInfo() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    // Test case 1: Default constructor and setters
    Book book1;
    book1.setTitle("The Great Gatsby");
    book1.setAuthor("F. Scott Fitzgerald");
    book1.setIsbn("978-0743273565");

    std::cout << "Book 1 Details:" << std::endl;
    book1.displayBookInfo();
    std::cout << std::endl;

    // Test case 2: Parameterized constructor and getters
    Book book2("To Kill a Mockingbird", "Harper Lee", "978-0061120084");

    std::cout << "Book 2 Details:" << std::endl;
    std::cout << "Title: " << book2.getTitle() << std::endl;
    std::cout << "Author: " << book2.getAuthor() << std::endl;
    std::cout << "ISBN: " << book2.getIsbn() << std::endl;
    std::cout << std::endl;

    // Test case 3: Modifying and re-displaying
    book1.setTitle("The Great Gatsby (Revised)");
    std::cout << "Book 1 (After title revision):" << std::endl;
    book1.displayBookInfo();
    std::cout << std::endl;
    
    // Test case 4: Const object interaction - demonstrates const-correctness of getters
    const Book constBook("Dune", "Frank Herbert", "978-0441172719");
    std::cout << "Const Book Details:" << std::endl;
    std::cout << "Title: " << constBook.getTitle() << std::endl;
    std::cout << "Author: " << constBook.getAuthor() << std::endl;
    std::cout << "ISBN: " << constBook.getIsbn() << std::endl;
    // Attempting constBook.setTitle("New Title"); here would correctly cause a compile-time error.
    
    return 0;
}