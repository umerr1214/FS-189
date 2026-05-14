#include <iostream>
#include <string>

// Base class V
class V {
    public:
        // Virtual method sE
        virtual void sE() {
            std::cout << "Vehicle engine starting...\n";
        }
        virtual ~V() {
            std::cout << "V destructor called.\n";
        }
};

// Derived class C
class C : public V {
    public:
        // Overriding sE, but missing 'override' keyword and bad formatting
        void sE() {
            std::cout << "Car engine starting, vroom vroom!\n";
        }
        ~C() {
            std::cout << "C destructor called.\n";
        }
};

// Derived class M
class M : public V {
    public:
        // Overriding sE, bad formatting
        void sE() {
            std::cout << "Motorcycle engine starting, revving up!\n";
        }
        ~M() {
            std::cout << "M destructor called.\n";
        }
};

int main() {
    std::cout << "--- Testing Vehicle ---\n";
    V* genericVehicle = new V();
    genericVehicle->sE();
    delete genericVehicle;

    std::cout << "--- Testing Car ---\n";
    V* car = new C(); // Polymorphic pointer
    car->sE();
    delete car;

    std::cout << "--- Testing Motorcycle ---\n";
    V* motorcycle = new M(); // Polymorphic pointer
    motorcycle->sE();
    delete motorcycle;

    // Also test direct instantiation for completeness
    std::cout << "--- Testing direct Car object ---\n";
    C myCar;
    myCar.sE();

    std::cout << "--- Testing direct Motorcycle object ---\n";
    M myMotorcycle;
    myMotorcycle.sE();

    return 0;
}