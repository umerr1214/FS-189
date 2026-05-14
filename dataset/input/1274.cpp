#include <iostream>
#include <string> // For verbose debug messages
#include <iomanip> // For std::fixed, std::setprecision

// Unnecessary namespace and template function for simple addition,
// demonstrating a readability/efficiency issue through over-engineering.
namespace VerboseMathOperations {
    template<typename NumericType>
    NumericType perform_basic_summation_of_two_operands(NumericType first_value_to_add, NumericType second_value_to_add) {
        // This helper function performs a very simple addition.
        // Its existence and verbosity are meant to demonstrate poor readability/efficiency.
        NumericType intermediate_sum_result = first_value_to_add + second_value_to_add;
        return intermediate_sum_result;
    }
}

class Calculator {
public:
    // Overloaded method for integer addition
    int add(int first_integer_operand_value, int second_integer_operand_value) {
        // Extensive comments and debug output for a simple operation, hindering readability and efficiency.
        std::cout << "DEBUG_LOG: Initiating integer addition process for operands: " 
                  << first_integer_operand_value << " and " << second_integer_operand_value << std::endl;
        
        // Using an unnecessary helper function for basic arithmetic.
        int final_integer_summation_result = VerboseMathOperations::perform_basic_summation_of_two_operands(
            first_integer_operand_value, 
            second_integer_operand_value
        );
        
        std::cout << "DEBUG_LOG: Integer addition completed. Result: " << final_integer_summation_result << std::endl;
        return final_integer_summation_result;
    }

    // Overloaded method for double-precision floating-point addition
    double add(double first_double_operand_value, double second_double_operand_value) {
        std::cout << "DEBUG_LOG: Initiating double addition process for operands: " 
                  << first_double_operand_value << " and " << second_double_operand_value << std::endl;
        
        double final_double_summation_result = VerboseMathOperations::perform_basic_summation_of_two_operands(
            first_double_operand_value, 
            second_double_operand_value
        );
        
        std::cout << "DEBUG_LOG: Double addition completed. Result: " << final_double_summation_result << std::endl;
        return final_double_summation_result;
    }

    // Overloaded method for single-precision floating-point addition
    float add(float first_float_operand_value, float second_float_operand_value) {
        std::cout << "DEBUG_LOG: Initiating float addition process for operands: " 
                  << first_float_operand_value << " and " << second_float_operand_value << std::endl;
        
        float final_float_summation_result = VerboseMathOperations::perform_basic_summation_of_two_operands(
            first_float_operand_value, 
            second_float_operand_value
        );
        
        std::cout << "DEBUG_LOG: Float addition completed. Result: " << final_float_summation_result << std::endl;
        return final_float_summation_result;
    }
};

int main() {
    Calculator calc;

    // Set precision for floating-point output for consistency in testing
    std::cout << std::fixed << std::setprecision(6);

    // This main function is for direct execution to show the problem.
    // The driver in the JSON will use std::cin for specific test cases.

    std::cout << "--- Demonstrating Calculator (Readability/Efficiency Issue) ---\n";

    std::cout << "\nTest 1 (Int):\n";
    std::cout << "Result: " << calc.add(100, 200) << std::endl;

    std::cout << "\nTest 2 (Double):\n";
    std::cout << "Result: " << calc.add(123.45, 67.89) << std::endl;

    std::cout << "\nTest 3 (Float):\n";
    std::cout << "Result: " << calc.add(50.5f, 25.5f) << std::endl;

    return 0;
}