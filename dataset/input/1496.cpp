#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Calculator {
public:
    // Methods are not marked const, even though they don't modify the object's state
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator my_calculator_instance; // Slightly verbose variable name

    std::cout << "--- Readability / Efficiency Issue Demonstration ---" << std::endl; // Using std::endl, which flushes buffer

    int integer_operand_one = 10;
    int integer_operand_two = 20;
    // Verbose output and unnecessary intermediate variables
    std::cout << "The sum of two integers " << integer_operand_one << " and " << integer_operand_two << " is: "
              << my_calculator_instance.add(integer_operand_one, integer_operand_two) << std::endl;

    double double_val_x = 15.5;
    double double_val_y = 7.25;
    // Setting precision for doubles, which is fine, but std::endl is used
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The sum of two double values " << double_val_x << " and " << double_val_y << " is: "
              << my_calculator_instance.add(double_val_x, double_val_y) << std::endl;

    int int_val_p = 100;
    int int_val_q = 200;
    int int_val_r = 300;
    std::cout << "The sum of three integers " << int_val_p << ", " << int_val_q << ", and " << int_val_r << " is: "
              << my_calculator_instance.add(int_val_p, int_val_q, int_val_r) << std::endl;

    return 0;
}