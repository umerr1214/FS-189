#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

class Rectangle {
private:
    double width;
    double height;

public:
    // Constructor that does not validate input, allowing negative dimensions.
    // This can lead to non-physical negative area calculations.
    Rectangle(double w, double h) : width(w), height(h) {}

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