#include <iostream>
#include <string>

// Readability issue: Global 'using namespace std;' is generally discouraged
// in header files or large scopes due to potential name collisions.
using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;

    // Default constructor
    Book() {
        title = "";
        author = "";
        isbn = "";
    }

    // Parameterized constructor with readability/efficiency issue:
    // Members are initialized using assignment in the constructor body instead of
    // the initializer list. For std::string, this means default constructing
    // each member first, then assigning, which is less efficient than direct initialization.
    Book(string t, string a, string i) {
        title = t; // Default constructed, then assigned
        author = a;
        isbn = i;
    }

    void display() const {
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "ISBN: " << isbn << "\n";
    }
};

int main() {
    Book book1("The C++ Programming Language", "Bjarne Stroustrup", "978-0321563842");
    book1.display();

    Book book2("Effective C++", "Scott Meyers", "978-0321334879");
    book2.display();

    return 0;
}