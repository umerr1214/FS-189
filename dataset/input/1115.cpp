#include <iostream>
// Logical Error: Missing <iomanip> and manual padding logic,
// leading to single-digit day/month not being zero-padded.

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
};

std::ostream& operator<<(std::ostream& os, const Date& d) {
    // Logical Error: Prints day/month without leading zeros for single-digit values.
    // Expected: 01/05/2023, Actual: 1/5/2023
    os << d.getDay() << "/"
       << d.getMonth() << "/"
       << d.getYear();
    return os;
}

int main() {
    Date d1(1, 5, 2023);
    Date d2(25, 12, 1999);
    Date d3(9, 7, 2020);

    std::cout << "Date 1: " << d1 << std::endl;
    std::cout << "Date 2: " << d2 << std::endl;
    std::cout << "Date 3: " << d3 << std::endl;

    return 0;
}