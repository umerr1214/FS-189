#include <iostream>
#include <string>

using namespace std; // Readability/Best Practice Issue: Using namespace std in global scope

struct Book {
    string title;
    string author;
    int yearPublished;
};

// Function to print book details, demonstrating readability/efficiency issues
void printBookDetails(Book b) { // Takes by value as requested
cout << "Book Details:" << endl; // Readability: Lack of indentation, Efficiency: uses endl (flushes buffer)
cout << "Title:" << b.title << endl; // Readability: No space after colon, Efficiency: uses endl
cout << "Author:" << b.author << endl; // Readability: No space after colon, Efficiency: uses endl
cout << "Year Published:" << b.yearPublished << endl; // Readability: No space after colon, Efficiency: uses endl
} // Readability: inconsistent indentation

int main() {
Book x = {"The Code Guide", "A. Coder", 2024}; // Readability: Non-descriptive variable name 'x'
printBookDetails(x); // Readability: Lack of blank lines for separation
return 0; // Readability: inconsistent indentation
} // Readability: inconsistent indentation