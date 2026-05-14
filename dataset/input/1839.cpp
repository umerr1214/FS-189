#include <iostream>
#include <string>
#include <utility>      // For std::move
#include <stdexcept>    // For std::invalid_argument

// CPU class with proper encapsulation, validation, and efficiency
class CPU {
private:
    std::string manufacturer;
    double clockSpeed; // GHz

public:
    // Constructor uses initializer list and performs input validation
    CPU(std::string manufacturer, double clockSpeed)
        : manufacturer(std::move(manufacturer)), clockSpeed(clockSpeed)
    {
        if (this->manufacturer.empty()) {
            throw std::invalid_argument("CPU manufacturer cannot be empty.");
        }
        if (this->clockSpeed <= 0) {
            throw std::invalid_argument("CPU clock speed must be positive.");
        }
    }

    // Getters are const-correct
    std::string getManufacturer() const { return manufacturer; }
    double getClockSpeed() const { return clockSpeed; }
};

// Laptop class demonstrating composition, validation, and efficiency
class Laptop {
private:
    std::string modelName;
    CPU cpu; // Composition: CPU object is a member

public:
    // Constructor uses initializer lists for all members and performs input validation.
    // CPU object is directly constructed using its constructor.
    Laptop(std::string modelName, std::string cpuManufacturer, double cpuClockSpeed)
        : modelName(std::move(modelName)),
          cpu(std::move(cpuManufacturer), cpuClockSpeed) // Efficiently construct CPU member
    {
        if (this->modelName.empty()) {
            throw std::invalid_argument("Laptop model name cannot be empty.");
        }
    }

    // Getters are const-correct
    std::string getModelName() const { return modelName; }
    // Delegating getters for CPU attributes to maintain encapsulation
    std::string getCpuManufacturer() const { return cpu.getManufacturer(); }
    double getCpuClockSpeed() const { return cpu.getClockSpeed(); }

    // Display method uses '\n' for potentially better performance than std::endl
    void displayDetails() const {
        std::cout << "Laptop Model: " << modelName << '\n';
        std::cout << "  CPU Manufacturer: " << cpu.getManufacturer() << '\n';
        std::cout << "  CPU Clock Speed: " << cpu.getClockSpeed() << " GHz" << '\n';
    }
};

int main() {
    try {
        Laptop laptop1("XPS 15", "Intel", 2.3);
        laptop1.displayDetails();

        Laptop laptop2("MacBook Pro", "Apple", 3.2);
        laptop2.displayDetails();

        // Example of how validation would prevent invalid objects (commented out for successful run)
        // Laptop invalidLaptop1("", "Bad CPU", 1.0); // Throws std::invalid_argument
        // Laptop invalidLaptop2("Good Laptop", "Bad CPU", -1.0); // Throws std::invalid_argument

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1; // Indicate error
    }

    return 0;
}