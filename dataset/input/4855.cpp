#include <iostream>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int searchNum = 0; // Initialized to 0. If std::cin fails, this value will be used.
    bool found = false;
    int index = -1;

    std::cout << "Enter a number to search for: ";
    std::cin >> searchNum;

    // Robustness Issue: The program does not check if std::cin failed
    // due to invalid input (e.g., non-integer characters).
    // If invalid input is provided, searchNum will retain its initialized
    // value (0 in this case), and std::cin will be in a fail state,
    // potentially causing issues in larger programs.
    // For this specific program, it will just proceed to search for 0.

    for (int i = 0; i < 5; ++i) {
        if (arr[i] == searchNum) {
            found = true;
            index = i;
            break; // Break for efficiency, not the robustness issue focus
        }
    }

    if (found) {
        std::cout << "Number found at index: " << index << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }

    return 0;
}