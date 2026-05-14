#include <iostream>
#include <string>
#include <vector> // This header is included but not used, contributing to a readability/efficiency issue.

// Using typedefs for basic types, which can sometimes reduce readability for common types
typedef int EnginePowerValue;
typedef std::string EngineFuelTypeString;
typedef std::string AutomobileMakeString;
typedef std::string AutomobileModelString;

// Class with verbose naming and inefficient practices
class VeryComplexEngineClassDefinition {
private:
    EnginePowerValue m_private_engine_horsepower_value; // Overly verbose member name
    EngineFuelTypeString m_private_engine_fuel_type_string_value; // Overly verbose member name

public:
    // Constructor with verbose parameter names
    VeryComplexEngineClassDefinition(EnginePowerValue initial_horsepower_for_engine, const EngineFuelTypeString& initial_fuel_type_for_engine)
        : m_private_engine_horsepower_value(initial_horsepower_for_engine), m_private_engine_fuel_type_string_value(initial_fuel_type_for_engine) {
        // The constructor is functionally correct but uses verbose naming.
    }

    // Getter method for horsepower, with verbose naming
    EnginePowerValue retrieveTheEngineHorsepowerValue() const {
        return m_private_engine_horsepower_value;
    }

    // Getter method for fuel type, returning std::string by value (inefficient for large strings)
    EngineFuelTypeString obtainTheEngineFuelTypeString() const {
        return m_private_engine_fuel_type_string_value; // Returns by value, causing a copy
    }

    // Method to display information, with verbose output formatting
    void displayCompleteEngineInformation() const {
        std::cout << "Engine Horsepower Information: " << m_private_engine_horsepower_value << " HP" << std::endl;
        std::cout << "Engine Fuel Type Information: " << m_private_engine_fuel_type_string_value << std::endl;
    }
};

// Class with verbose naming and inefficient practices, composing the Engine
class AutomobileVehicleClassStructure {
private:
    AutomobileMakeString m_private_automobile_make_identifier; // Overly verbose member name
    AutomobileModelString m_private_automobile_model_identifier; // Overly verbose member name
    VeryComplexEngineClassDefinition m_composed_engine_object_instance; // Composition with verbose member name

public:
    // Constructor with very long parameter names and initializer list
    AutomobileVehicleClassStructure(
        const AutomobileMakeString& automobile_make_parameter,
        const AutomobileModelString& automobile_model_parameter,
        EnginePowerValue engine_horsepower_parameter,
        const EngineFuelTypeString& engine_fuel_type_parameter
    ) : m_private_automobile_make_identifier(automobile_make_parameter),
        m_private_automobile_model_identifier(automobile_model_parameter),
        m_composed_engine_object_instance(engine_horsepower_parameter, engine_fuel_type_parameter) {
        // The constructor is functionally correct but verbose.
    }

    // Method to present full automobile details, with verbose output
    void presentFullAutomobileDetails() const {
        std::cout << "Automobile Make: " << m_private_automobile_make_identifier << std::endl;
        std::cout << "Automobile Model: " << m_private_automobile_model_identifier << std::endl;
        std::cout << "  Related Engine Information:" << std::endl;
        m_composed_engine_object_instance.displayCompleteEngineInformation(); // Access Engine's method
    }

    // Car method to access engine horsepower, with verbose naming
    EnginePowerValue getTheAssociatedEngineHorsepower() const {
        return m_composed_engine_object_instance.retrieveTheEngineHorsepowerValue();
    }

    // Car method to access engine fuel type, returning std::string by value (inefficient)
    EngineFuelTypeString getTheAssociatedEngineFuelType() const {
        return m_composed_engine_object_instance.obtainTheEngineFuelTypeString();
    }
};

int main() {
    // Creating instances with verbose names
    AutomobileVehicleClassStructure first_car_instance("Honda", "Civic", 158, "Petrol");
    std::cout << "--- First Automobile Vehicle Instance Details ---" << std::endl;
    first_car_instance.presentFullAutomobileDetails();
    std::cout << "Accessed Engine Horsepower: " << first_car_instance.getTheAssociatedEngineHorsepower() << std::endl;
    std::cout << "Accessed Engine Fuel Type: " << first_car_instance.getTheAssociatedEngineFuelType() << std::endl;
    std::cout << std::endl;

    AutomobileVehicleClassStructure second_car_instance("Tesla", "Model 3", 450, "Electric");
    std::cout << "--- Second Automobile Vehicle Instance Details ---" << std::endl;
    second_car_instance.presentFullAutomobileDetails();
    std::cout << "Accessed Engine Horsepower: " << second_car_instance.getTheAssociatedEngineHorsepower() << std::endl;
    std::cout << "Accessed Engine Fuel Type: " << second_car_instance.getTheAssociatedEngineFuelType() << std::endl;
    std::cout << std::endl;

    return 0;
}