#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    void print() const {
        std::cout << day << "/" << month << "/" << year;
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    Date d1(1, 1, 2023);
    Date d2(1, 1, 2023);
    Date d3(2, 1, 2023);
    Date d4(1, 2, 2023);
    Date d5(1, 1, 2024);

    std::cout << "d1: "; d1.print(); std::cout << std::endl;
    std::cout << "d2: "; d2.print(); std::cout << std::endl;
    std::cout << "d3: "; d3.print(); std::cout << std::endl;
    std::cout << "d4: "; d4.print(); std::cout << std::endl;
    std::cout << "d5: "; d5.print(); std::cout << std::endl;

    std::cout << "d1 == d2: " << (d1 == d2 ? "true" : "false") << std::endl;
    std::cout << "d1 == d3: " << (d1 == d3 ? "true" : "false") << std::endl;
    std::cout << "d1 == d4: " << (d1 == d4 ? "true" : "false") << std::endl;
    std::cout << "d1 == d5: " << (d1 == d5 ? "true" : "false") << std::endl;

    return 0;
}