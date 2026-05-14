#include <iostream>
#include <string>
#include <stdexcept> // For std::invalid_argument

class Date {
private:
    int day;
    int month;
    int year;

    // Helper function to check for leap year
    bool is_leap(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // Helper function to validate date components
    bool is_valid_date(int d, int m, int y) const {
        if (y < 1) return false; // Year must be positive
        if (m < 1 || m > 12) return false;

        int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (is_leap(y)) {
            days_in_month[2] = 29; // February in a leap year
        }

        if (d < 1 || d > days_in_month[m]) return false;
        return true;
    }

public:
    // Constructor with robust input validation
    Date(int d, int m, int y) {
        if (!is_valid_date(d, m, y)) {
            throw std::invalid_argument("Invalid date provided. Day, month, or year out of range.");
        }
        this->day = d;
        this->month = m;
        this->year = y;
    }

    // Overload the == operator concisely and correctly
    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    // Helper to print date for verification
    void print() const {
        std::cout << day << "/" << month << "/" << year;
    }
};

int main() {
    // Test cases for the Date class with robust constructor
    try {
        Date d1(15, 7, 2025);
        Date d2(15, 7, 2025);
        Date d3(16, 7, 2025);
        Date d4(29, 2, 2024); // Valid leap year date
        Date d5(29, 2, 2020); // Valid leap year date
        Date d6(28, 2, 2023); // Valid non-leap year date

        std::cout << "d1: "; d1.print(); std::cout << std::endl;
        std::cout << "d2: "; d2.print(); std::cout << std::endl;
        std::cout << "d3: "; d3.print(); std::cout << std::endl;
        std::cout << "d4: "; d4.print(); std::cout << std::endl;

        std::cout << "d1 == d2: " << (d1 == d2 ? "true" : "false") << std::endl; // Expected: true
        std::cout << "d1 == d3: " << (d1 == d3 ? "true" : "false") << std::endl; // Expected: false
        std::cout << "d4 == d5: " << (d4 == d5 ? "true" : "false") << std::endl; // Expected: false
        std::cout << "d4 == d4: " << (d4 == d4 ? "true" : "false") << std::endl; // Expected: true
        std::cout << "d6 == d4: " << (d6 == d4 ? "true" : "false") << std::endl; // Expected: false

        // Attempt to create an invalid date (will throw an exception)
        // Date invalid_date(30, 2, 2023);
        // std::cout << "Invalid date created (should not reach here)." << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}