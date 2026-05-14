#include <iostream>
#include <iomanip> // Required for std::setw and std::setfill

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor
    // This constructor has a semantic error: parameters shadow member variables without proper initialization.
    // The member variables 'day', 'month', 'year' will not be initialized with the constructor arguments.
    Date(int day, int month, int year) {
        // The parameters 'day', 'month', 'year' shadow the member variables.
        // Without 'this->', the assignment 'day = day;' assigns the parameter to itself,
        // leaving the member variable uninitialized (or default-initialized to 0 for fundamental types).
        // This compiles but does not produce the intended behavior.
        day = day;     // Semantic error: assigns parameter 'day' to itself
        month = month; // Semantic error: assigns parameter 'month' to itself
        year = year;   // Semantic error: assigns parameter 'year' to itself
    }

    // Public method to display the date
    void displayDate() {
        std::cout << std::setw(2) << std::setfill('0') << day << "-"
                  << std::setw(2) << std::setfill('0') << month << "-"
                  << year;
    }
};

int main() {
    // Test cases
    Date d1(1, 1, 2023);
    std::cout << "Date 1: ";
    d1.displayDate();
    std::cout << std::endl;

    Date d2(15, 12, 2024);
    std::cout << "Date 2: ";
    d2.displayDate();
    std::cout << std::endl;

    Date d3(5, 7, 1999);
    std::cout << "Date 3: ";
    d3.displayDate();
    std::cout << std::endl;

    return 0;
}