#include <string>
#include <iostream>
#include <vector>
#include <utility> // For std::pair

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
public:
    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i) {}

    std::string getIsbn() const {
        return isbn;
    }

    std::string getTitle() const {
        return title;
    }

    void print() const {
        std::cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn;
    }
};

// Syntax Error: Missing 'operator' keyword
bool ==(const Book& lhs, const Book& rhs) {
    return lhs.getIsbn() == rhs.getIsbn();
}

int main() {
    std::vector<std::pair<std::pair<Book, Book>, bool>> testCases = {
        {{Book("The Hobbit", "J.R.R. Tolkien", "978-0-345-33968-3"), Book("The Hobbit", "J.R.R. Tolkien", "978-0-345-33968-3")}, true},
        {{Book("The Hobbit", "J.R.R. Tolkien", "978-0-345-33968-3"), Book("The Lord of the Rings", "J.R.R. Tolkien", "978-0-345-33968-3")}, true}, // Same ISBN, different title
        {{Book("1984", "George Orwell", "978-0-452-28423-1"), Book("Animal Farm", "George Orwell", "978-0-451-52634-2")}, false}, // Different ISBN, different title
        {{Book("Book A", "Author X", "ISBN123"), Book("Book A", "Author Y", "ISBN456")}, false} // Different ISBN, same title
    };

    std::cout << "Testing Book == operator:\n";
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];
        // This line will cause a compilation error due to the syntax error in operator overloading
        // bool result = (tc.first.first == tc.first.second);
        std::cout << "Test Case " << (i + 1) << ":\n";
        std::cout << "  Book 1: "; tc.first.first.print(); std::cout << "\n";
        std::cout << "  Book 2: "; tc.first.second.print(); std::cout << "\n";
        std::cout << "  Expected: " << (tc.second ? "true" : "false") << ", Got: N/A (Compile Error)\n";
        std::cout << "  Status: FAILED (Compile Error)\n";
        std::cout << "--------------------------------\n";
    }

    return 0;
}