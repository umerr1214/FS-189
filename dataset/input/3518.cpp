#include <iostream>
#include <string>

// Define the Book struct
struct Book {
    std::string t; // Non-descriptive variable name for title
    std::string a; // Non-descriptive variable name for author
    int y;         // Non-descriptive variable name for publicationYear
};

int main() {
    // Create a C-style array of 3 Book structs
    Book bks[3]; // Non-idiomatic C++ (std::array or std::vector preferred for fixed size)

    // Populate the details for each book
    bks[0].t = "The Lord of the Rings";
    bks[0].a = "J.R.R. Tolkien";
    bks[0].y = 1954;

    bks[1].t = "To Kill a Mockingbird";
    bks[1].a = "Harper Lee";
    bks[1].y = 1960;

    bks[2].t = "The Great Gatsby";
    bks[2].a = "F. Scott Fitzgerald";
    bks[2].y = 1925;

    // Iterate through the array using an old-style for loop
    for (int i = 0; i < 3; ++i) { // Less readable than range-based for loop
        std::cout << "Book " << i + 1 << ": ";
        std::cout << "Title: " << bks[i].t << ", ";
        std::cout << "Author: " << bks[i].a << ", ";
        std::cout << "Year: " << bks[i].y << std::endl;
    }

    return 0;
}