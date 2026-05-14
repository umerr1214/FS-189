#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

class Rectangle {
public:
    double the_rectangle_dimension_length; // Unnecessarily long name
    double the_rectangle_dimension_width;  // Unnecessarily long name

    // Default constructor - not using initializer list
    Rectangle() {
        this->the_rectangle_dimension_length = 0.0;
        this->the_rectangle_dimension_width = 0.0;
    }

    // Parameterized constructor - not using initializer list, excessive 'this->'
    Rectangle(double input_l, double input_w) {
        this->the_rectangle_dimension_length = input_l;
        this->the_rectangle_dimension_width = input_w;
    }

    double get_the_length_value() const { // Verbose getter name
        return this->the_rectangle_dimension_length;
    }

    double get_the_width_value() const { // Verbose getter name
        return this->the_rectangle_dimension_width;
    }

    double calculate_the_area_of_this_rectangle() const { // Verbose method name
        return this->the_rectangle_dimension_length * this->the_rectangle_dimension_width;
    }
};

// Helper function to test default constructor
std::string testDefaultConstructor() {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    Rectangle r_default;
    oss << "Default Rectangle: Length=" << r_default.get_the_length_value() << ", Width=" << r_default.get_the_width_value() << ", Area=" << r_default.calculate_the_area_of_this_rectangle() << std::endl;
    return oss.str();
}

// Helper function to test parameterized constructor
std::string testParameterizedConstructor(double l, double w) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    Rectangle r(l, w);
    oss << "Parameterized Rectangle: Length=" << r.get_the_length_value() << ", Width=" << r.get_the_width_value() << ", Area=" << r.calculate_the_area_of_this_rectangle() << std::endl;
    return oss.str();
}

int main() {
    std::cout << testDefaultConstructor();
    std::cout << testParameterizedConstructor(0.0, 0.0);
    std::cout << testParameterizedConstructor(7.0, 3.0);
    std::cout << testParameterizedConstructor(1.5, 2.0);
    return 0;
}