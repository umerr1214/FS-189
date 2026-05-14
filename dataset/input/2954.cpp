#include <iostream>
#include <string>
#include <sstream>

class Box {
private:
    double m_box_object_length_dimension; // Overly verbose variable name
    double m_box_object_width_dimension;  // Overly verbose variable name

public:
    // Constructor with a default argument for width.
    // Readability/Efficiency issue: Uses 0.0 as a sentinel for default width,
    // which is problematic if a width of 0.0 is actually intended.
    // Also, uses 'this->' redundantly.
    Box(double input_length_value, double input_width_value = 0.0) {
        this->m_box_object_length_dimension = input_length_value; // Redundant 'this->'
        if (input_width_value == 0.0) { // Sentinel check, assuming 0.0 means default
            this->m_box_object_width_dimension = input_length_value;
        } else {
            this->m_box_object_width_dimension = input_width_value;
        }
        std::cout << "A new Box object has been created with initial dimensions." << std::endl; // Excessive output in constructor
    }

    // Readability issue: Overly verbose method name and redundant 'this->'
    double get_box_object_area_calculation_result() const {
        return this->m_box_object_length_dimension * this->m_box_object_width_dimension;
    }

    double get_box_object_length_dimension_value() const { // Overly verbose method name
        return this->m_box_object_length_dimension;
    }

    double get_box_object_width_dimension_value() const { // Overly verbose method name
        return this->m_box_object_width_dimension;
    }
};

int main() {
    std::cout << "--- Starting Box Demonstrations ---" << std::endl << std::endl; // Excessive std::endl

    Box first_example_box(10.0, 5.0); // Create a box with explicit length and width
    std::cout << "First Box Details:" << std::endl;
    std::cout << "  Length: " << first_example_box.get_box_object_length_dimension_value() << std::endl; // Excessive std::endl
    std::cout << "  Width: " << first_example_box.get_box_object_width_dimension_value() << std::endl;   // Excessive std::endl
    std::cout << "  Calculated Area: " << first_example_box.get_box_object_area_calculation_result() << std::endl << std::endl;

    Box second_example_box(7.0); // Create a box with only length, triggering default width
    std::cout << "Second Box Details:" << std::endl;
    std::cout << "  Length: " << second_example_box.get_box_object_length_dimension_value() << std::endl;
    std::cout << "  Width (defaulted): " << second_example_box.get_box_object_width_dimension_value() << std::endl;
    std::cout << "  Calculated Area: " << second_example_box.get_box_object_area_calculation_result() << std::endl << std::endl;

    Box third_example_box(12.5, 2.0); // Another explicit box
    std::cout << "Third Box Details:" << std::endl;
    std::cout << "  Length: " << third_example_box.get_box_object_length_dimension_value() << std::endl;
    std::cout << "  Width: " << third_example_box.get_box_object_width_dimension_value() << std::endl;
    std::cout << "  Calculated Area: " << third_example_box.get_box_object_area_calculation_result() << std::endl << std::endl;

    std::cout << "--- Box Demonstrations Complete ---" << std::endl; // Excessive std::endl

    return 0;
}