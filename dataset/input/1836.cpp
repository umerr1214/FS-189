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
        : manufacturer(manufacturer), clockSpeed(clockSpeed) {
        std::cout << "CPU created: " << manufacturer << std::endl;
    }

    // Destructor to observe lifecycle
    ~CPU() {
        std::cout << "CPU destroyed: " << manufacturer << std::endl;
    }

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
    // SEMANTIC ERROR: Instead of composing a CPU object directly (value semantics),
    // it aggregates a pointer to an externally created CPU object.
    // This violates the 'composition' requirement where the Laptop should own
    // and manage the lifecycle of its CPU member.
    CPU* cpuPtr; // Using a pointer instead of a direct object member

public:
    // Constructor takes a pointer to an existing CPU object
    Laptop(const std::string& modelName, CPU* externalCpu)
        : modelName(modelName), cpuPtr(externalCpu) {
        if (!cpuPtr) { // Basic check for null pointer
            std::cerr << "Warning: Laptop created with null CPU pointer!" << std::endl;
        }
    }

    // Destructor: No 'delete cpuPtr;' here because Laptop does not own the CPU object.
    // This highlights the semantic deviation from composition, where ownership is implied.
    ~Laptop() {
        std::cout << "Laptop destroyed: " << modelName << std::endl;
    }

    void displayLaptop() const {
        std::cout << "Laptop Model: " << modelName << std::endl;
        if (cpuPtr) {
            cpuPtr->displayCPU();
        } else {
            std::cout << "No CPU assigned." << std::endl;
        }
    }
};

int main() {
    // Create CPU objects externally on the stack
    CPU intelCpu("Intel", 2.3);
    CPU amdCpu("AMD", 3.8);

    std::cout << "\n--- Creating Laptops ---" << std::endl;
    // Laptop aggregates the CPU objects by storing their addresses
    Laptop myLaptop("XPS 15", &intelCpu);
    Laptop gamingLaptop("ROG Strix", &amdCpu);

    std::cout << "\n--- Displaying Laptops ---" << std::endl;
    myLaptop.displayLaptop();
    gamingLaptop.displayLaptop();

    std::cout << "\n--- Laptops and CPUs will be destroyed ---" << std::endl;
    // The CPU objects (intelCpu, amdCpu) will be destroyed when main ends,
    // *after* the Laptop objects are destroyed, demonstrating that Laptop does not own them.
    return 0;
}