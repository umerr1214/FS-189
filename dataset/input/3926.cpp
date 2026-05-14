#include <iostream>
#include <string>
#include <limits> // Included but not fully utilized for buffer clearing, which is a minor point for efficiency/robustness

// This program demonstrates readability and efficiency issues:
// - Uses `std::string::at(i)` which includes bounds checking overhead in each iteration.
// - Calls `strInput.length()` in the loop condition, which might be re-evaluated (though often optimized by modern compilers).
// - Uses less descriptive variable names.
// - Lacks comments for clarity.
void solve() {
    std::string strInput; // Less descriptive variable name
    char charFind;       // Less descriptive variable name
    int countOccur = 0;  // Less descriptive variable name

    std::cout << "Enter string: ";
    std::getline(std::cin, strInput); // Correctly reads full line

    std::cout << "Enter character: ";
    std::cin >> charFind; // Correctly reads character

    // Inefficient loop:
    // 1. `strInput.length()` is called in the loop condition, potentially re-evaluating string length on each iteration.
    // 2. `strInput.at(i)` performs bounds checking in each iteration, adding overhead compared to `strInput[i]`.
    for (int i = 0; i < strInput.length(); ++i) { 
        if (strInput.at(i) == charFind) { 
            countOccur++;
        }
    }

    std::cout << "The character '" << charFind << "' appears " << countOccur << " time";
    if (countOccur != 1) {
        std::cout << "s";
    }
    std::cout << " in \"" << strInput << "\"." << std::endl;
}

int main() {
    solve();
    return 0;
}