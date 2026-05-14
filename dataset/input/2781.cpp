#include <iostream>

class Calculator {
public:
    // Adds two integers
    int add(int a, int b) {
        return a + b;
    }

    // Adds three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Adds two doubles
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    // Test cases for int add(int, int)
    std::cout << "add(10,20):" << calc.add(10, 20) << ";";
    std::cout << "add(-5,-10):" << calc.add(-5, -10) << ";";
    std::cout << "add(100,-50):" << calc.add(100, -50) << ";";
    std::cout << "add(0,0):" << calc.add(0, 0) << ";";
    std::cout << "add(2000000000,1000000000):" << calc.add(2000000000, 1000000000) << ";";

    // Test cases for int add(int, int, int)
    std::cout << "add(1,2,3):" << calc.add(1, 2, 3) << ";";
    std::cout << "add(-1,-2,-3):" << calc.add(-1, -2, -3) << ";";
    std::cout << "add(10,-5,2):" << calc.add(10, -5, 2) << ";";
    std::cout << "add(0,0,0):" << calc.add(0, 0, 0) << ";";
    std::cout << "add(1000000000,1000000000,1000000000):" << calc.add(1000000000, 1000000000, 1000000000) << ";";

    // Test cases for double add(double, double)
    std::cout << "add(1.5,2.5):" << calc.add(1.5, 2.5) << ";";
    std::cout << "add(-1.0,-0.5):" << calc.add(-1.0, -0.5) << ";";
    std::cout << "add(3.14,-1.0):" << calc.add(3.14, -1.0) << ";";
    std::cout << "add(0.0,0.0):" << calc.add(0.0, 0.0) << ";";
    std::cout << "add(0.1,0.2):" << calc.add(0.1, 0.2) << \";\";
    std::cout << "add(1.23e20,4.56e20):" << calc.add(1.23e20, 4.56e20) << \";\";

    return 0;
}