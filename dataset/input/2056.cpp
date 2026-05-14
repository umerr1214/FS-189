#include <iostream>

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
} // ERROR: Missing semicolon after class definition

int main() {
    // This main function is part of the code with the error.
    // It would not compile due to the missing semicolon.
    // If it did compile, it would work correctly.
    Date d1(15, 7, 2023);
    std::cout << "Date: " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() << std::endl;

    Date d2(1, 1, 2000);
    std::cout << "Date: " << d2.getDay() << "/" << d2.getMonth() << "/" << d2.getYear() << std::endl;

    return 0;
}