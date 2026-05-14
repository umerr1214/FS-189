#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor - Lacks validation, allowing invalid dates to be set
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    // Const member function to display the date
    void displayDate() const {
        std::cout << month << "/" << day << "/" << year << std::endl;
    }
};

int main() {
    // Demonstrate calling displayDate() on a non-const object
    Date myDate(15, 7, 2023); // A valid date
    std::cout << "Non-const date: ";
    myDate.displayDate();

    // Demonstrate calling displayDate() on an object with invalid data
    // This highlights the robustness issue: the class allows an invalid state.
    Date invalidDate(32, 13, 2023); // Invalid day (32), invalid month (13)
    std::cout << "Invalid date (robustness issue): ";
    invalidDate.displayDate();

    // Demonstrate calling displayDate() on a const object
    const Date constDate(1, 1, 2024); // A valid date
    std::cout << "Const date: ";
    constDate.displayDate();

    return 0;
}