#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision
#include <algorithm> // For std::max

// Using a less descriptive typedef for double
typedef double DblDim; // A bit vague

class Rectangle {
private:
    DblDim _wVal; // Non-descriptive member name
    DblDim _hVal; // Non-descriptive member name

public:
    // Constructor with non-descriptive parameter names
    Rectangle(DblDim x, DblDim y) : _wVal(x), _hVal(y) {
        // Simple validation to prevent negative dimensions, but naming remains poor
        if (x < 0) _wVal = 0;
        if (y < 0) _hVal = 0;
    }

    // Friend function declaration - name is correct as per prompt
    friend DblDim calculateArea(const Rectangle& rObj); // 'rObj' is a bit verbose for a parameter
};

// Friend function definition
DblDim calculateArea(const Rectangle& rObj) { // Using 'rObj' for Rectangle object
    DblDim tempResult = rObj._wVal * rObj._hVal; // Unnecessary intermediate variable
    return tempResult;
}

int main() {
    std::string inputLine; // Vague variable name
    while (std::getline(std::cin, inputLine)) {
        std::stringstream sStream(inputLine); // Vague variable name
        DblDim iW, iH; // Very short, non-descriptive input variable names
        if (!(sStream >> iW >> iH)) {
            std::cerr << "Input parsing failed. Expected two numbers." << std::endl;
            continue;
        }
        
        Rectangle aRect(iW, iH); // Non-descriptive object name
        DblDim finalArea = calculateArea(aRect); // Unnecessary intermediate variable for result
        
        std::cout << std::fixed << std::setprecision(2) << finalArea << std::endl;
    }
    return 0;
}