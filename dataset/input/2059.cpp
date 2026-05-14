#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Parameterized constructor - LACKS VALIDATION
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    // Public getter methods
    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }
};

int main() {
    // Test case 1: Valid date
    Date d1(15, 7, 2023);
    std::cout << "Date 1 (Valid): " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() << std::endl;

    // Test case 2: Invalid date - Robustness Issue
    // The constructor does not validate inputs, allowing creation of an impossible date.
    Date d2(32, 13, 2024);
    std::cout << "Date 2 (Invalid): " << d2.getDay() << "/" << d2.getMonth() << "/" << d2.getYear() << std::endl;

    // Test case 3: Another invalid date
    Date d3(0, 5, 2025);
    std::cout << "Date 3 (Invalid): " << d3.getDay() << "/" << d3.getMonth() << "/" << d3.getYear() << std::endl;

    return 0;
}