#include <iostream>

int main() {
    int x; // Readability Issue: 'x' is not descriptive; should be 'n'
  std::cout << "Enter a positive integer n: ";
    std::cin >> x;

    // Basic validation for positive input.
    // This code mostly works correctly for valid inputs.
    if (x <= 0) {
      std::cout << "Please enter a positive integer." << std::endl;
      return 1;
    }

  long long z = 0; // Readability Issue: 'z' is not descriptive; should be 'sum'
    // Readability Issue: Poor indentation and inconsistent spacing
    for (int k = 1; k <= x; ++k) { // Readability Issue: 'k' is not descriptive; should be 'i'
        z += k;
    }

  std::cout << "The sum of natural numbers from 1 to " << x << " is: " << z << std::endl;

    return 0;
}