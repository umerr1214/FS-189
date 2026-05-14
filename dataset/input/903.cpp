#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    // Semantic Error: bitwise operators vs arithmetic?
    // Or using assignment.
    
    // Let's use bitwise AND with 3 instead of % 4.
    // year & 3 == 0 is equivalent to year % 4 == 0. This is actually correct optimization!
    // We need an error.
    
    // Let's use bitwise OR.
    // if ((year | 4) == 0) // Never true for positive year.
    
    // Let's use assignment.
    // if (year = 2000) // Sets to 2000, returns true.
    
    // Let's confuse logical operators.
    // year % 4 == 0 & year % 100 != 0
    // Bitwise AND between boolean results? (1 & 1 -> 1). This works too.
    
    // Let's use incorrect type logic?
    // Using string comparison?
    
    // Let's use the assignment error.
    if (year = 2000) { // Semantic Error: Assignment in condition
        return true;
    }
    return false;
}

int main() {
    int year = 1999;
    // Expected: False (1999)
    // Actual: True (because assigns 2000)
    if (isLeapYear(year)) cout << year << " is a leap year." << endl;
    else cout << year << " is not a leap year." << endl;
    return 0;
}
