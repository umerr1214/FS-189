#include <iostream>
#include <string>
#include <iomanip> // For std::setw and std::setfill
#include <vector>
#include <tuple>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    bool isValidDate() {
        // Robustness Issue: Does not validate if year is positive (year > 0).
        // It will treat year 0 or negative years as potentially valid if month/day checks pass.
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > 31) return false; // Basic check, refined below

        // Robustness Issue: Flawed leap year logic for century years divisible by 400.
        // It incorrectly classifies years like 2000 as non-leap years.
        bool isLeap = (year % 4 == 0 && year % 100 != 0);

        int daysInMonth;
        switch (month) {
            case 2: // February
                daysInMonth = isLeap ? 29 : 28;
                break;
            case 4: case 6: case 9: case 11: // April, June, September, November
                daysInMonth = 30;
                break;
            default: // January, March, May, July, August, October, December
                daysInMonth = 31;
                break;
        }

        return day <= daysInMonth;
    }

    void displayDate() {
        std::cout << std::setfill('0') << std::setw(2) << day << '/'
                  << std::setfill('0') << std::setw(2) << month << '/'
                  << std::setfill('0') << std::setw(4) << year;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::tuple<int, int, int>> inputs = {
        {15, 3, 2023},   // Valid
        {29, 2, 2024},   // Leap year
        {29, 2, 2023},   // Non-leap year Feb
        {31, 4, 2023},   // Month with 30 days, invalid day
        {31, 1, 2023},   // Month with 31 days, valid day
        {1, 13, 2023},   // Invalid month (too high)
        {1, 0, 2023},    // Invalid month (too low)
        {0, 1, 2023},    // Invalid day (too low)
        {29, 2, 2000},   // Century leap year (divisible by 400) - Robustness bug: should be valid, will be invalid
        {29, 2, 1900},   // Century non-leap year (divisible by 100 but not 400)
        {1, 1, 0},       // Year 0 - Robustness bug: should be invalid, will be valid
        {1, 1, -2023}    // Negative year - Robustness bug: should be invalid, will be valid
    };

    for (const auto& input_tuple : inputs) {
        int d = std::get<0>(input_tuple);
        int m = std::get<1>(input_tuple);
        int y = std::get<2>(input_tuple);

        Date date(d, m, y);
        std::cout << "Input: " << d << " " << m << " " << y << "\n";
        std::cout << "isValid: " << (date.isValidDate() ? "true" : "false") << ", display: ";
        date.displayDate();
        std::cout << "\n";
    }
    return 0;
}