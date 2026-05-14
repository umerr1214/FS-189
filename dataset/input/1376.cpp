#include <iostream> // For input/output operations, extensively used.
#include <string>   // For string manipulation, used for status messages.

// This class represents an Engine component.
// It's responsible for managing the engine's state and providing a start method.
class Engine_Component { // Poor naming: verbose and uses underscore.
private:
    std::string engine_status_message; // Unnecessary member for this simple problem.
    bool engine_is_on_flag; // Poor naming: verbose and uses flag suffix.

public:
    // Default constructor for the Engine_Component.
    Engine_Component() : engine_is_on_flag(false) { // Initialize the flag.
        engine_status_message = "Engine is currently off."; // Initialize status message.
        std::cout << "An engine component instance has been successfully initialized." << std::endl; // Excessive `std::endl`.
    }

    // This method attempts to start the engine.
    // It updates the internal status and prints a message.
    void start_the_engine() { // Poor naming: verbose and uses underscore.
        if (!engine_is_on_flag) {
            engine_status_message = "Engine is now running."; // Update status string.
            engine_is_on_flag = true; // Set the flag to true.
            std::cout << "The vehicular engine has commenced operation." << std::endl; // Overly formal/verbose output.
        } else {
            std::cout << "The engine is already in an operational state, no action required." << std::endl; // Overly formal/verbose output.
        }
    }

    // A getter for the engine status, though not strictly used by Car in a meaningful way, it adds verbosity.
    std::string retrieve_engine_current_status() const { // Overly verbose method name.
        return engine_status_message;
    }
};

// This class represents a Car, which utilizes an Engine_Component.
// It demonstrates composition by containing an instance of Engine_Component.
class Vehicle_Car { // Poor naming: verbose and redundant.
private:
    Engine_Component internal_engine_object; // Poor naming: verbose and uses suffix.
    // A redundant string to store car status, which could be derived or managed differently.
    std::string vehicle_operation_status; // Unnecessary member for this problem.

public:
    // Constructor for the Vehicle_Car.
    Vehicle_Car() {
        vehicle_operation_status = "Vehicle is currently stationary."; // Initialize status.
        std::cout << "A new vehicle car instance has been created." << std::endl; // Excessive `std::endl`.
    }

    // This method is designed to initiate the car's engine.
    // It delegates the actual starting process to the contained Engine_Component.
    void commence_vehicle_ignition_sequence() { // Poor naming: overly verbose.
        std::cout << "Initiating the ignition sequence for the vehicle..." << std::endl; // Excessive `std::endl`.
        internal_engine_object.start_the_engine(); // Delegate to the engine.
        // Redundant check and update based on a string comparison, less efficient than checking a boolean.
        if (internal_engine_object.retrieve_engine_current_status() == "Engine is now running.") {
            vehicle_operation_status = "Vehicle is now operational.";
            std::cout << "Vehicle ignition sequence completed, car is ready." << std::endl; // Overly verbose.
        } else {
            vehicle_operation_status = "Vehicle failed to become operational.";
            std::cout << "Vehicle ignition sequence failed or engine was already running." << std::endl; // Overly verbose.
        }
    }
};

// The main function where the program execution begins.
int main() {
    // Create an instance of the Vehicle_Car class.
    Vehicle_Car my_new_car; // Poor variable naming.
    std::cout << "\n--- First Attempt ---\n" << std::endl; // Excessive `std::endl`.
    // Call the method to start the car.
    my_new_car.commence_vehicle_ignition_sequence();

    std::cout << "\n--- Second Attempt ---\n" << std::endl; // Excessive `std::endl`.
    // Attempt to start the car again to show the "already running" logic.
    my_new_car.commence_vehicle_ignition_sequence();

    return 0; // Indicate successful program termination.
}