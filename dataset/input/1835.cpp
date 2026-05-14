#include <iostream>
#include <string>
#include <iomanip> // For std::setprecision

// CPU class
class CPU {
private:
    std::string manufacturer;
    double clockSpeed; // GHz

public:
    // Constructor
    CPU(const std::string& manufacturer, double clockSpeed)
        : manufacturer(manufacturer), clockSpeed(clockSpeed) {}

    // Default constructor for logical error case to compile
    CPU() : manufacturer("Generic"), clockSpeed(1.0) {}

    // Getters
    std::string getManufacturer() const {
        return manufacturer;
    }

    double getClockSpeed() const {
        return clockSpeed;
    }

    void displayCPU() const {
        std::cout << "CPU Manufacturer: " << manufacturer
                  << ", Clock Speed: " << std::fixed << std::setprecision(2) << clockSpeed << " GHz" << std::endl;
    }
};

// Laptop class
class Laptop {
private:
    std::string modelName;
    // CPU object as a member (composition)
    CPU cpu;

public:
    // LOGICAL ERROR: The CPU member is always initialized with default values,
    // ignoring the parameters passed to the Laptop constructor for CPU.
    Laptop(const std::string& modelName, const std::string& cpuManufacturer, double cpuClockSpeed)
        : modelName(modelName), cpu() {} // Calls default CPU constructor, ignoring cpuManufacturer, cpuClockSpeed

    // Method to display Laptop details
    void displayLaptop() const {
        std::cout << "Laptop Model: " << modelName << std::endl;
        cpu.displayCPU();
    }
};

int main() {
    // Example usage
    std::cout << "--- My Laptop ---" << std::endl;
    Laptop myLaptop("XPS 15", "Intel", 2.3);
    myLaptop.displayLaptop();

    std::cout << "\n--- Gaming Laptop ---" << std::endl;
    Laptop gamingLaptop("ROG Strix", "AMD", 3.8);
    gamingLaptop.displayLaptop();

    return 0;
}