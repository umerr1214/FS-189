#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Logical error: 'day' and 'month' are swapped during initialization.
    Date(int d, int m, int y) : day(m), month(d), year(y) {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
};

int main() {
    Date d1(15, 7, 2023); // Expected: 15/7/2023, Actual output will be: 7/15/2023
    std::cout << "Date: " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() << std::endl;

    Date d2(1, 1, 2000); // Expected: 1/1/2000, Actual output will be: 1/1/2000 (appears correct due to identical values)
    std::cout << "Date: " << d2.getDay() << "/" << d2.getMonth() << "/" << d2.getYear() << std::endl;

    return 0;
}