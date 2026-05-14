#include <iostream>

class MathOperations {
public:
    int add(int a, int b);
    double add(double a, double b); // Missing semicolon here
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int MathOperations::add(int a, int b) {
    return a + b;
}

double MathOperations::add(double a, double b) {
    return a + b;
}

int main() {
    MathOperations ops;
    std::cout << "Sum of 5 and 10 (int): " << ops.add(5, 10) << std::endl;
    std::cout << "Sum of 5.5 and 10.5 (double): " << ops.add(5.5, 10.5) << std::endl;
    std::cout << "Sum of 1, 2, and 3 (int): " << ops.add(1, 2, 3) << std::endl;
    return 0;
}