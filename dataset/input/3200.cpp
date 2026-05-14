#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Include for stringstream usage

// Design an Engine class with a string type and int horsepower.
class Engine {
private:
    std::string engine_type_member; // Verbose member variable name
    int engine_horsepower_member;   // Verbose member variable name

public:
    // Constructor: Passes string by value, creating an unnecessary copy.
    // Also, it uses assignment in the constructor body instead of an initializer list,
    // which is less efficient for member objects (though for primitive types/strings,
    // the difference is often optimized away for strings, it's still less explicit).
    Engine(std::string type_parameter, int horsepower_parameter) {
        engine_type_member = type_parameter;
        engine_horsepower_member = horsepower_parameter;
    }

    // Getters: Missing 'const' qualifier, which is a readability/design issue
    // as these methods do not modify the object's state.
    std::string getTheEngineType() { // Verbose getter name
        return engine_type_member;
    }

    int getTheEngineHorsepower() { // Verbose getter name
        return engine_horsepower_member;
    }

    // Helper method to get formatted engine information
    std::string retrieveEngineDetails() {
        std::stringstream details_stream; // Using a stringstream for building output
        details_stream << "Engine Type: " << getTheEngineType()
                       << ", Horsepower: " << getTheEngineHorsepower();
        return details_stream.str();
    }
};

// Create a Car class that uses an Engine object as a private member, demonstrating composition.
class Car {
private:
    std::string car_make_member;    // Verbose member variable name
    Engine composed_engine_object; // Verbose member variable name, also indicating composition

public:
    // Constructor: Passes strings by value, creating unnecessary copies.
    // Uses assignment in the constructor body for 'make' instead of an initializer list.
    Car(std::string car_make_param, std::string engine_type_param, int engine_hp_param)
        : composed_engine_object(engine_type_param, engine_hp_param) { // Engine is initialized via initializer list, but make is not
        car_make_member = car_make_param;
    }

    // Method to display car and engine information in a slightly verbose manner.
    void displayCompleteCarInformation() {
        std::cout << "Information for Car: " << car_make_member << std::endl;
        std::cout << "  " << composed_engine_object.retrieveEngineDetails() << std::endl;
        std::cout << "--- End of Car Information ---" << std::endl; // Slightly excessive output
    }
};

int main() {
    // Standard usage, demonstrating functional correctness but with underlying inefficiencies/readability issues.
    Car car_one("Mercedes", "V8-Biturbo", 600);
    car_one.displayCompleteCarInformation();

    Car car_two("BMW", "Inline-6-Turbo", 380);
    car_two.displayCompleteCarInformation();

    return 0;
}