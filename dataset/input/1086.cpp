#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() : day(1), month(1), year(2000) {}

    void setDay(int d) {
        if (d >= 1 && d <= 31) {
            day = d;
        } else {
            std::cout << "Error: Invalid day " << d << ". Day not updated." << std::endl;
        }
    }

    void setMonth(int m) {
        if (m >= 1 && m <= 12) {
            month = m;
        } else {
            std::cout << "Error: Invalid month " << m << ". Month not updated." << std::endl;
        }
    }

    void setYear(int y) {
        year = y;
    }

    void displayDate() {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};

int main() {
    Date myDate;
    myDate.displayDate(); // Expected: 1/1/2000

    myDate.setDay(15);
    myDate.setMonth(7);
    myDate.setYear(2023);
    myDate.displayDate(); // Expected: 15/7/2023

    // SEMANTIC ERROR: Attempting to access a private member directly from outside the class
    std::cout << "Directly accessing day: " << myDate.day << std::endl; // This line will cause a compilation error

    return 0;
}