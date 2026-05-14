#include <iostream>
#include <string>
#include <utility> // For std::move

// CPU class without input validation
class CPU {
private:
    std::string manufacturer;
    double clockSpeed; // GHz

public:
    // Constructor allows invalid clockSpeed (e.g., negative, zero)
    CPU(std::string manufacturer, double clockSpeed)
        : manufacturer(std::move(manufacturer)), clockSpeed(clockSpeed) {}

    std::string getManufacturer() const { return manufacturer; }
    double getClockSpeed() const { return clockSpeed; }
};

// Laptop class without input validation for model name
class Laptop {
private:
    std::string modelName;
    CPU cpu; // Composition

public:
    // Constructor allows empty modelName and passes potentially invalid CPU data
    Laptop(std::string modelName, std::string cpuManufacturer, double cpuClockSpeed)
        : modelName(std::move(modelName)),
          cpu(cpuManufacturer, cpuClockSpeed) {} // CPU constructor handles its own (lack of) validation

    std::string getModelName() const { return modelName; }
    std::string getCpuManufacturer() const { return cpu.getManufacturer(); }
    double getCpuClockSpeed() const { return cpu.getClockSpeed(); }

    void displayDetails() const {
        std::cout << "Laptop Model: " << modelName << std::endl;
        std::cout << "  CPU Manufacturer: " << cpu.getManufacturer() << std::endl;
        std::cout << "  CPU Clock Speed: " << cpu.getClockSpeed() << " GHz" << std::endl;
    }
};

int main() {
    // Demonstrating robustness issues:
    // 1. Laptop with an invalid (negative) CPU clock speed
    Laptop laptop1("XPS 15", "Intel", -2.3); 
    laptop1.displayDetails();

    // 2. Laptop with an empty model name
    Laptop laptop2("", "AMD", 3.8); 
    laptop2.displayDetails();

    // 3. Laptop with a zero clock speed (often undesirable)
    Laptop laptop3("Gaming Beast", "Nvidia", 0.0);
    laptop3.displayDetails();

    return 0;
}