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
} // SYNTAX ERROR: Missing semicolon after class definition

// Overload the << operator for Date objects
std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << std::setfill('0') << std::setw(2) << date.day << "-"
       << std::setfill('0') << std::setw(2) << date.month << "-"
       << date.year;
    return os;
}

int main() {
    Date d1(1, 1, 2023);
    std::cout << "Date: " << d1 << std::endl;

    Date d2(15, 10, 2024);
    std::cout << "Another Date: " << d2 << std::endl;

    Date d3(5, 3, 2021);
    std::cout << "Third Date: " << d3 << std::endl;
    
    return 0;
}