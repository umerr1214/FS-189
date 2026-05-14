#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor using initializer list and basic validation for robustness
    Date(int d, int m, int y) : year(y) {
        // Basic month validation: default to 1 if out of range
        if (m >= 1 && m <= 12) {
            month = m;
        } else {
            month = 1; // Default to January
        }

        // Basic day validation: default to 1 if out of range (not considering month-specific days for simplicity)
        if (d >= 1 && d <= 31) {
            day = d;
        } else {
            day = 1; // Default to 1st
        }
    }

    // Const member function to display the date concisely
    void displayDate() const {
        std::cout << month << "/" << day << "/" << year << std::endl;
    }
};

int main() {
    // Demonstrate calling displayDate() on a non-const object
    Date myDate(15, 7, 2023);
    std::cout << "Non-const date: ";
    myDate.displayDate();

    // Demonstrate calling displayDate() on an object with initially invalid data
    // The constructor's basic validation will correct it.
    Date correctedDate(32, 13, 2023); // Invalid day (32), invalid month (13)
    std::cout << "Corrected date (from invalid input): ";
    correctedDate.displayDate(); // Should display 1/1/2023 due to validation

    // Demonstrate calling displayDate() on a const object
    const Date constDate(1, 1, 2024);
    std::cout << "Const date: ";
    constDate.displayDate();

    return 0;
}