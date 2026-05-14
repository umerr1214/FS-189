#include <iostream>
#include <vector>
#include <cmath> // For std::abs
#include <iomanip> // For std::fixed, std::setprecision

// Using namespace std; is generally considered bad practice in headers or large projects
// but included here to demonstrate a minor readability issue.
using namespace std;

class Temperature {
private:
    double celsiusTemperatureValue; // Slightly verbose variable name

public:
    // Constructor
    Temperature(double initialCelsius) : celsiusTemperatureValue(initialCelsius) {} // Verbose parameter name

    // Public method to get Fahrenheit temperature
    // Missing 'const' qualifier, which is an efficiency/design oversight
    double getFahrenheit() {
        // Calculating conversion factors within the method every time it's called
        // instead of using a constant or direct literal, a minor efficiency/readability issue.
        double conversionFactor = 9.0 / 5.0;
        double offsetValue = 32.0;
        double fahrenheitResult = celsiusTemperatureValue * conversionFactor + offsetValue;
        return fahrenheitResult;
    }
};

struct TestCase {
    double input_celsius;
    double expected_fahrenheit;
};

int main() {
    vector<TestCase> test_data_points = { // Inconsistent naming with typical 'test_cases'
        {0.0, 32.0},
        {20.0, 68.0},
        {-10.0, 14.0},
        {100.0, 212.0},
        {37.0, 98.6}
    };

    cout << fixed << setprecision(1); // Use std::fixed and std::setprecision

    int successful_tests_counter = 0; // Verbose variable name
    for (size_t i = 0; i < test_data_points.size(); ++i) {
        Temperature temp_object(test_data_points[i].input_celsius); // Verbose object name
        double actual_fahrenheit_output = temp_object.getFahrenheit(); // Verbose variable name
        
        if (abs(actual_fahrenheit_output - test_data_points[i].expected_fahrenheit) < 0.001) {
            cout << "Test Case " << i + 1 << " Status: Passed" << endl; // Excessive use of endl
            cout << "  Input C: " << test_data_points[i].input_celsius << endl;
            cout << "  Actual F: " << actual_fahrenheit_output << endl;
            cout << "  Expected F: " << test_data_points[i].expected_fahrenheit << endl << endl;
            successful_tests_counter++;
        } else {
            cout << "Test Case " << i + 1 << " Status: FAILED" << endl;
            cout << "  Input C: " << test_data_points[i].input_celsius << endl;
            cout << "  Actual F: " << actual_fahrenheit_output << endl;
            cout << "  Expected F: " << test_data_points[i].expected_fahrenheit << endl << endl;
        }
    }

    cout << "--- Final Test Report ---" << endl;
    cout << "Total Cases Executed: " << test_data_points.size() << endl;
    cout << "Successful Completions: " << successful_tests_counter << endl;
    cout << "Failed Completions: " << test_data_points.size() - successful_tests_counter << endl;

    return (successful_tests_counter == test_data_points.size()) ? 0 : 1;
}