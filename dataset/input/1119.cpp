#include <iostream> // Required for std::ostream, std::cout, std::endl
#include <iomanip>  // Required for std::setw, std::setfill

class Date {
public:
    int day;
    int month;
    int year;

    Date(int d, int m, int y) : day(d), month(m), year(y) {}
};

// Overload the << operator correctly using stream manipulators for proper formatting.
std::ostream& operator<<(std::ostream& os, const Date& date) {
    // Save current fill character and width to restore them later
    char prev_fill = os.fill();
    std::streamsize prev_width = os.width();

    os << std::setfill('0') << std::setw(2) << date.day << "/"
       << std::setw(2) << date.month << "/"
       << std::setw(4) << date.year; // setw(4) ensures 4 digits for year, e.g., 0999 for 999

    // Restore original stream settings
    os.fill(prev_fill);
    // std::setw only applies to the next output operation, so restoring width is often not strictly needed
    // unless the stream previously had a fixed width set that should persist.
    os.width(prev_width); 

    return os;
}

int main() {
    Date d1(1, 1, 2023);
    Date d2(15, 7, 2024);
    Date d3(5, 12, 2020);
    Date d4(10, 10, 2025);
    Date d5(2, 3, 999); // Test year with less than 4 digits

    std::cout << "Date 1: " << d1 << std::endl; // Expected: 01/01/2023
    std::cout << "Date 2: " << d2 << std::endl; // Expected: 15/07/2024
    std::cout << "Date 3: " << d3 << std::endl; // Expected: 05/12/2020
    std::cout << "Date 4: " << d4 << std::endl; // Expected: 10/10/2025
    std::cout << "Date 5: " << d5 << std::endl; // Expected: 02/03/0999

    return 0;
}