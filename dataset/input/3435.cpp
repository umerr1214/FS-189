#include <iostream>
#include <string>

// Function containing the core logic
void solve(std::istream& in, std::ostream& out) {
    int num;
    out << "Enter a non-negative integer: ";
    in >> num;

    // Input validation: Ensure the number is non-negative
    if (num < 0) {
        out << "Invalid input. Please enter a non-negative integer." << std::endl;
        return;
    }

    // Use long long to handle larger factorial values without overflow
    // Factorials grow very quickly, so `long long` is appropriate for inputs up to 20.
    long long factorial = 1; 

    // Calculate factorial using a for loop
    // The loop correctly handles 0! (factorial remains 1 as loop doesn't run)
    // and 1! (loop runs once for i=1, factorial remains 1).
    for (int i = 1; i <= num; ++i) {
        factorial *= i;
    }

    out << "Factorial of " << num << " is " << factorial << "." << std::endl;
}

int main() {
    solve(std::cin, std::cout);
    return 0;
}