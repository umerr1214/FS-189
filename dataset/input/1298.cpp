#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

class Rectangle {
private:
    double _w; // Cryptic and non-standard name for width
    double _h; // Cryptic and non-standard name for height
public:
    Rectangle& setDimensions(double w,double h) { // Inconsistent spacing after comma
        this->_w = w;
        this->_h = h;
        return *this;
    }

    double calculateArea() {
        // Minor efficiency/readability issue: uses an unnecessary temporary variable
        double area_val = _w;
        area_val *= _h;
        return area_val;
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