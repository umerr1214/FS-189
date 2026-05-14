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

// Overload the << operator for Date objects with a logical error: prints MM-DD-YYYY
std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << std::setfill('0') << std::setw(2) << date.month << "-" // LOGICAL ERROR: month printed before day
       << std::setfill('0') << std::setw(2) << date.day << "-"
       << date.year;
    return os;
}

int main() {
    Date d1(5, 12, 2023); // Expected: 05-12-2023 (December 5th)
    std::cout << "Date 1: " << d1 << std::endl;

    Date d2(1, 1, 2024); // Expected: 01-01-2024 (January 1st)
    std::cout << "Date 2: " << d2 << std::endl; // This specific case will appear correct, but the logic is flawed

    Date d3(25, 3, 2025); // Expected: 25-03-2025 (March 25th)
    std::cout << "Date 3: " << d3 << std::endl;
    
    return 0;
}