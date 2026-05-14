#include <iostream>

// Core logic for 4778: Readability / Efficiency Issue (inefficient loop, less readable names)
void solve_4778() {
    int myNum; // Less descriptive variable name than 'N'
    std::cout << "Enter a positive integer N: ";
    std::cin >> myNum; // Assuming valid input for this category for simplicity of this error type

    int currentSum = 0; // Less descriptive variable name than 'sumOfOdds'
    for (int i = 1; i <= myNum; ++i) { // Inefficient: iterates through all numbers from 1 to N
        if (i % 2 != 0) { // Checks if odd in every iteration, which is redundant
            currentSum += i;
        }
    }

    std::cout << "The sum of odd numbers between 1 and " << myNum << " is: " << currentSum << std::endl;
}

int main() {
    solve_4778();
    return 0;
}