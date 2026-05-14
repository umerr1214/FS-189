#include <iostream> // For std::cout, but also mixing with cstdio
#include <string>
#include <cstdio>   // For printf and snprintf
#include <vector>   // For internal data storage, potentially used inefficiently

class Resource {
private:
    std::string resource_name_identifier; // Overly verbose variable name
    std::vector<int> internal_data_storage; // Vector used for simple data, could be inefficiently sized

public:
    Resource(const std::string& name_param) : resource_name_identifier(name_param) {
        // Inefficient string formatting and mixing output styles
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Resource %s has been acquired by the system. Starting internal data allocation now...", resource_name_identifier.c_str());
        printf("%s\n", buffer); // Using printf

        // Simulating potentially inefficient internal data initialization
        // A large loop for a simple demonstration resource, affecting efficiency
        for (int i = 0; i < 1000; ++i) {
            internal_data_storage.push_back(i * 2 + 1); // Repeated allocations if capacity not reserved
        }
        printf("Internal data for %s initialized with %zu elements.\n", resource_name_identifier.c_str(), internal_data_storage.size());
    }

    ~Resource() {
        // Overly verbose and inefficient string concatenation, using std::endl frequently
        std::string release_message = "Resource ";
        release_message += resource_name_identifier;
        release_message += " is now being released. Goodbye from destructor!";
        std::cout << release_message << std::endl; // Using std::cout and std::endl
        // Redundant clear, as vector will be destroyed anyway
        internal_data_storage.clear();
    }

    void perform_action() const {
        // Mixing printf for consistency in this 'bad' example
        printf("Resource %s is performing its designated action. First data element: %d\n", resource_name_identifier.c_str(), internal_data_storage[0]);
    }
};

// Function with overly verbose name and unnecessary nested scopes
void demonstrate_resource_lifespan_and_order_of_destruction() {
    std::cout << "\n--- Entering demonstrate_resource_lifespan_and_order_of_destruction ---" << std::endl;

    Resource first_local_resource_instance("Alpha"); // First object with verbose name
    first_local_resource_instance.perform_action();

    { // Unnecessary nested scope, impacts readability and flow
        Resource second_local_resource_instance_in_nested_scope("Beta"); // Second object
        second_local_resource_instance_in_nested_scope.perform_action();

        Resource third_local_resource_instance_further_nested("Gamma"); // Third object
        third_local_resource_instance_further_nested.perform_action();

        std::cout << "  --- Exiting unnecessary nested scope ---" << std::endl;
    } // Destructors for 'Gamma' then 'Beta' are called here

    Resource fourth_local_resource_instance_after_nested_scope("Delta"); // Fourth object
    fourth_local_resource_instance_after_nested_scope.perform_action();

    std::cout << "--- Exiting demonstrate_resource_lifespan_and_order_of_destruction ---" << std::endl;
} // Destructors for 'Delta' then 'Alpha' are called here

int main() {
    std::cout << "Starting main function execution." << std::endl;
    demonstrate_resource_lifespan_and_order_of_destruction();
    std::cout << "Main function execution finished." << std::endl;
    return 0;
}