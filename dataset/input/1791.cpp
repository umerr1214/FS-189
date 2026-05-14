#include <iostream> // Required for input/output operations
#include <string>   // Required for std::string

// Resource class that simulates acquiring and releasing a resource
class Resource {
private:
    std::string name; // Name of the resource for identification

public:
    // Constructor: Called when a Resource object is created
    // Simulates acquiring the resource and prints a message.
    Resource(const std::string& n) : name(n) {
        std::cout << "Resource " << name << " acquired." << std::endl;
    }

    // Destructor: Called when a Resource object is destroyed
    // Simulates releasing the resource and prints a message.
    ~Resource() {
        std::cout << "Resource " << name << " released." << std::endl;
    }

    // A simple method to demonstrate the resource is active and usable
    void use() const {
        std::cout << "Resource " << name << " is in use." << std::endl;
    }
};

// Function to demonstrate the order of constructor and destructor calls
// for local objects within different scopes.
void demonstrateScope() {
    std::cout << "\n--- Entering demonstrateScope() ---" << std::endl;

    // Object 1: Created at the start of the demonstrateScope() function's scope
    Resource res1("First");
    res1.use();

    { // Start of a nested scope
        std::cout << "  --- Entering nested scope ---" << std::endl;

        // Object 2: Created within the nested scope
        Resource res2("Second");
        res2.use();

        // Object 3: Created after res2 within the same nested scope
        Resource res3("Third");
        res3.use();

        std::cout << "  --- Exiting nested scope ---" << std::endl;
    } // End of nested scope: res3's destructor is called, then res2's destructor (LIFO order)

    // Object 4: Created after the nested scope, but still within demonstrateScope()'s main scope
    Resource res4("Fourth");
    res4.use();

    std::cout << "--- Exiting demonstrateScope() ---" << std::endl;
} // End of demonstrateScope() function: res4's destructor is called, then res1's destructor (LIFO order)

int main() {
    std::cout << "--- Main function started ---" << std::endl;

    // Call the function that demonstrates object lifetimes and scopes
    demonstrateScope();

    std::cout << "--- Main function finished ---" << std::endl;
    return 0; // Indicate successful execution
}