#include <iostream>
#include <string>
#include <cstring> // For strcpy, strlen

// ERROR TYPE: Robustness Issue
// Issues:
// 1. Missing virtual destructor in base classes (Electronics, Smartphone).
//    Deleting a derived object via a base pointer will lead to undefined behavior/memory leaks
//    because only the base class destructor will be called.
// 2. Using raw char* for string attributes without implementing the Rule of Three/Five
//    (copy constructor, copy assignment operator, move constructor, move assignment operator).
//    This leads to shallow copies if objects are copied, potentially causing double-frees or memory corruption.
//    While not explicitly demonstrated with a copy in main here to avoid crashes, the design is flawed.

class Electronics {
public:
    double powerConsumption;
    char* manufacturer; // Using raw char*

    Electronics(double pc, const char* m) : powerConsumption(pc) {
        if (m) {
            manufacturer = new char[strlen(m) + 1];
            strcpy(manufacturer, m);
        } else {
            manufacturer = nullptr;
        }
    }

    // Missing virtual destructor: This is a critical robustness flaw in an inheritance hierarchy.
    ~Electronics() {
        delete[] manufacturer;
    }

    void displayElectronicsDetails() {
        std::cout << "Electronics Details:" << std::endl;
        std::cout << "  Power Consumption: " << powerConsumption << "W" << std::endl;
        std::cout << "  Manufacturer: " << (manufacturer ? manufacturer : "N/A") << std::endl;
    }
};

class Smartphone : public Electronics {
public:
    char* operatingSystem; // Using raw char*

    Smartphone(double pc, const char* m, const char* os)
        : Electronics(pc, m) {
        if (os) {
            operatingSystem = new char[strlen(os) + 1];
            strcpy(operatingSystem, os);
        } else {
            operatingSystem = nullptr;
        }
    }

    // Missing virtual destructor
    ~Smartphone() {
        delete[] operatingSystem;
    }

    void displaySmartphoneDetails() {
        Electronics::displayElectronicsDetails();
        std::cout << "Smartphone Details:" << std::endl;
        std::cout << "  Operating System: " << (operatingSystem ? operatingSystem : "N/A") << std::endl;
    }
};

class PremiumSmartphone : public Smartphone {
public:
    int cameraMP;

    PremiumSmartphone(double pc, const char* m, const char* os, int cmp)
        : Smartphone(pc, m, os), cameraMP(cmp) {}

    // Missing virtual destructor (though no direct dynamic members here, the chain is broken)
    ~PremiumSmartphone() {
        // No dynamic memory directly owned by PremiumSmartphone, but still part of the flawed hierarchy.
    }

    void displayPremiumSmartphoneDetails() {
        Smartphone::displaySmartphoneDetails();
        std::cout << "Premium Smartphone Details:" << std::endl;
        std::cout << "  Camera Megapixels: " << cameraMP << "MP" << std::endl;
    }
};

int main() {
    // Demonstrate basic functionality
    PremiumSmartphone myPhone(10.5, "ElectroCorp", "Android 12", 64);
    std::cout << "--- First Premium Smartphone Details ---" << std::endl;
    myPhone.displayPremiumSmartphoneDetails();
    std::cout << std::endl;

    // Demonstrate the robustness issue: deleting derived object via base pointer
    // Due to missing virtual destructor in Electronics and Smartphone,
    // only Electronics::~Electronics() will be called, leading to memory leaks
    // for 'operatingSystem' and 'manufacturer' allocated by Smartphone and Electronics parts.
    std::cout << "--- Demonstrating polymorphic deletion with non-virtual destructor ---" << std::endl;
    Electronics* polyPhone = new PremiumSmartphone(12.0, "TechGear", "iOS 15", 108);
    // Only base details are accessible via base pointer without virtual methods
    polyPhone->displayElectronicsDetails(); 
    delete polyPhone; // MEMORY LEAK for Smartphone and PremiumSmartphone parts

    std::cout << "\nProgram finished. A memory profiler would indicate leaks due to design flaws." << std::endl;

    return 0;
}