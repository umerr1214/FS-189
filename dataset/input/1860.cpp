#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void displayDate() const {
        // Semantic Error: Attempting to modify a member variable ('day')
        // within a 'const' member function. This violates const-correctness.
        this->day = 1; // Compiler will flag this as an error
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};

int main() {
    Date today(25, 10, 2023);
    std::cout << "Non-const date: ";
    today.displayDate();

    const Date anniversary(1, 1, 2024);
    std::cout << "Const date: ";
    anniversary.displayDate();

    return 0;
}