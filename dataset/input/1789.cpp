#include <iostream>
#include <string>
#include <stdexcept> // For std::runtime_error

class Resource {
private:
    std::string name;
    int* data; // Internal raw resource that needs careful management
public:
    Resource(const std::string& n) : name(n), data(nullptr) {
        std::cout << "Resource " << name << " acquired." << std::endl;
        // Simulate acquiring an internal resource (dynamic memory)
        data = new int[10]; // Allocate dynamic memory
        for (int i = 0; i < 10; ++i) data[i] = i;
    }

    ~Resource() {
        std::cout << "Resource " << name << " released." << std::endl;
        if (data) {
            delete[] data; // Release internal resource
            data = nullptr;
        }
    }

    void use() const {
        std::cout << "Resource " << name << " in use. Data[0]: " << data[0] << std::endl;
    }
};

// Function that might throw an exception, demonstrating a robustness issue
void potentiallyThrowingFunction() {
    static int callCount = 0;
    callCount++;
    if (callCount % 2 == 0) { // Throw an exception on every second call
        std::cerr << "Potentially throwing function throwing an exception!" << std::endl;
        throw std::runtime_error("Simulated error in potentiallyThrowingFunction");
    }
    std::cout << "Potentially throwing function completed successfully." << std::endl;
}

// Function to demonstrate local object lifetimes with a robustness issue
void demonstrateScopeRobustness() {
    std::cout << "\n--- Entering demonstrateScopeRobustness ---" << std::endl;
    Resource res1("A"); // Resource managed by RAII

    int* raw_resource = nullptr; // Raw pointer resource, prone to leaks
    try {
        raw_resource = new int(100); // Raw resource acquired manually
        std::cout << "Raw resource acquired: " << *raw_resource << std::endl;

        potentiallyThrowingFunction(); // This might throw an exception

        Resource res2("B"); // This resource might not be constructed if an exception occurs above
        res2.use();

        // Robustness issue: If potentiallyThrowingFunction throws, this 'delete' is skipped,
        // leading to a memory leak for 'raw_resource'.
        delete raw_resource;
        raw_resource = nullptr; // Prevent double-free
    } catch (const std::exception& e) {
        std::cerr << "Caught exception in demonstrateScopeRobustness: " << e.what() << std::endl;
        // Robustness issue demonstration: The 'raw_resource' is not deleted here,
        // highlighting the leak path if RAII isn't used for all resources.
        if (raw_resource) {
            std::cerr << "WARNING: Raw resource (int*) was leaked due to exception!" << std::endl;
            // For this example, we intentionally do not delete raw_resource here
            // to demonstrate the robustness issue. In real code, this would be a bug.
        }
    }
    std::cout << "--- Exiting demonstrateScopeRobustness ---" << std::endl;
    // res1 destructor will be called here automatically (RAII works)
}

int main() {
    std::cout << "--- Main function started ---" << std::endl;
    try {
        demonstrateScopeRobustness(); // First call: no exception
        demonstrateScopeRobustness(); // Second call: throws exception
    } catch (const std::exception& e) {
        // This catch block would only be reached if an exception escaped demonstrateScopeRobustness
        std::cerr << "Caught unhandled exception in main: " << e.what() << std::endl;
    }
    std::cout << "--- Main function finished ---" << std::endl;
    return 0;
}