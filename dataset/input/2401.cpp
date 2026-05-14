#include <iostream>
#include <string>
#include <vector>

// Simulate a global counter for resource IDs to highlight the issue
// This global state is part of the problematic design for demonstrating the robustness issue.
static int next_resource_id = 0;

class ResourceHandler {
public:
    int resource_id;

    ResourceHandler() : resource_id(++next_resource_id) {
        std::cout << "Resource " << resource_id << " acquired." << std::endl;
    }

    // Problem: The class implicitly uses the default copy constructor and copy assignment operator.
    // For a resource-managing class, this leads to a shallow copy of the 'resource_id'.
    // Consequently, multiple ResourceHandler objects can end up managing the same conceptual resource ID.
    // This violates the Rule of Three/Five/Zero and can cause severe robustness issues
    // such as double-release (calling the destructor twice for the same resource ID)
    // or resource leaks if not properly managed.
    // In this simulation, it means "Resource X released." will print multiple times
    // for the same ID, indicating a double-release scenario.

    ~ResourceHandler() {
        std::cout << "Resource " << resource_id << " released." << std::endl;
    }

    void do_work() const {
        std::cout << "Resource " << resource_id << " doing work." << std::endl;
    }
};

// Function to demonstrate passing ResourceHandler by value, triggering the copy constructor.
void process_resource(ResourceHandler rh) { // 'rh' is a copy of the argument
    rh.do_work();
    // When 'rh' goes out of scope, its destructor is called, releasing the resource.
    // This is problematic because the original 'ResourceHandler' object still exists
    // and will attempt to release the *same* resource later.
}

int main() {
    std::cout << "--- Main Scope Start ---" << std::endl;
    {
        ResourceHandler res1; // Resource 1 acquired
        res1.do_work();

        std::cout << "--- Calling process_resource ---" << std::endl;
        process_resource(res1); // Problematic copy occurs here
        std::cout << "--- Returned from process_resource ---" << std::endl;
        // At this point, the resource_id 1 has already been "released" by the copy 'rh'.
        // When 'res1' goes out of scope, it will attempt to "release" resource_id 1 again.
    } // res1's destructor called here, leading to double-release for resource 1
    std::cout << "--- Main Scope End ---" << std::endl;

    std::cout << "\n--- Another test with vector (also problematic) ---" << std::endl;
    std::vector<ResourceHandler> handlers;
    // When ResourceHandler() creates a temporary, it acquires a resource (e.g., Resource 2).
    // push_back then copies this temporary into the vector (using the default copy constructor).
    // The temporary is then destroyed, releasing Resource 2.
    // The copy in the vector still holds Resource 2.
    handlers.push_back(ResourceHandler()); // Resource 2 acquired, temporary copy created for vector, temporary released
    handlers.push_back(ResourceHandler()); // Resource 3 acquired, temporary copy created for vector, temporary released
    std::cout << "--- Vector filled ---" << std::endl;
    // When 'handlers' vector is destroyed at the end of main, it will destroy its elements.
    // This will cause Resource 2 and Resource 3 to be "released" again, leading to double-release.

    return 0;
}