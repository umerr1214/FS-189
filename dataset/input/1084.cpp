#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor
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
        year = y; // No specific validation for year requested
    }

    void displayDate() {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Date myDate;
    myDate.displayDate(); // Should be 1/1/2000

    myDate.setDay(15);
    myDate.setMonth(7);
    myDate.setYear(2023);
    myDate.displayDate(); // Should be 15/7/2023

    myDate.setDay(32);   // Invalid day
    myDate.setMonth(13); // Invalid month
    myDate.displayDate(); // Should still be 15/7/2023

    return 0;
}