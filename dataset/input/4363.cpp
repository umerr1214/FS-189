#include <iostream>

// Function to multiply the value at a memory address by two
// Lacks nullptr check, leading to a crash if a null pointer is passed.
void multiplyByTwo(int* ptr) {
    // Robustness issue: Dereferencing a potentially null pointer without checking
    *ptr = *ptr * 2;
}

int main() {
    int num1 = 5;
    // std::cout << "Initial value of num1: " << num1 << std::endl;
    multiplyByTwo(&num1);
    std::cout << num1 << std::endl; // Expected: 10

    int num2 = 0;
    // std::cout << "Initial value of num2: " << num2 << std::endl;
    multiplyByTwo(&num2);
    std::cout << num2 << std::endl; // Expected: 0

    int num3 = -3;
    // std::cout << "Initial value of num3: " << num3 << std::endl;
    multiplyByTwo(&num3);
    std::cout << num3 << std::endl; // Expected: -6

    // Demonstrating the robustness issue: Passing a nullptr
    int* nullPtr = nullptr;
    // std::cout << "Attempting to call multiplyByTwo with a nullptr..." << std::endl;
    // This line will cause a segmentation fault (runtime error)
    multiplyByTwo(nullPtr);
    // std::cout << "This line will likely not be reached if a crash occurs." << std::endl;

    return 0;
}