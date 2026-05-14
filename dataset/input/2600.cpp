#include <iostream>
#include <string>

// ERROR TYPE: Readability / Efficiency Issue
// Issues:
// 1. Excessive use of std::endl, which flushes the buffer on each call, leading to inefficiency.
//    Should use '\n' instead for better performance.
// 2. Not using constructor initializer lists for all members where possible.
//    Members are assigned in the constructor body, which can be less efficient (default construct then assign).
// 3. Lack of const correctness for display methods. These methods do not modify the object's state
//    and should be marked const.
// 4. Inconsistent formatting (e.g., extra blank lines, inconsistent indentation).
// 5. Verbose output statements, each with its own `std::cout << ... << std::endl;`
//    Could be combined or formatted more compactly.

class Electronics {
public: // Attributes are public, poor encapsulation
    double powerConsumption;
    std::string manufacturer;

    Electronics(double pc, std::string m) { // No initializer list
        powerConsumption = pc;
        manufacturer = m;
    }

    // Non-virtual destructor, though less critical without raw pointers or polymorphic deletion in main
    ~Electronics() {
    }


    void displayElectronicsDetails() { // Missing const-correctness
        std::cout << "Electronics Details:" << std::endl;

        std::cout << "  Power Consumption: " << powerConsumption << "W" << std::endl;

        std::cout << "  Manufacturer: " << manufacturer << std::endl;
    }
};

class Smartphone : public Electronics {
public:
    std::string operatingSystem;

    Smartphone(double pc, std::string m, std::string os)
        : Electronics(pc, m) { // Base class uses initializer list, but derived member does not
        operatingSystem = os;
    }


    ~Smartphone() {
    }

    void displaySmartphoneDetails() { // Missing const-correctness
        displayElectronicsDetails(); // Calls base method
        std::cout << "Smartphone Details:" << std::endl;
        std::cout << "  Operating System: " << operatingSystem << std::endl;
    }
};

class PremiumSmartphone : public Smartphone {
public:
    int cameraMP;

    PremiumSmartphone(double pc, std::string m, std::string os, int cmp)
        : Smartphone(pc, m, os) { // Base class uses initializer list, but derived member does not
        cameraMP = cmp;
    }


    ~PremiumSmartphone() {
    }

    void displayPremiumSmartphoneDetails() { // Missing const-correctness
        displaySmartphoneDetails(); // Calls base method
        std::cout << "Premium Smartphone Details:" << std::endl;
        std::cout << "  Camera Megapixels: " << cameraMP << "MP" << std::endl;
    }
};

int main() {
    PremiumSmartphone myPremiumPhone(11.2, "GlobalTech", "Android 13", 108);
    std::cout << "Displaying Premium Smartphone details:" << std::endl;
    myPremiumPhone.displayPremiumSmartphoneDetails();
    std::cout << std::endl; // Extra std::endl for spacing

    return 0;
}