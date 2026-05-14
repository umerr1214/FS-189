#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision
#include <algorithm> // For std::max

class Rectangle {
private:
    double width;
    double height;

public:
    // Constructor to initialize dimensions (good practice)
    Rectangle() : width(0.0), height(0.0) {}

    // setDimensions method returns a reference to the current object.
    // Includes robustness by ensuring dimensions are non-negative.
    Rectangle& setDimensions(double w, double h) {
        // Ensure dimensions are non-negative. Clamping to 0 gracefully handles invalid inputs.
        this->width = std::max(0.0, w);
        this->height = std::max(0.0, h);
        return *this;
    }

    // calculateArea method is efficient, clear, and const-correct
    double calculateArea() const {
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