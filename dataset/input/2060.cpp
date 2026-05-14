#include <iostream>
#include <string>

class Date {
private:
    int d_val; // Cryptic variable name for day
    int m_val; // Cryptic variable name for month
    int y_val; // Cryptic variable name for year

public:
    // Parameterized constructor
    Date(int p1, int p2, int p3) { // Cryptic parameter names
        // Redundant assignments for readability issue
        int temp_d = p1;
        this->d_val = temp_d; // Explicit this-> for verbosity

        int temp_m = p2;
        this->m_val = temp_m;

        int temp_y = p3;
        this->y_val = temp_y;
    }

    // Public getter methods - slightly verbose
    int getDay() const {
        int currentDay = d_val; // Unnecessary temporary variable
        return currentDay;
    }

    int getMonth() const {
        int currentMonth = m_val;
        return currentMonth;
    }

    int getYear() const {
        int currentYear = y_val;
        return currentYear;
    }
};

int main() {
    // Test case 1: Valid date
    Date d1(15, 7, 2023);
    std::cout << "Date 1: " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() << std::endl;

    // Test case 2: Another valid date
    Date d2(1, 1, 2000);
    std::cout << "Date 2: " << d2.getDay() << "/" << d2.getMonth() << "/" << d2.getYear() << std::endl;

    // Test case 3: A different valid date
    Date d3(31, 12, 1999);
    std::cout << "Date 3: " << d3.getDay() << "/" << d3.getMonth() << "/" << d3.getYear() << std::endl;

    return 0;
}