#include <iostream>

class Date {
private:
    int date_day_attribute; // Overly verbose attribute name
    int date_month_attribute;
    int date_year_attribute;

public:
    // Constructor - uses direct assignment instead of initializer list (less efficient/idiomatic)
    Date(int input_day, int input_month, int input_year) {
        date_day_attribute = input_day;
        date_month_attribute = input_month;
        date_year_attribute = input_year;
    }

    // Const member function to display the date - overly verbose and less efficient I/O
    void displayDate() const {
        std::cout << "The current date is: ";
        std::cout << date_month_attribute;
        std::cout << "/"; // Separate output statements for each part
        std::cout << date_day_attribute;
        std::cout << "/";
        std::cout << date_year_attribute;
        std::cout << std::endl; // Explicitly flush and newline
    }
};

int main() {
    // Demonstrate calling displayDate() on a non-const object
    int example_day = 15; // Verbose variable names
    int example_month = 7;
    int example_year = 2023;
    Date non_const_date_object(example_day, example_month, example_year);
    std::cout << "Non-const object demonstration: ";
    non_const_date_object.displayDate();

    // Demonstrate calling displayDate() on a const object
    const int another_day = 1;
    const int another_month = 1;
    const int another_year = 2024;
    const Date const_date_object(another_day, another_month, another_year);
    std::cout << "Const object demonstration: ";
    const_date_object.displayDate();

    return 0;
}