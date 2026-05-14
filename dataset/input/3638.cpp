#include <iostream>
#include <iomanip> // For output formatting

int main() {
    float a[5]; // Poor, non-descriptive variable name for array
    float s = 0.0f; // Poor, non-descriptive variable name for sum
    int i = 0; // Loop variable declared outside, slightly less idiomatic for a simple for loop

    std::cout << "Enter 5 floating numbers:" << std::endl; // Less descriptive prompt

    while (i < 5) { // Uses magic number 5; a const variable would be better
        std::cout << "Num " << i + 1 << ": "; // Abbreviated prompt
        std::cin >> a[i];
        i++;
    }

    // Separate loop for summation, slightly less efficient than summing during input
    // for a small array, but mainly a readability/style choice.
    for (i = 0; i < 5; ++i) { // Magic number 5 again; 'i' is reused without clear reset
        s = s + a[i];
    }

    float x = s / 5; // Poor, non-descriptive variable name for average; magic number 5

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The average is: " << x << std::endl; // Less descriptive output message

    return 0;
}