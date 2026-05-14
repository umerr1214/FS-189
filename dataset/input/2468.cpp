#include <iostream>
#include <string> // Included unnecessarily, but doesn't cause errors, just a minor inefficiency/readability quirk.

class ComplexNumber_With_Verbose_Names {
public:
    double real_part_of_complex_number;
    double imaginary_part_of_complex_number;

    // Constructor with default values
    ComplexNumber_With_Verbose_Names(double initial_real_value = 0.0, double initial_imaginary_value = 0.0) {
        real_part_of_complex_number = initial_real_value;
        imaginary_part_of_complex_number = initial_imaginary_value;
    }

    // Overload the addition operator
    // Uses verbose local variables before returning, making it less concise.
    ComplexNumber_With_Verbose_Names operator+(const ComplexNumber_With_Verbose_Names& another_complex_number_object) const {
        double resultant_real_value = this->real_part_of_complex_number + another_complex_number_object.real_part_of_complex_number;
        double resultant_imaginary_value = this->imaginary_part_of_complex_number + another_complex_number_object.imaginary_part_of_complex_number;
        
        ComplexNumber_With_Verbose_Names temporary_sum_object(resultant_real_value, resultant_imaginary_value);
        return temporary_sum_object; // Explicit temporary, though RVO often optimizes this.
    }

    // Overload the stream insertion operator
    // Produces overly verbose output, making 'easy printing' less easy to read.
    friend std::ostream& operator<<(std::ostream& output_stream_reference, const ComplexNumber_With_Verbose_Names& current_complex_number_object) {
        output_stream_reference << "Complex Number Object: [Real_Component=" << current_complex_number_object.real_part_of_complex_number;
        output_stream_reference << ", Imaginary_Component=" << current_complex_number_object.imaginary_part_of_complex_number;
        
        if (current_complex_number_object.imaginary_part_of_complex_number >= 0) {
            output_stream_reference << ", Standard_Form=" << current_complex_number_object.real_part_of_complex_number << " + " << current_complex_number_object.imaginary_part_of_complex_number << "i";
        } else {
            output_stream_reference << ", Standard_Form=" << current_complex_number_object.real_part_of_complex_number << " - " << -current_complex_number_object.imaginary_part_of_complex_number << "i";
        }
        output_stream_reference << "]";
        return output_stream_reference;
    }
};

int main() {
    ComplexNumber_With_Verbose_Names first_complex_operand(3.0, 4.0);
    ComplexNumber_With_Verbose_Names second_complex_operand(1.5, -2.5);
    ComplexNumber_With_Verbose_Names sum_of_complex_numbers = first_complex_operand + second_complex_operand;

    std::cout << "Details of first complex number: " << first_complex_operand << std::endl;
    std::cout << "Details of second complex number: " << second_complex_operand << std::endl;
    std::cout << "Result of their addition: " << sum_of_complex_numbers << std::endl;

    ComplexNumber_With_Verbose_Names another_first_operand(0.5, 1.0);
    ComplexNumber_With_Verbose_Names another_second_operand(-2.0, 0.0);
    ComplexNumber_With_Verbose_Names another_sum_result = another_first_operand + another_second_operand;
    std::cout << "Another addition result: " << another_sum_result << std::endl;

    return 0;
}