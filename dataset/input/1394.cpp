#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor without validation (not the primary issue here)
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Overload the == operator with multiple conditional checks
    // This is less concise and potentially less efficient than a single logical expression.
    bool operator==(const Date& other) const {
        if (day != other.day) {
            return false;
        }
        if (month != other.month) {
            return false;
        }
        if (year != other.year) {
            return false;
        }
        return true; // All components are equal
    }

    // Helper to print date for verification
    void print() const {
        std::cout << day << "/" << month << "/" << year;
    }
};

int main() {
    // Test cases for the Date class
    Date d1(1, 1, 2024);
    Date d2(1, 1, 2024);
    Date d3(2, 1, 2024);
    Date d4(1, 2, 2024);
    Date d5(1, 1, 2025);

    std::cout << "d1: "; d1.print(); std::cout << std::endl;
    std::cout << "d2: "; d2.print(); std::cout << std::endl;
    std::cout << "d3: "; d3.print(); std::cout << std::endl;

    std::cout << "d1 == d2: " << (d1 == d2 ? "true" : "false") << std::endl; // Expected: true
    std::cout << "d1 == d3: " << (d1 == d3 ? "true" : "false") << std::endl; // Expected: false
    std::cout << "d1 == d4: " << (d1 == d4 ? "true" : "false") << std::endl; // Expected: false
    std::cout << "d1 == d5: " << (d1 == d5 ? "true" : "false") << std::endl; // Expected: false

    return 0;
}