#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

// Syntax error: 'clas' instead of 'class'
clas Temperature {
private:
    double celsius;

public:
    void setCelsius(double c) {
        celsius = c;
    }

    double getCelsius() {
        return celsius;
    }

    void setFahrenheit(double f) {
        celsius = (f - 32.0) * 5.0 / 9.0;
    }

    double getFahrenheit() {
        return celsius * 9.0 / 5.0 + 32.0;
    }
};

int main() {
    // This code will not compile due to the syntax error above.
    // If it were fixed, it would demonstrate the Temperature class functionality.
    // Temperature temp;
    // std::cout << std::fixed << std::setprecision(1);

    // temp.setCelsius(25.0);
    // std::cout << "25.0 C is " << temp.getFahrenheit() << " F\n";

    // temp.setFahrenheit(68.0);
    // std::cout << "68.0 F is " << temp.getCelsius() << " C\n";

    return 0;
}