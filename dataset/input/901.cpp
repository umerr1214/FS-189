#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
} // Syntax Error: Missing semicolon

int main() {
    int year = 2024;
    if (isLeapYear(year)) cout << year << " is a leap year." << endl;
    else cout << year << " is not a leap year." << endl;
    return 0;
}
