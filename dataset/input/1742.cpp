#include <iostream>
#include <sstream>
#include <string>

class ComplexNumber {
private:
    double real_part_of_complex_value; // Verbose member name
    double imaginary_part_of_complex_value; // Verbose member name

public:
    // Readability Issue: Constructor parameters are in a confusing order (imaginary then real)
    // and have overly verbose names.
    ComplexNumber(double initial_imaginary_component_value = 0.0, double initial_real_component_value = 0.0)
        : real_part_of_complex_value(initial_real_component_value),
          imaginary_part_of_complex_value(initial_imaginary_component_value) {}

    // Overly verbose getter methods
    double retrieve_the_real_part() const { return real_part_of_complex_value; }
    double retrieve_the_imaginary_part() const { return imaginary_part_of_complex_value; }

    // Readability/Efficiency Issue:
    // - Uses `this->` excessively.
    // - Overly verbose variable names within the operator.
    // - Creates an unnecessary temporary `ComplexNumber` object `result_of_addition`
    //   when a direct return could be used (minor efficiency, major readability).
    ComplexNumber operator+(const ComplexNumber& another_complex_number_object) const {
        double temporary_sum_for_real_parts = this->real_part_of_complex_value + another_complex_number_object.real_part_of_complex_value;
        double temporary_sum_for_imaginary_parts = this->imaginary_part_of_complex_value + another_complex_number_object.imaginary_part_of_complex_value;

        // Efficiency/Readability: Constructor parameter order is still confusing here.
        // Creates a named temporary object then returns it.
        ComplexNumber result_of_addition(temporary_sum_for_imaginary_parts, temporary_sum_for_real_parts);
        return result_of_addition;
    }
};

// Stream insertion operator with verbose internal calls
std::ostream& operator<<(std::ostream& output_stream_object, const ComplexNumber& current_complex_number_instance) {
    output_stream_object << current_complex_number_instance.retrieve_the_real_part()
                         << " + "
                         << current_complex_number_instance.retrieve_the_imaginary_part()
                         << "i";
    return output_stream_object;
}

int main() {
    std::string line_of_input_data;
    while (std::getline(std::cin, line_of_input_data)) {
        std::istringstream input_string_stream_for_parsing(line_of_input_data);
        double first_real_value, first_imaginary_value, second_real_value, second_imaginary_value;
        if (!(input_string_stream_for_parsing >> first_real_value >> first_imaginary_value >> second_real_value >> second_imaginary_value)) {
            std::cerr << "Error: Malformed input data. Please provide four double values." << std::endl;
            continue;
        }

        // Note: Constructor order is (imaginary, real)
        ComplexNumber first_operand_complex_number(first_imaginary_value, first_real_value);
        ComplexNumber second_operand_complex_number(second_imaginary_value, second_real_value);

        ComplexNumber final_computed_sum_complex_number = first_operand_complex_number + second_operand_complex_number;

        output_stream_object << final_computed_sum_complex_number << std::endl;
    }
    return 0;
}