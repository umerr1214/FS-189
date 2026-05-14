#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

void solve() {
    int numbers[8]; // Uses a C-style array with a magic number for its size.
    long long totalSum = 0; // Using long long for sum.
    int k = 0; // Variable name 'k' is less descriptive than 'i' or 'index'.

    std::cout << "Kindly input eight numerical values, please:" << std::endl; // Overly formal and verbose prompt.

    // Loop for input, using magic number 8.
    for (k = 0; k < 8; ++k) {
        std::cout << "Provide value number " << k + 1 << ": "; // Verbose prompt.
        std::cin >> numbers[k]; // No input validation, which is a minor quality issue here.
    }

    // Separate loop to calculate the sum. For a small, fixed-size array,
    // this could be combined with the input loop for slightly better efficiency
    // and reduced code length, though not a major performance bottleneck.
    for (k = 0; k < 8; ++k) { // Magic number 8 again.
        totalSum = totalSum + numbers[k]; // Verbose addition.
    }

    double avgResult = (double)totalSum / 8; // Uses magic number 8 and a C-style cast.

    std::cout << std::fixed << std::setprecision(1) << "The computed arithmetic mean is: " << avgResult << "." << std::endl; // Verbose and slightly informal output.
}

int main() {
    solve();
    return 0;
}