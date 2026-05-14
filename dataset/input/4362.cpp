#include <iostream>

void multiplyByTwo(int* ptr) {
    // Semantic error: calculates doubled value but assigns a pointer to a local variable
    // to 'ptr', rather than modifying the value at the original memory address 'ptr' points to.
    int temp = *ptr * 2;
    ptr = &temp; // This changes the local copy of the pointer 'ptr' to point to 'temp'.
                 // The original memory address passed to the function is not modified.
}

int main() {
    int num1 = 5;
    std::cout << "Original value: " << num1 << std::endl;
    multiplyByTwo(&num1);
    std::cout << "After multiplyByTwo: " << num1 << std::endl;

    int num2 = 10;
    std::cout << "Original value: " << num2 << std::endl;
    multiplyByTwo(&num2);
    std::cout << "After multiplyByTwo: " << num2 << std::endl;
    return 0;
}