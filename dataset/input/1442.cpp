#include <iostream>
#include <iomanip> // Included but not used idiomatically for padding, contributing to readability issue.

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

// Readability / Efficiency Issue: Uses verbose if-statements for padding
// instead of the more concise and idiomatic std::setw and std::setfill.
// This makes the code less readable and slightly less efficient.
std::ostream& operator<<(std::ostream& os, const Date& date) {
    if (date.day < 10) {
        os << '0';
    }
    os << date.day << "-";

    if (date.month < 10) {
        os << '0';
    }
    os << date.month << "-";

    os << date.year;
    return os;
}

int main() {
    Date d1(1, 1, 2023);
    Date d2(15, 7, 1999);
    Date d3(5, 12, 2010);
    Date d4(28, 2, 2024);

    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
    std::cout << d3 << std::endl;
    std::cout << d4 << std::endl;

    return 0;
}