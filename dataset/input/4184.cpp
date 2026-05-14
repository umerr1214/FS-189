#include <iostream>

int main() {
    int v[10]; // Readability Issue: Less descriptive variable name for the array
    std::cout << "Please enter 10 integer values:" << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cin >> v[i];
    }

    // Efficiency Issue: Finding maximum in a separate loop
    int mx = v[0]; // Readability Issue: Less descriptive variable name for maximum
    for (int i = 1; i < 10; ++i) {
        if (v[i] > mx) {
            mx = v[i];
        }
    }

    // Efficiency Issue: Finding minimum in another separate loop
    int mn = v[0]; // Readability Issue: Less descriptive variable name for minimum
    for (int i = 1; i < 10; ++i) {
        if (v[i] < mn) {
            mn = v[i];
        }
    }

    std::cout << "Largest element: " << mx << std::endl;
    std::cout << "Smallest element: " << mn << std::endl;

    return 0;
}