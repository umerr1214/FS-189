#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

class Vector2D {
private:
    double _coordinate_x_value; // Overly verbose variable name
    double _coordinate_y_value; // Overly verbose variable name

public:
    // Verbose constructor implementation
    Vector2D(double initial_x_component_value = 0.0, double initial_y_component_value = 0.0) {
        // Explicitly use 'this' for member initialization, making it verbose
        this->_coordinate_x_value = initial_x_component_value;
        this->_coordinate_y_value = initial_y_component_value;
    }

    // Friend declarations for non-member operators to access private members
    // This is good practice for non-member operators, but the implementation will be verbose.
    friend Vector2D operator+(const Vector2D& left_vector_operand, const Vector2D& right_vector_operand);
    friend std::ostream& operator<<(std::ostream& output_stream, const Vector2D& vector_object_to_print);
};

// Overloaded binary '+' operator for vector addition (non-member function)
// This implementation is correct but unnecessarily verbose and slightly less efficient
// than direct initialization.
Vector2D operator+(const Vector2D& left_vector_operand, const Vector2D& right_vector_operand) {
    // A temporary Vector2D object is default-constructed first.
    // This involves a default constructor call.
    Vector2D result_of_addition_vector;

    // Then, its private members are assigned values.
    // This is less efficient than directly constructing the result with the final values.
    result_of_addition_vector._coordinate_x_value = left_vector_operand._coordinate_x_value + right_vector_operand._coordinate_x_value;
    result_of_addition_vector._coordinate_y_value = left_vector_operand._coordinate_y_value + right_vector_operand._coordinate_y_value;

    // The temporary result object is returned by value.
    return result_of_addition_vector;
}

// Overload the output stream operator for easy printing with verbose parameter names
std::ostream& operator<<(std::ostream& output_stream, const Vector2D& vector_object_to_print) {
    output_stream << "(" << vector_object_to_print._coordinate_x_value << ", " << vector_object_to_print._coordinate_y_value << ")";
    return output_stream;
}

int main() {
    // Set output precision for doubles
    std::cout << std::fixed << std::setprecision(1);

    // Test 1: Addition of two positive vectors
    Vector2D v1_obj(1.0, 2.0); // Verbose variable names in main as well
    Vector2D v2_obj(3.0, 4.0);
    Vector2D v3_result_obj = v1_obj + v2_obj;
    std::cout << v3_result_obj << std::endl;

    // Test 2: Addition involving negative and decimal coordinates
    Vector2D v_negative_x_obj(-1.0, 2.5);
    Vector2D v_negative_y_obj(3.5, -4.0);
    Vector2D v_negative_result_obj = v_negative_x_obj + v_negative_y_obj;
    std::cout << v_negative_result_obj << std::endl;

    // Test 3: Chained addition
    Vector2D v_chain_first(1.0, 1.0);
    Vector2D v_chain_second(2.0, 2.0);
    Vector2D v_chain_third(3.0, 3.0);
    Vector2D v_chained_sum_result = v_chain_first + v_chain_second + v_chain_third;
    std::cout << v_chained_sum_result << std::endl;

    // Test 4: Addition with a zero vector
    Vector2D v_zero_coordinates(0.0, 0.0);
    Vector2D v_non_zero_coordinates(5.0, 6.0);
    Vector2D v_zero_sum_result = v_zero_coordinates + v_non_zero_coordinates;
    std::cout << v_zero_sum_result << std::endl;

    return 0;
}