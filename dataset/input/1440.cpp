#include <iostream>
#include <iomanip> // Required for std::setw and std::setfill

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Friend declaration for the overloaded operator<<
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

// Overload the << operator for Date objects with a semantic error: returns std::ostream by value
std::ostream operator<<(std::ostream& os, const Date& date) { // SEMANTIC ERROR: Should return std::ostream& (by reference)
    os << std::setfill('0') << std::setw(2) << date.day << "-"
       << std::setfill('0') << std::setw(2) << date.month << "-"
       << date.year;
    return os; // Returns a copy of the ostream object, breaking chaining and potentially causing performance issues
}

int main() {
    Date d1(15, 7, 2023);
    std::cout << "Date 1: " << d1 << std::endl; // Works for single output

    Date d2(2, 2, 2024);
    std::cout << "Date 2: " << d2 << std::endl; // Works for single output

    Date d3(10, 11, 2025);
    // This chained output will still compile and might appear to work,
    // but the intermediate `std::cout << d3` returns a temporary `std::ostream` object.
    // The subsequent `<< " and more text"` operates on this temporary, not the original `std::cout`.
    // This is a semantic violation of how insertion operators are typically designed.
    std::cout << "Chained: " << d3 << " and more text" << std::endl;
    
    return 0;
}