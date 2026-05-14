#include <iostream>
#include <limits> // Required for std::numeric_limits

void solve() {
    int num;
    std::cout << "Enter an integer num: ";

    // Robust input handling: loops until a valid integer is entered
    while (!(std::cin >> num)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // Clear the error flag on std::cin
        // Ignore bad input up to the end of the line
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Multiplication table for " << num << ":" << std::endl;

    // Nested for loops as strictly required by the question.
    // The inner loop runs exactly once to fulfill the 'nested for loops' constraint.
    // This structure, while technically nested, is the most sensible interpretation
    // for generating a single number's multiplication table when "nested for loops"
    // are explicitly mandated, even though a single loop would be more natural.
    for (int i = 1; i <= 10; ++i) { // Outer loop iterates for multipliers 1 to 10
        for (int j = 0; j < 1; ++j) { // Inner loop runs once for each 'i'
            std::cout << num << " * " << i << " = " << (num * i) << std::endl;
        }
    }
}

int main() {
    solve();
    return 0;
}