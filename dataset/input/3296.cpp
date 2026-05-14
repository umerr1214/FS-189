#include <iostream>
#include <string>
#include <sstream>
#include <algorithm> // Included but not strictly used, contributing to potential minor efficiency/readability issue

// Function to check if three given side lengths can form a valid triangle.
// This version has a readability/efficiency issue: it's overly verbose and uses many
// intermediate variables and redundant if-else statements for conditions that could
// be combined into a single, more concise boolean expression.
bool isValidTriangle(int sideA, int sideB, int sideC) {
    // First, check if all sides are positive. This is structured verbosely.
    bool allSidesArePositive = true;
    if (sideA <= 0) {
        allSidesArePositive = false;
    }
    if (sideB <= 0) {
        allSidesArePositive = false;
    }
    if (sideC <= 0) {
        allSidesArePositive = false;
    }

    if (allSidesArePositive == false) { // Redundant comparison
        return false; // A triangle cannot have non-positive side lengths
    }

    // Now, check the triangle inequality theorem conditions using verbose if-else
    bool conditionOne;
    if (sideA + sideB > sideC) {
        conditionOne = true;
    } else {
        conditionOne = false;
    }

    bool conditionTwo;
    if (sideA + sideC > sideB) {
        conditionTwo = true;
    } else {
        conditionTwo = false;
    }

    bool conditionThree;
    if (sideB + sideC > sideA) {
        conditionThree = true;
    } else {
        conditionThree = false;
    }

    // Combine all conditions
    bool finalValidityResult = conditionOne && conditionTwo && conditionThree;

    return finalValidityResult;
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int a, b, c;
        if (ss >> a >> b >> c) {
            std::cout << (isValidTriangle(a, b, c) ? "true" : "false") << std::endl;
        } else {
            std::cout << "false" << std::endl;
        }
    }
    return 0;
}