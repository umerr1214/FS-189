#include <iostream>
#include <string>
#include <memory> // For std::unique_ptr

class Base {
public:
    Base() {
        std::cout << "Base Constructor" << std::endl;
    }
    // Correct: Virtual destructor.
    // This ensures that when a Derived object is deleted through a Base* pointer,
    // the correct destructor sequence (Derived then Base) is called,
    // preventing memory leaks and ensuring proper cleanup.
    virtual ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base {
private:
    std::string* data_buffer; // Simulate a dynamically allocated resource
public:
    Derived(const std::string& info = "Derived's data") : Base(), data_buffer(new std::string(info)) {
        std::cout << "Derived Constructor (" << *data_buffer << ")" << std::endl;
    }
    // 'override' keyword is good practice for virtual functions
    ~Derived() override {
        std::cout << "Derived Destructor (" << *data_buffer << ")" << std::endl;
        delete data_buffer; // This memory is now correctly freed
    }
};

void demonstrate_correctness() {
    std::cout << "--- Demonstrating Correct Polymorphic Destruction (Raw Pointer) ---" << std::endl;
    std::cout << "Creating a Derived object via a Base pointer:" << std::endl;
    Base* ptr_raw = new Derived("Raw Pointer Managed Derived"); // Allocate Derived object
    
    std::cout << "\nDeleting the object via the Base pointer:" << std::endl;
    // Due to 'virtual ~Base()', both Derived and Base destructors are called correctly.
    delete ptr_raw;
    std::cout << "--- End Raw Pointer Demonstration ---" << std::endl;

    std::cout << "\n--- Demonstrating Correct Polymorphic Destruction (Smart Pointer) ---" << std::endl;
    std::cout << "Creating a Derived object using std::unique_ptr<Base>:" << std::endl;
    // std::unique_ptr automatically manages memory, leveraging the virtual destructor.
    std::unique_ptr<Base> ptr_smart = std::make_unique<Derived>("Smart Pointer Managed Derived");
    
    std::cout << "Smart pointer object created. It will be automatically deleted on scope exit." << std::endl;
    // No explicit 'delete' needed. The unique_ptr ensures proper cleanup.
    std::cout << "--- End Smart Pointer Demonstration (Scope Exit) ---" << std::endl;

} // ptr_smart goes out of scope here, triggering its destructor and thus the virtual destructors

int main() {
    demonstrate_correctness();
    return 0;
}