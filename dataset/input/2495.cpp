#include <iostream>

class Engine {
public:
    Engine() {
        std::cout << "Engine created." << std::endl;
    }
    ~Engine() {
        std::cout << "Engine destroyed." << std::endl;
    }
};

class Car {
public:
    Car() {
        // Logical Error: Engine is dynamically allocated but not properly composed.
        // The Car class takes ownership of the Engine pointer.
        // However, the destructor forgets to delete it, leading to a memory leak.
        engine_ptr_ = new Engine(); 
        std::cout << "Car created." << std::endl;
    }
    ~Car() {
        std::cout << "Car destroyed." << std::endl;
        // Logical Error: Missing 'delete engine_ptr_;' here.
        // This means the Engine object will not be destroyed along with the Car.
    }

private:
    Engine* engine_ptr_; // Pointer to Engine, implying dynamic allocation
};

int main() {
    std::cout << "--- Starting main ---" << std::endl;
    Car myCar;
    std::cout << "--- End of main ---" << std::endl;
    return 0;
}