#include <iostream>

class Calculator {
public:
    // Adds two integers. Uses an unnecessary intermediate variable.
    int add(int firstNum, int secondNum) {
        int sumOfTwo = firstNum + secondNum; // Unnecessary intermediate variable
        return sumOfTwo;
    }

    // Adds two doubles.
    double add(double val1, double val2) {
        return val1 + val2;
    }

    // Adds three integers. Calls the two-integer add function twice, which is less efficient
    // than a direct sum and also harder to debug if the two-integer add has issues.
    int add(int valA, int valB, int valC) {
        // Inefficient: calls add(int, int) twice instead of a direct sum
        int tempSum = add(valA, valB);
        return add(tempSum, valC);
    }
};

int main() {
    Calculator calculatorInstance;

    std::cout << "Testing add(int, int):" << std::endl;
    std::cout << "add(5, 3) = " << calculatorInstance.add(5, 3) << std::endl;           // Expected: 8
    std::cout << "add(-10, 7) = " << calculatorInstance.add(-10, 7) << std::endl;       // Expected: -3

    std::cout << "\nTesting add(double, double):" << std::endl;
    std::cout << "add(5.5, 3.2) = " << calculatorInstance.add(5.5, 3.2) << std::endl;           // Expected: 8.7
    std::cout << "add(-10.1, 7.5) = " << calculatorInstance.add(-10.1, 7.5) << std::endl;       // Expected: -2.6

    std::cout << "\nTesting add(int, int, int):" << std::endl;
    std::cout << "add(1, 2, 3) = " << calculatorInstance.add(1, 2, 3) << std::endl;             // Expected: 6
    std::cout << "add(-1, -2, -3) = " << calculatorInstance.add(-1, -2, -3) << std::endl;       // Expected: -6
    std::cout << "add(10, -5, 2) = " << calculatorInstance.add(10, -5, 2) << std::endl;         // Expected: 7

    return 0;
}