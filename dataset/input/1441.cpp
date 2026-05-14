#include <iostream>
// No <iomanip> included, leading to the robustness issue in formatting.

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

    // Friend declaration for the operator
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

// Robustness Issue: The operator does not robustly adhere to the 'DD-MM-YYYY' format.
// It fails to add leading zeros for single-digit days and months,
// resulting in 'D-M-YYYY' instead of 'DD-MM-YYYY' for certain dates.
std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.day << "-" << date.month << "-" << date.year;
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