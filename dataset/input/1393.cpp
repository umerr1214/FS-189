#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor without any validation, allowing invalid dates to be created
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Overload the == operator to compare if two Date objects represent the same date
    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    // Helper to print date for verification
    void print() const {
        std::cout << day << "/" << month << "/" << year;
    }
};

int main() {
    // Test cases for the Date class
    Date d1(10, 5, 2023);
    Date d2(10, 5, 2023);
    Date d3(11, 5, 2023);
    Date d4(30, 2, 2023); // An invalid date (February 30th)
    Date d5(30, 2, 2023); // Another invalid date

    std::cout << "d1: "; d1.print(); std::cout << std::endl;
    std::cout << "d2: "; d2.print(); std::cout << std::endl;
    std::cout << "d3: "; d3.print(); std::cout << std::endl;
    std::cout << "d4 (invalid): "; d4.print(); std::cout << std::endl;
    std::cout << "d5 (invalid): "; d5.print(); std::cout << std::endl;

    std::cout << "d1 == d2: " << (d1 == d2 ? "true" : "false") << std::endl; // Expected: true
    std::cout << "d1 == d3: " << (d1 == d3 ? "true" : "false") << std::endl; // Expected: false
    std::cout << "d4 == d5: " << (d4 == d5 ? "true" : "false") << std::endl; // Expected: true (comparison works for invalid dates)
    std::cout << "d1 == d4: " << (d1 == d4 ? "true" : "false") << std::endl; // Expected: false

    return 0;
}