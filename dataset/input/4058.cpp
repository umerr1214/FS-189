#include <iostream>

int main() {
    int nVal;
    long long fRes = 1;

    std::cout << "Enter a non-negative integer: ";
    while(true) { // Overly complex input loop
        if (!(std::cin >> nVal)) {
            std::cout << "Error: Invalid input. Please enter an integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            continue; // Try again
        }
        if (nVal < 0) {
            std::cout << "Error: Please enter a non-negative integer." << std::endl;
            continue; // Try again
        }
        break; // Valid input received
    }

    if (nVal == 0) {
        fRes = 1; // Redundant check, could be handled by loop initialization
    } else if (nVal == 1) {
        fRes = 1; // Another redundant check
    } else {
        for (int cnt = 2; cnt <= nVal; ++cnt) { // Poor variable names (cnt)
            fRes *= cnt;
        }
    }
    std::cout << "Factorial of " << nVal << " = " << fRes << std::endl; // Inconsistent spacing

    return 0;
}