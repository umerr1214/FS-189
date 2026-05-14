#include <iostream>

class Date {
public:
    int day;
    int month;
    int year;

    Date(int d, int m, int y) : day(d), month(m), year(y) {}
};

// Overload the << operator with a robustness issue:
// It does not ensure leading zeros for single-digit day/month,
// violating the DD/MM/YYYY format specification.
std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}

int main() {
    Date d1(1, 1, 2023);
    Date d2(15, 7, 2024);
    Date d3(5, 12, 2020);
    Date d4(10, 10, 2025);

    std::cout << "Date 1: " << d1 << std::endl; // Expected: 01/01/2023, Actual: 1/1/2023
    std::cout << "Date 2: " << d2 << std::endl; // Expected: 15/07/2024, Actual: 15/7/2024
    std::cout << "Date 3: " << d3 << std::endl; // Expected: 05/12/2020, Actual: 5/12/2020
    std::cout << "Date 4: " << d4 << std::endl; // Expected: 10/10/2025, Actual: 10/10/2025

    return 0;
}