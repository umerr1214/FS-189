#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    // Logical Error: Incorrect logic for leap year.
    // E.g. only checking % 4 without 100/400 exception?
    // Or implementing "divisible by 4 OR divisible by 100" which is wrong.
    // Or swapping the 100/400 logic.
    
    // Error: Fails to check % 400 exception correctly, or fails for century years.
    // Logic: if % 4 is true -> true. (Fails for 1900, 2100).
    
    if (year % 4 == 0) {
        return true; // Returns true for 1900 (should be false)
    }
    return false;
}

int main() {
    int year = 1900;
    // Expected: False
    // Actual: True
    if (isLeapYear(year)) cout << year << " is a leap year." << endl;
    else cout << year << " is not a leap year." << endl;
    return 0;
}
