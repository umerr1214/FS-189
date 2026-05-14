#include <iostream>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    // Syntax Error: Missing return type 'double' for the method below
    add(double a, double b) { 
        return a + b;
    }
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;
    // The following lines will not compile due to the syntax error above
    // std::cout << "Sum of 5 and 7 (int): " << calc.add(5, 7) << std::endl;
    // std::cout << "Sum of 5.5 and 7.7 (double): " << calc.add(5.5, 7.7) << std::endl;
    // std::cout << "Sum of 1, 2, and 3 (int): " << calc.add(1, 2, 3) << std::endl;
    return 0;
}