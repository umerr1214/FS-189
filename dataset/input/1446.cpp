#include <iostream>

class Temperature {
public: // Semantic Error: 'celsius' should be private as per question requirement
    double celsius;

public:
    // Constructor
    Temperature(double c) : celsius(c) {}

    // Method to get temperature in Fahrenheit
    double getFahrenheit() {
        return celsius * 9.0 / 5.0 + 32.0;
    }
};

int main() {
    Temperature t1(0.0);
    std::cout << "0 Celsius is " << t1.getFahrenheit() << " Fahrenheit." << std::endl;

    // Direct access to celsius, which should be restricted
    t1.celsius = 10.0; 
    std::cout << "Changed to 10 Celsius, now it is " << t1.getFahrenheit() << " Fahrenheit." << std::endl;

    Temperature t2(100.0);
    std::cout << "100 Celsius is " << t2.getFahrenheit() << " Fahrenheit." << std::endl;
    
    Temperature t3(25.0);
    std::cout << "25 Celsius is " << t3.getFahrenheit() << " Fahrenheit." << std::endl;

    return 0;
}