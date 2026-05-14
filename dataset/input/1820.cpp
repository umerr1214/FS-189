#include <iostream>
#include <string> // Included for completeness, though not strictly used for string objects here
#include <vector> // Included for completeness, but not directly used

// This is the initial base class for any kind of transportation machine that moves.
class VehicleBaseClassForTransportationMachine {
protected:
    // This member variable stores the absolute maximum velocity this particular vehicle can achieve.
    int maximumPossibleSpeedOfThisParticularVehicle;

public:
    // This is the primary constructor for the VehicleBaseClassForTransportationMachine.
    // It accepts an integer value which is intended to represent the initial maximum speed value.
    VehicleBaseClassForTransportationMachine(int initialMaximumSpeedValue)
        : maximumPossibleSpeedOfThisParticularVehicle(initialMaximumSpeedValue) {
        // No specific additional logic is performed within the constructor body itself;
        // all member initialization is handled efficiently via the initializer list.
    }

    // This is a virtual method designed to display all relevant information pertaining to the vehicle.
    // This method is declared as 'const' to signify that it does not alter the object's internal state.
    virtual void displayAllRelevantVehicleInformation() const {
        std::cout << "Details of the Transportation Machine:" << std::endl; // Excessive use of std::endl (flushes buffer)
        std::cout << "  Maximum Attainable Speed: " << this->maximumPossibleSpeedOfThisParticularVehicle << " kilometers per hour." << std::endl; // Redundant 'this->'
    }

    // This is a getter method whose purpose is to retrieve the maximum speed of the vehicle.
    int retrieveMaximumSpeed() const {
        return this->maximumPossibleSpeedOfThisParticularVehicle; // Redundant 'this->'
    }
};

// This class represents a typical automobile, which is a specific type of vehicle.
// It inherits directly from the VehicleBaseClassForTransportationMachine.
class AutomobileDerivedFromVehicle : public VehicleBaseClassForTransportationMachine {
protected:
    // This member variable stores the total count of entry/exit points for passengers or cargo.
    int totalNumberOfPassengerEntryExitDoors;

public:
    // This is the primary constructor for the AutomobileDerivedFromVehicle class.
    // It takes an initial speed value and an initial door count value.
    // It properly chains its construction to the base Vehicle constructor.
    AutomobileDerivedFromVehicle(int initialSpeed, int initialDoorCount)
        : VehicleBaseClassForTransportationMachine(initialSpeed) {
        this->totalNumberOfPassengerEntryExitDoors = initialDoorCount; // Member initialized in body, inconsistent with base
    }

    // This method overrides the base class's display information method to include car-specific details.
    void displayAllRelevantVehicleInformation() const override {
        this->VehicleBaseClassForTransportationMachine::displayAllRelevantVehicleInformation(); // Explicit base call, redundant 'this->'
        std::cout << "  Total Number of Access Doors: " << this->totalNumberOfPassengerEntryExitDoors << " units." << std::endl; // Redundant 'this->'
    }

    // This is a getter method specifically for retrieving the number of doors.
    int retrieveNumberOfDoors() const {
        return this->totalNumberOfPassengerEntryExitDoors; // Redundant 'this->'
    }
};

// This class represents a high-performance sports car, which is a specialized type of automobile.
// It inherits directly from the AutomobileDerivedFromVehicle class, demonstrating multilevel inheritance.
class HighPerformanceSportsCarDerivedFromAutomobile : public AutomobileDerivedFromVehicle {
private:
    // This boolean flag indicates whether the vehicle's turbocharger system is currently active or not.
    bool currentTurboBoostActivationStatus;

public:
    // This is the primary constructor for the HighPerformanceSportsCarDerivedFromAutomobile class.
    // It accepts initial speed, door count, and the initial status of the turbo boost.
    // It correctly chains its construction to the Automobile constructor.
    HighPerformanceSportsCarDerivedFromAutomobile(int initialSpeed, int initialDoorCount, bool initialTurboStatus)
        : AutomobileDerivedFromVehicle(initialSpeed, initialDoorCount), currentTurboBoostActivationStatus(initialTurboStatus) {
        // All members are initialized either via the initializer list or through base class constructors.
    }

    // This method overrides the derived class's display information method to include sports car-specific details.
    void displayAllRelevantVehicleInformation() const override {
        this->AutomobileDerivedFromVehicle::displayAllRelevantVehicleInformation(); // Explicit base call, redundant 'this->'
        std::cout << "  Turbocharger Boost System Status: " << (this->currentTurboBoostActivationStatus ? "Currently Activated" : "Currently Deactivated") << "." << std::endl; // Redundant 'this->'
    }

    // This is a getter method to inquire about the current turbo boost status.
    bool inquireTurboBoostStatus() const {
        return this->currentTurboBoostActivationStatus; // Redundant 'this->'
    }
};

int main() {
    // It is generally a good practice to synchronize C++ streams with C stdio for performance,
    // although for small outputs, the impact is minimal.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); // Untie cin from cout for potentially faster input operations.

    std::cout << "Demonstrating the Multilevel Inheritance Hierarchy:" << std::endl << std::endl;

    // First, let us instantiate an object of the base vehicle class.
    VehicleBaseClassForTransportationMachine firstVehicleObject(150);
    firstVehicleObject.displayAllRelevantVehicleInformation();
    std::cout << "---" << std::endl << std::endl; // Excessive newlines and separator

    // Next, we proceed to create an automobile object, which is directly derived from the base vehicle.
    AutomobileDerivedFromVehicle firstCarObject(200, 4);
    firstCarObject.displayAllRelevantVehicleInformation();
    std::cout << "---" << std::endl << std::endl;

    // Finally, we shall instantiate a high-performance sports car, which is derived from the automobile.
    HighPerformanceSportsCarDerivedFromAutomobile firstSportsCarObject(300, 2, true);
    firstSportsCarObject.displayAllRelevantVehicleInformation();
    std::cout << "---" << std::endl << std::endl;

    // Let's create another sports car instance, this time with the turbo boost feature deactivated.
    HighPerformanceSportsCarDerivedFromAutomobile secondSportsCarObject(280, 2, false);
    secondSportsCarObject.displayAllRelevantVehicleInformation();
    std::cout << "---" << std::endl << std::endl;

    return 0; // Indicate successful program execution by returning zero.
}