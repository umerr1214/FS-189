#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Readability / Efficiency Issue:
    // - 'title' is default constructed, then assigned in the constructor body (inefficient).
    // - Parameter names (t, a, i) are not descriptive (poor readability).
    // - Unnecessary use of 'this->' in display method (minor readability/style issue).
    Book(const std::string& t, const std::string& a, const std::string& i)
        : author(a), isbn(i) // Only 'author' and 'isbn' are initialized via initializer list
    {
        title = t; // 'title' is default constructed, then assigned. This is less efficient
                   // than direct initialization via an initializer list for std::string.
    }

    void display() const {
        std::cout << "Title: " << this->title << std::endl; // Unnecessary use of 'this->'
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book b1("The Lord of the Rings", "J.R.R. Tolkien", "978-0618053267");
    b1.display();
    std::cout << "--------------------" << std::endl;

    Book b2("Pride and Prejudice", "Jane Austen", "978-0141439518");
    b2.display();
    std::cout << "--------------------" << std::endl;

    std::cout << "\nExplanation for initializer lists:" << std::endl;
    std::cout << "Initializer lists are generally preferred because they initialize members directly." << std::endl;
    std::cout << "When you assign in the constructor body (like `title = t;`), the member (`title`) is first default-constructed," << std::endl;
    std::cout << "and then its assignment operator is called. This can be less efficient for complex objects like `std::string`" << std::endl;
    std::cout << "as it involves an extra construction and destruction of a temporary object. For `const` or reference members," << std::endl;
    std::cout << "assignment in the body is not even possible, making initializer lists mandatory." << std::endl;
    std::cout << "Also, using cryptic parameter names (t, a, i) reduces readability." << std::endl;
    return 0;
}