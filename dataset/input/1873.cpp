#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

class Publication {
private:
    std::string title;
    double price;

public:
    // Default constructor
    Publication() : title(""), price(0.0) {}

    void setTitle(std::string t) {
        title = t;
    }

    void setPrice(double p) {
        price = p;
    }

    void displayPublicationDetails() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: $" << price << std::endl;
    }
};

class Book : public Publication {
private:
    std::string author;

public:
    // Default constructor
    Book() : Publication(), author("") {}

    void setAuthor(std::string a) {
        author = a;
    }

    void displayBookDetails() const {
        displayPublicationDetails(); // Call base class method
        std::cout << "Author: " << author << std::endl;
    }
};

class Magazine : public Publication {
private:
    int issueNumber;

public:
    // Default constructor
    Magazine() : Publication(), issueNumber(0) {}

    void setIssueNumber(int issue) {
        issueNumber = issue;
    }

    void displayMagazineDetails() const {
        displayPublicationDetails(); // Call base class method
        std::cout << "Issue Number: " << issueNumber << std::endl;
    }
};

int main() {
    Book myBook;
    Magazine myMagazine;

    std::string inputTitle, inputAuthor;
    double inputPrice;
    int inputIssueNumber;

    std::cout << "--- Enter Book Details ---" << std::endl;
    std::cout << "Enter book title: ";
    std::getline(std::cin, inputTitle); // Reads entire line
    myBook.setTitle(inputTitle);

    std::cout << "Enter book price: ";
    // Robustness Issue: No input validation for price.
    // If non-numeric input is given, std::cin will fail,
    // subsequent reads might fail or loop unexpectedly.
    std::cin >> inputPrice;
    myBook.setPrice(inputPrice);

    // Clear the buffer after numeric input and ignore rest of line
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter book author: ";
    std::getline(std::cin, inputAuthor);
    myBook.setAuthor(inputAuthor);

    std::cout << "\n--- Enter Magazine Details ---" << std::endl;
    std::cout << "Enter magazine title: ";
    std::getline(std::cin, inputTitle);
    myMagazine.setTitle(inputTitle);

    std::cout << "Enter magazine price: ";
    // Robustness Issue: No input validation for price.
    std::cin >> inputPrice;
    myMagazine.setPrice(inputPrice);

    // Clear the buffer after numeric input and ignore rest of line
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter magazine issue number: ";
    // Robustness Issue: No input validation for issue number.
    std::cin >> inputIssueNumber;
    myMagazine.setIssueNumber(inputIssueNumber);

    // No need to clear buffer after final numeric input if program exits.

    std::cout << "\n--- Displaying Details ---" << std::endl;
    std::cout << "\nBook Details:" << std::endl;
    myBook.displayBookDetails();

    std::cout << "\nMagazine Details:" << std::endl;
    myMagazine.displayMagazineDetails();

    return 0;
}