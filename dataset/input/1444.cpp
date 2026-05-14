#include <iostream>

class Temperature {
private:
    double celsius;

public:
    // Constructor
    Temperature(double c) : celsius(c) {}

    // Method to get temperature in Fahrenheit
    double getFahrenheit() {
        return celsius * 9.0 / 5.0 + 32.0;
    }
} // Missing semicolon here after class definition

int main() {
    Temperature t1(0.0);
    std::cout << "0 Celsius is " << t1.getFahrenheit() << " Fahrenheit." << std::endl;

    Temperature t2(100.0);
    std::cout << "100 Celsius is " << t2.getFahrenheit() << " Fahrenheit." << std::endl;
    
    Temperature t3(25.0);
    std::cout << "25 Celsius is " << t3.getFahrenheit() << " Fahrenheit." << std::endl;

    return 0;
}