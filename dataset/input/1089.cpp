#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Default constructor: Initializes to a valid default date.
    Date() : day(1), month(1), year(2000) {}

    // Parameterized constructor: Initializes with provided values, performing validation.
    Date(int d, int m, int y) : day(1), month(1), year(2000) { // Initialize to default first
        // Set year first as it has no specific validation
        setYear(y);
        // Set month and day, relying on setter validation
        setMonth(m);
        setDay(d);
    }

    // Getter methods
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setter for day with basic validation
    bool setDay(int d) {
        if (d >= 1 && d <= 31) { // Basic validation as per question, ignoring month specifics
            this->day = d;
            return true;
        } else {
            std::cout << "Error: Invalid day (" << d << "). Day must be between 1 and 31. Not updated." << std::endl;
            return false;
        }
    }

    // Setter for month with basic validation
    bool setMonth(int m) {
        if (m >= 1 && m <= 12) {
            this->month = m;
            return true;
        } else {
            std::cout << "Error: Invalid month (" << m << "). Month must be between 1 and 12. Not updated." << std::endl;
            return false;
        }
    }

    // Setter for year (no specific validation requested)
    void setYear(int y) {
        this->year = y;
    }

    // Utility method to print the date
    std::string toString() const {
        return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
    }
};

int main() {
    std::cout << "--- Testing Correct Version Code ---" << std::endl;

    // Test Case 1: Default constructor
    Date d1;
    std::cout << "d1 (default constructor): " << d1.toString() << std::endl; // Expected: 1/1/2000

    // Test Case 2: Parameterized constructor with valid values
    Date d2(15, 7, 2023);
    std::cout << "d2 (15/7/2023): " << d2.toString() << std::endl; // Expected: 7/15/2023

    // Test Case 3: Parameterized constructor with invalid month
    std::cout << "\nAttempting to create d3 with invalid month (15/13/2024):" << std::endl;
    Date d3(15, 13, 2024); // Month 13 is invalid, should default to 1/15/2024 (or 1/1/2024 if day also fails)
    std::cout << "d3: " << d3.toString() << std::endl; // Expected: 1/15/2024 (month defaults to 1)

    // Test Case 4: Parameterized constructor with invalid day
    std::cout << "\nAttempting to create d4 with invalid day (32/10/2025):" << std::endl;
    Date d4(32, 10, 2025); // Day 32 is invalid, should default to 10/1/2025
    std::cout << "d4: " << d4.toString() << std::endl; // Expected: 10/1/2025 (day defaults to 1)

    // Test Case 5: Setting valid values via setters
    Date d5;
    std::cout << "\nInitial d5: " << d5.toString() << std::endl;
    d5.setMonth(12);
    d5.setDay(25);
    d5.setYear(2026);
    std::cout << "d5 after valid sets (12/25/2026): " << d5.toString() << std::endl;

    // Test Case 6: Setting invalid values via setters
    std::cout << "\nAttempting to set invalid day (0) on d5:" << std::endl;
    d5.setDay(0); // Should fail, d5 remains 12/25/2026
    std::cout << "d5 after invalid day set: " << d5.toString() << std::endl;

    std::cout << "\nAttempting to set invalid month (100) on d5:" << std::endl;
    d5.setMonth(100); // Should fail, d5 remains 12/25/2026
    std::cout << "d5 after invalid month set: " << d5.toString() << std::endl;

    std::cout << "\nAttempting to set valid year (1999) on d5:" << std::endl;
    d5.setYear(1999); // Should succeed
    std::cout << "d5 after valid year set: " << d5.toString() << std::endl; // Expected: 12/25/1999

    return 0;
}