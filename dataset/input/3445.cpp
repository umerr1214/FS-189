#include <iostream>
#include <vector>
#include <limits> // Required for std::numeric_limits

void solve() {
    const int SIZE = 5;
    int numbers[SIZE];

    std::cout << "Enter " << SIZE << " integers:\n";

    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> numbers[i];
        // Robustness issue: No check for std::cin.fail() or bad input.
        // If user enters non-integer, cin will enter a fail state,
        // leading to potential infinite loops or incorrect behavior.
    }

    if (SIZE == 0) {
        // This case is not reachable due to fixed SIZE=5, but good practice for robustness.
        std::cout << "Array is empty.\n";
        return;
    }

    int largestElement = numbers[0];
    for (int i = 1; i < SIZE; ++i) {
        if (numbers[i] > largestElement) {
            largestElement = numbers[i];
        }
    }

    std::cout << "The largest element is: " << largestElement << "\n";
}

int main() {
    solve();
    return 0;
}