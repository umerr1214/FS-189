#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

class Rectangle {
public:
    double width;
    double height;

    // setDimensions method returns a reference to the current object
    Rectangle& setDimensions(double w, double h) {
        // Robustness issue: No validation for w or h.
        // Negative values will be accepted, leading to incorrect physical interpretations
        // and potentially negative area.
        this->width = w;
        this->height = h;
        return *this;
    }

    double calculateArea() {
        return width * height;
    }
};

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        double w, h;
        char comma;
        if (!(ss >> w >> comma >> h)) {
            std::cout << "ERROR: Invalid input format." << std::endl;
            continue;
        }

        Rectangle rect;
        // Demonstrate method chaining as required by the question
        double area = rect.setDimensions(w, h).calculateArea();
        
        std::cout << std::fixed << std::setprecision(2) << area << std::endl;
    }
    return 0;
}