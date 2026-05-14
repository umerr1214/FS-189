#include <iostream>
#include <string>
#include <vector> // Included, though not strictly necessary for a fixed-size C-style array of 2.

struct Book {
    std::string title;
    int pages;
};

int main() {
    Book booksArray[2]; // Using a C-style array

    booksArray[0].title = "The C++ Way";
    booksArray[0].pages = 800;

    booksArray[1].title = "Accelerated C++";
    booksArray[1].pages = 600;

    // Readability/Efficiency Issue: Using a loop and temporary variables for a fixed-size 2-element array
    // is overly complex and less efficient than a direct if-else comparison.
    // While 'maxIdx' and 'i' are standard loop variable names, the overall approach is verbose
    // for this specific problem constraint.
    int maxIdx = 0;
    for (int i = 1; i < 2; ++i) { // Loop runs only once (for i=1)
        if (booksArray[i].pages > booksArray[maxIdx].pages) {
            maxIdx = i;
        }
    }
    // If pages are equal, maxIdx remains 0, implicitly picking the first book.

    std::cout << booksArray[maxIdx].title << std::endl;

    return 0;
}