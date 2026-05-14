#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

    // Helper function for basic validation
    bool isValidDate(int d, int m, int y) const {
        if (y < 1) return false; // Year must be positive
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > 31) return false; // Simplified day check, not accounting for months with fewer days

        // More robust day check (e.g., for Feb, Apr, Jun, Sep, Nov) could be added here
        // For simplicity and focus on the main question, this basic check is sufficient.
        if (m == 2) {
            bool isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
            if (d > (isLeap ? 29 : 28)) return false;
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            if (d > 30) return false;
        }
        return true;
    }

public:
    // Parameterized constructor with basic validation
    Date(int d, int m, int y) {
        if (isValidDate(d, m, y)) {
            this->day = d;
            this->month = m;
            this->year = y;
        } else {
            // Default to a valid date if input is invalid
            std::cerr << "Warning: Invalid date provided (" << d << "/" << m << "/" << y << "). Setting to default 1/1/2000." << std::endl;
            this->day = 1;
            this->month = 1;
            this->year = 2000;
        }
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

    // Test case 2: Another valid date
    Date d2(29, 2, 2024); // Leap year
    std::cout << "Date 2 (Leap Year): " << d2.getDay() << "/" << d2.getMonth() << "/" << d2.getYear() << std::endl;

    // Test case 3: Invalid day/month/year combination
    Date d3(32, 13, 2025); // Invalid day and month
    std::cout << "Date 3 (Invalid input): " << d3.getDay() << "/" << d3.getMonth() << "/" << d3.getYear() << std::endl;

    // Test case 4: Invalid day for a specific month
    Date d4(31, 4, 2023); // April has 30 days
    std::cout << "Date 4 (Invalid day for month): " << d4.getDay() << "/" << d4.getMonth() << "/" << d4.getYear() << std::endl;

    // Test case 5: Invalid year
    Date d5(10, 10, -500);
    std::cout << "Date 5 (Invalid year): " << d5.getDay() << "/" << d5.getMonth() << "/" << d5.getYear() << std::endl;

    return 0;
}