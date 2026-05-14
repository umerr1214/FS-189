#include <iostream>
#include <vector>
#include <numeric> // Required for std::accumulate

class Calculator {
public:
    // Adds two integers using std::accumulate with a temporary vector
    int add(int operand1, int operand2) {
        std::vector<int> numbers_to_sum = {operand1, operand2};
        return std::accumulate(numbers_to_sum.begin(), numbers_to_sum.end(), 0);
    }

    // Adds three integers using std::accumulate with a temporary vector
    int add(int first_val, int second_val, int third_val) {
        std::vector<int> temporary_vec_for_sum = {first_val, second_val, third_val};
        return std::accumulate(temporary_vec_for_sum.begin(), temporary_vec_for_sum.end(), 0);
    }

    // Adds two doubles with verbose variable names and an unnecessary temporary variable
    double add(double valA, double valB) {
        double resultant_sum_value = valA + valB; // Unnecessary temporary variable
        return resultant_sum_value;
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
    std::cout << "add(0.1,0.2):" << calc.add(0.1, 0.2) << ";";
    std::cout << "add(1.23e20,4.56e20):" << calc.add(1.23e20, 4.56e20) << ";";

    return 0;
}