#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void displayDate() const {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    Date today(25, 10, 2023);
    std::cout << "Non-const date: ";
    today.displayDate();

    const Date anniversary(1, 1, 2024);
    std::cout << "Const date: ";
    anniversary.displayDate();

    return 0;
}