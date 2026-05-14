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
            // LOGICAL ERROR: Prints error but still updates the day, violating "do not update"
            std::cout << "Error: Invalid day " << d << ". Day will be updated anyway." << std::endl;
            day = d; 
        }
    }

    void setMonth(int m) {
        if (m >= 1 && m <= 11) { // LOGICAL ERROR: Should be m <= 12, so month 12 will be incorrectly rejected
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

    std::cout << "--- Testing logical errors ---" << std::endl;

    myDate.setDay(32); // Invalid day, but will update due to logical error
    myDate.displayDate(); // Program output: 32/7/2023 (Incorrect, should be 15/7/2023)

    myDate.setMonth(12); // Valid month, but will fail validation due to logical error (m <= 11)
    myDate.displayDate(); // Program output: 32/7/2023 (Incorrect, should be 32/12/2023 if day was valid, or 15/12/2023 if day was correctly not updated)

    return 0;
}