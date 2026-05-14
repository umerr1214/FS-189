#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision
#include <algorithm> // For std::max

class Rectangle {
private:
    double width;
    double height;

public:
    // Constructor with input validation to ensure non-negative dimensions
    Rectangle(double w, double h) : 
        width(std::max(0.0, w)),  // Ensure width is not negative
        height(std::max(0.0, h)) // Ensure height is not negative
    {}

    // Friend function declaration
    friend double calculateArea(const Rectangle& rect);
};

// Friend function definition, directly accessing private members
double calculateArea(const Rectangle& rect) {
    return rect.width * rect.height;
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        double w, h;
        if (!(ss >> w >> h)) {
            std::cerr << "Invalid input format. Please enter two doubles." << std::endl;
            continue;
        }
        
        Rectangle rect(w, h);
        double area = calculateArea(rect);
        
        std::cout << std::fixed << std::setprecision(2) << area << std::endl;
    }
    return 0;
}