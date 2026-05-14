#include <iostream>
#include <string>
#include <vector>

// Base class Vehicle
class Vehicle {
protected:
    int speed;
    std::string color;

public:
    Vehicle(int s, const std::string& c) : speed(s), color(c) {}

    // Robustness Issue 1: Missing virtual destructor.
    // If a derived class object is deleted via a Vehicle* pointer,
    // the derived class destructor will not be called, leading to resource leaks
    // if derived classes managed dynamic memory beyond std::string.
    // ~Vehicle() {} // Should be virtual ~Vehicle() {}

    void setSpeed(int s) {
        // Robustness Issue 2: No validation for speed.
        // Allows negative speed, which might be an invalid state for a vehicle.
        speed = s;
    }

    int getSpeed() const {
        return speed;
    }

    void setColor(const std::string& c) {
        color = c;
    }

    const std::string& getColor() const {
        return color;
    }

    void displayVehicleInfo() const {
        std::cout << "Vehicle Info: Speed = " << speed << " mph, Color = " << color << std::endl;
    }
};

// Derived class Car
class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(int s, const std::string& c, int nd) : Vehicle(s, c), numDoors(nd) {}

    void setNumDoors(int nd) {
        // Robustness Issue 3: No validation for numDoors.
        // Allows 0 or negative doors, which is an invalid state for a car.
        numDoors = nd;
    }

    int getNumDoors() const {
        return numDoors;
    }

    void honkHorn() const {
        std::cout << "Car specific method: Honk! Honk! (This car has " << numDoors << " doors)." << std::endl;
    }

    void displayCarInfo() const {
        displayVehicleInfo(); // Call base method
        std::cout << "Car Specifics: Number of Doors = " << numDoors << std::endl;
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    Motorcycle(int s, const std::string& c, bool hs) : Vehicle(s, c), hasSidecar(hs) {}

    void setHasSidecar(bool hs) {
        hasSidecar = hs;
    }

    bool getHasSidecar() const {
        return hasSidecar;
    }

    void wheelie() const {
        std::cout << "Motorcycle specific method: Doing a wheelie! "
                  << (hasSidecar ? "Careful with the sidecar!" : "Whee!") << std::endl;
    }

    void displayMotorcycleInfo() const {
        displayVehicleInfo(); // Call base method
        std::cout << "Motorcycle Specifics: Has Sidecar = " << (hasSidecar ? "Yes" : "No") << std::endl;
    }
};

int main() {
    std::cout << "--- Demonstrating Car ---" << std::endl;
    Car myCar(120, "Red", 4);
    myCar.displayCarInfo();
    myCar.honkHorn();

    std::cout << "\n--- Demonstrating Motorcycle ---" << std::endl;
    Motorcycle myMotorcycle(90, "Black", true);
    myMotorcycle.displayMotorcycleInfo();
    myMotorcycle.wheelie();

    std::cout << "\n--- Demonstrating Robustness Issues ---" << std::endl;
    std::cout << "Setting invalid speed and doors:" << std::endl;
    myCar.setSpeed(-50); // Setting negative speed
    myCar.setNumDoors(0); // Setting 0 doors
    myCar.displayCarInfo();

    // The missing virtual destructor issue would manifest if we had dynamic memory
    // in derived classes and deleted them polymorphically.
    // Example (commented out to avoid compile errors if no dynamic memory is added):
    /*
    Vehicle* v_ptr = new Car(100, "Blue", 2);
    // If Vehicle had a non-virtual destructor, Car's destructor wouldn't be called.
    delete v_ptr;
    */

    return 0;
}