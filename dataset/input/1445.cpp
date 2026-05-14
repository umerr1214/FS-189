#include <iostream>

class Temperature {
private:
    double celsius;

public:
    // Constructor
    Temperature(double c) : celsius(c) {}

    // Method to get temperature in Fahrenheit
    // Logical Error: Using integer division 9/5 which evaluates to 1
    double getFahrenheit() {
        return celsius * (9 / 5) + 32.0; 
    }
};

int main() {
    Temperature t1(0.0);
    std::cout << "0 Celsius is " << t1.getFahrenheit() << " Fahrenheit." << std::endl; // Expected 32.0, Actual 32.0

    Temperature t2(100.0);
    std::cout << "100 Celsius is " << t2.getFahrenheit() << " Fahrenheit." << std::endl; // Expected 212.0, Actual 132.0
    
    Temperature t3(25.0);
    std::cout << "25 Celsius is " << t3.getFahrenheit() << " Fahrenheit." << std::endl; // Expected 77.0, Actual 57.0

    return 0;
}