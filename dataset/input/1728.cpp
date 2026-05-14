#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    // Semantic Error: The 'add(double, double)' overload is intentionally omitted.
    // When add is called with two doubles, the compiler will implicitly convert
    // them to integers to call 'add(int, int)', leading to data loss and incorrect results.
    // double add(double a, double b) {
    //     return a + b;
    // }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;

    // Test 1: add two integers (Correct)
    int res1 = calc.add(5, 3);
    std::cout << "Add two integers (5, 3): " << res1 << std::endl;

    // Test 2: add two doubles (Semantic Error: Calls add(int, int) due to implicit conversion)
    // 5.5 becomes 5, 3.2 becomes 3. Result will be 5 + 3 = 8.0, instead of 8.7
    double res2 = calc.add(5.5, 3.2);
    std::cout << std::fixed << std::setprecision(1) << "Add two doubles (5.5, 3.2): " << res2 << std::endl;

    // Test 3: add three integers (Correct)
    int res3 = calc.add(1, 2, 3);
    std::cout << "Add three integers (1, 2, 3): " << res3 << std::endl;

    return 0;
}