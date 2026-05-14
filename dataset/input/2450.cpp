#include <iostream>
#include <iomanip>    // For std::fixed and std::setprecision
#include <vector>     // For std::vector
#include <numeric>    // For std::accumulate

class MathOperations {
public:
    // Overloaded add method for two integers
    int add(int a, int b) const {
        return a + b;
    }

    // Overloaded add method for two doubles
    double add(double a, double b) const {
        return a + b;
    }

    // Overloaded add method for three integers - Readability/Efficiency Issue
    // Using std::vector and std::accumulate for three numbers is less efficient
    // and less readable than a direct sum (a + b + c) for such a small, fixed count.
    int add(int a, int b, int c) const {
        std::vector<int> numbers = {a, b, c};
        return std::accumulate(numbers.begin(), numbers.end(), 0);
    }
};

int main() {
    MathOperations mo;

    // Test add(int, int)
    std::cout << "add(5, 3) = " << mo.add(5, 3) << std::endl;
    std::cout << "add(-1, 10) = " << mo.add(-1, 10) << std::endl;
    std::cout << "add(0, 0) = " << mo.add(0, 0) << std::endl;

    // Test add(double, double)
    std::cout << std::fixed << std::setprecision(1); // Set precision for doubles
    std::cout << "add(5.5, 3.2) = " << mo.add(5.5, 3.2) << std::endl;
    std::cout << "add(-1.0, 10.5) = " << mo.add(-1.0, 10.5) << std::endl;
    std::cout << "add(0.0, 0.0) = " << mo.add(0.0, 0.0) << std::endl;

    // Test add(int, int, int)
    std::cout << std::setprecision(6); // Reset precision for int outputs (or default)
    std::cout << "add(1, 2, 3) = " << mo.add(1, 2, 3) << std::endl;
    std::cout << "add(-1, 0, 1) = " << mo.add(-1, 0, 1) << std::endl;
    std::cout << "add(10, -5, 2) = " << mo.add(10, -5, 2) << std::endl;

    return 0;
}