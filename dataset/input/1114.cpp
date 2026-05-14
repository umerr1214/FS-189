#include <iostream>
#include <string>
#include <iomanip> // For std::setw, std::setfill

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
} // Syntax Error: Missing semicolon after class definition

std::ostream& operator<<(std::ostream& os, const Date& d) {
    os << std::setw(2) << std::setfill('0') << d.getDay() << "/"
       << std::setw(2) << std::setfill('0') << d.getMonth() << "/"
       << d.getYear();
    return os;
}

int main() {
    Date d1(1, 5, 2023);
    Date d2(25, 12, 1999);
    Date d3(9, 7, 2020);

    std::cout << "Date 1: " << d1 << std::endl;
    std::cout << "Date 2: " << d2 << std::endl;
    std::cout << "Date 3: " << d3 << std::endl;

    return 0;
}