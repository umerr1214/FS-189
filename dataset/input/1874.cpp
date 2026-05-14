#include <iostream>
#include <string>

class Publication {
private:
    std::string title_val; // Inconsistent naming convention
    double price_val;

public:
    void set_details_pub(std::string title, double price) { // Pass by value (minor inefficiency)
        this->title_val = title; // Redundant 'this->'
        this->price_val = price;
    }

    void show_details_pub() const { // Generic method name
        std::cout << "Publication Info:" << std::endl; // Generic output
        std::cout << "  Title is: " << this->title_val << std::endl;
        std::cout << "  Cost is: $" << this->price_val << std::endl;
    }
};

class Book : public Publication {
private:
    std::string writer_name; // Inconsistent naming convention

public:
    void set_book_info(std::string author) { // Pass by value
        this->writer_name = author;
    }

    void show_book_info() const { // Generic method name, doesn't call base display
        // Readability Issue: Does not call base class display method.
        // User must explicitly call show_details_pub() and then show_book_info()
        // to get complete book details, which is less convenient and error-prone.
        std::cout << "  Author is: " << this->writer_name << std::endl;
    }
};

class Magazine : public Publication {
private:
    int issue_num; // Inconsistent naming convention

public:
    void set_magazine_data(int number) { // Pass by value
        this->issue_num = number;
    }

    void show_magazine_data() const { // Generic method name, doesn't call base display
        // Readability Issue: Does not call base class display method.
        std::cout << "  Issue Number is: " << this->issue_num << std::endl;
    }
};

int main() {
    Book myBook;
    Magazine myMagazine;

    // Readability Issue: No constructors, requiring multiple setter calls.
    myBook.set_details_pub("Programming in C++", 55.99);
    myBook.set_book_info("Robert Lafore");

    myMagazine.set_details_pub("Linux Journal", 8.75);
    myMagazine.set_magazine_data(305);

    std::cout << "--- Book Details (Partial) ---" << std::endl;
    myBook.show_details_pub(); // User must remember to call this first
    myBook.show_book_info();   // Then this

    std::cout << "\n--- Magazine Details (Partial) ---" << std::endl;
    myMagazine.show_details_pub(); // User must remember to call this first
    myMagazine.show_magazine_data(); // Then this

    std::cout << "\n--- Demonstrating full display by calling separately ---" << std::endl;
    std::cout << "Book:\n";
    myBook.show_details_pub();
    myBook.show_book_info();
    std::cout << "Magazine:\n";
    myMagazine.show_details_pub();
    myMagazine.show_magazine_data();

    return 0;
}