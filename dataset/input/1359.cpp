#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

/**
 * @brief A Calculator class demonstrating overloaded addition methods.
 *
 * This class provides methods to add integers and doubles with different
 * numbers of arguments.
 */
class Calculator {
public:
    /**
     * @brief Adds two integers.
     * @param num1 The first integer.
     * @param num2 The second integer.
     * @return The sum of the two integers.
     */
    int add(int num1, int num2) const noexcept {
        return num1 + num2;
    }

    /**
     * @brief Adds two doubles.
     * @param num1 The first double.
     * @param num2 The second double.
     * @return The sum of the two doubles.
     */
    double add(double num1, double num2) const noexcept {
        return num1 + num2;
    }

    /**
     * @brief Adds three integers.
     * @param num1 The first integer.
     * @param num2 The second integer.
     * @param num3 The third integer.
     * @return The sum of the three integers.
     */
    int add(int num1, int num2, int num3) const noexcept {
        return num1 + num2 + num3;
    }
};

int main() {
    Calculator myCalculator; // Create an instance of the Calculator class

    // --- Demonstrate calling the add(int, int) method ---
    int intA = 10;
    int intB = 20;
    int sumInt = myCalculator.add(intA, intB);
    std::cout << "Int sum: " << sumInt << '\n';

    // --- Demonstrate calling the add(double, double) method ---
    double doubleX = 10.5;
    double doubleY = 20.5;
    double sumDouble = myCalculator.add(doubleX, doubleY);
    // Use std::fixed and std::setprecision for consistent double output
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Double sum: " << sumDouble << '\n';

    // --- Demonstrate calling the add(int, int, int) method ---
    int intP = 1;
    int intQ = 2;
    int intR = 3;
    int sumThreeInt = myCalculator.add(intP, intQ, intR);
    std::cout << "Three int sum: " << sumThreeInt << '\n';

    return 0;
}