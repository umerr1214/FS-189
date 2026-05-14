#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

struct Book {
    std::string title;
    std::string author;
    int publicationYear;
};

// Function to get book details robustly
void getBookDetails(Book& book, int bookNumber) {
    std::cout << "\n--- Book " << bookNumber << " ---\n";

    std::cout << "Enter title: ";
    // Use std::ws to consume any leading whitespace, including leftover newlines
    // from previous numeric inputs, before reading the title.
    std::getline(std::cin >> std::ws, book.title);

    std::cout << "Enter author: ";
    std::getline(std::cin, book.author);

    while (true) { // Loop for robust integer input
        std::cout << "Enter publication year: ";
        std::cin >> book.publicationYear;

        if (std::cin.fail()) { // Check if the input operation failed
            std::cout << "Invalid input. Please enter a number for the year.\n";
            std::cin.clear(); // Clear the error flag on std::cin
            // Ignore the rest of the invalid line in the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            // Valid integer was read, now consume the rest of the line (the newline character)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break; // Exit the loop if input is valid
        }
    }
}

// Function to print book details
void printBookDetails(const Book& book, int bookNumber) {
    std::cout << "\nBook " << bookNumber << ":\n";
    std::cout << "Title: " << book.title << "\n";
    std::cout << "Author: " << book.author << "\n";
    std::cout << "Publication Year: " << book.publicationYear << "\n";
}

int main() {
    Book books[3]; // Declare an array of three Book structs

    std::cout << "Enter details for three books:\n";
    for (int i = 0; i < 3; ++i) {
        getBookDetails(books[i], i + 1); // Use the robust input function
    }

    std::cout << "\n--- Details of all books ---\n";
    for (int i = 0; i < 3; ++i) {
        printBookDetails(books[i], i + 1); // Use the print function
    }

    return 0;
}