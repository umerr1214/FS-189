#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include <iomanip> // For std::fixed and std::setprecision

class Calculator {
public:
    // Overloaded add method for two integers (inefficient and less readable)
    int add(int valA, int valB) {
        std::vector<int> numbers_to_sum; // Unnecessary vector allocation
        numbers_to_sum.push_back(valA);
        numbers_to_sum.push_back(valB);
        // Using accumulate for just two numbers is less efficient than direct addition
        return std::accumulate(numbers_to_sum.begin(), numbers_to_sum.end(), 0);
    }

    // Overloaded add method for two doubles (less readable with variable names and unnecessary intermediate)
    double add(double d1, double d2) {
        double result_of_addition = d1 + d2; // Unnecessary intermediate variable
        return result_of_addition;
    }

    // Overloaded add method for three integers (inefficient and less readable)
    int add(int valA, int valB, int valC) {
        std::vector<int> listOfInts; // Cryptic variable name
        listOfInts.push_back(valA);
        listOfInts.push_back(valB);
        listOfInts.push_back(valC);
        // Again, accumulate for three numbers is less efficient
        int finalSum = std::accumulate(listOfInts.begin(), listOfInts.end(), 0);
        return finalSum;
    }
};

int main() {
    Calculator myCalc; // Cryptic object name

    std::cout << "Testing Calculator with readability/efficiency issues:\n";
    std::cout << std::fixed << std::setprecision(2); // Set precision for double output

    std::cout << "Result of adding two integers: " << myCalc.add(5, 7) << std::endl;
    std::cout << "Result of adding two doubles: " << myCalc.add(3.14, 2.71) << std::endl;
    std::cout << "Result of adding three integers: " << myCalc.add(10, 20, 30) << std::endl;
    std::cout << "Another double sum: " << myCalc.add(0.1, 0.2) << std::endl;
    std::cout << "Another int sum: " << myCalc.add(-5, 10, -2) << std::endl;

    return 0;
}