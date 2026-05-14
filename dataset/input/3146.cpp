#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Calculator {
public:
    // Adds two integers
    int add(int first_integer_value, int second_integer_value) {
        // Using an unnecessary intermediate variable, slightly impacting efficiency/readability
        int result_of_two_ints_addition = first_integer_value + second_integer_value;
        return result_of_two_ints_addition;
    }

    // Adds two doubles
    double add(double first_double_operand, double second_double_operand) {
        // Overly verbose variable names, impacting readability
        double computed_sum_of_the_two_doubles = first_double_operand + second_double_operand;
        return computed_sum_of_the_two_doubles;
    }

    // Adds three integers
    int add(int parameter_one, int parameter_two, int parameter_three) {
        // Unnecessarily breaking down the addition, though compiler might optimize.
        // Still, it's less direct and slightly less efficient in source code expression.
        int partial_sum_a_b = parameter_one + parameter_two;
        int final_sum_a_b_c = partial_sum_a_b + parameter_three;
        return final_sum_a_b_c;
    }
};

int main() {
    Calculator my_calculator_instance; // Long instance name

    std::cout << "--- Integer Addition (Two) ---" << std::endl;
    std::cout << "Result of 25 + 75 is: " << my_calculator_instance.add(25, 75) << std::endl; // Expected: 100
    std::cout << "Result of -10 + 30 is: " << my_calculator_instance.add(-10, 30) << std::endl; // Expected: 20

    std::cout << "\n--- Double Addition ---" << std::endl;
    std::cout << std::fixed << std::setprecision(1); // Set precision for consistent double output
    std::cout << "Result of 15.7 + 4.3 is: " << my_calculator_instance.add(15.7, 4.3) << std::endl; // Expected: 20.0
    std::cout << "Result of -8.2 + 2.0 is: " << my_calculator_instance.add(-8.2, 2.0) << std::endl; // Expected: -6.2

    std::cout << "\n--- Integer Addition (Three) ---" << std::endl;
    std::cout << "Result of 5 + 10 + 15 is: " << my_calculator_instance.add(5, 10, 15) << std::endl; // Expected: 30
    std::cout << "Result of 1 + -1 + 100 is: " << my_calculator_instance.add(1, -1, 100) << std::endl; // Expected: 100

    return 0;
}