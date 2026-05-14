#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm> // For std::copy

class ResourceHandler {
private:
    int* m_data;
    size_t m_size; // Use size_t for array sizes

public:
    // Constructor: Allocates memory and initializes elements to 0
    ResourceHandler(size_t size) : m_size(size), m_data(nullptr) {
        if (m_size > 0) {
            m_data = new int[m_size](); // Value-initializes all elements to 0
        }
    }

    // Destructor: Correctly deallocates the dynamically allocated memory
    ~ResourceHandler() {
        delete[] m_data; // It's safe to call delete[] on a nullptr
        m_data = nullptr; // Good practice to nullify after deletion
    }

    // Copy Constructor: Performs a deep copy
    ResourceHandler(const ResourceHandler& other) : m_size(other.m_size), m_data(nullptr) {
        if (m_size > 0) {
            m_data = new int[m_size];
            std::copy(other.m_data, other.m_data + other.m_size, m_data);
        }
    }

    // Copy Assignment Operator: Performs a deep copy, handles self-assignment
    ResourceHandler& operator=(const ResourceHandler& other) {
        if (this == &other) { // Handle self-assignment
            return *this;
        }

        // Deallocate existing memory
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;

        // Allocate new memory and copy data
        m_size = other.m_size;
        if (m_size > 0) {
            m_data = new int[m_size];
            std::copy(other.m_data, other.m_data + other.m_size, m_data);
        }
        return *this;
    }

    // Accessor to set a value at a specific index
    void setValue(size_t index, int value) {
        if (index < m_size) { // Check for valid index
            m_data[index] = value;
        } else {
            std::cerr << "Error: Index " << index << " out of bounds for size " << m_size << std::endl;
        }
    }

    // Accessor to get a value at a specific index (const-correct)
    int getValue(size_t index) const {
        if (index < m_size) {
            return m_data[index];
        }
        std::cerr << "Error: Index " << index << " out of bounds for size " << m_size << std::endl;
        return 0; // Return a default/error value
    }

    // Method to print the array contents
    std::string printArray() const {
        std::ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < m_size; ++i) {
            oss << m_data[i];
            if (i < m_size - 1) {
                oss << ", ";
            }
        }
        oss << "]";
        return oss.str();
    }
};

void run_test_case(size_t initial_size, const std::vector<std::pair<size_t, int>>& values_to_set, std::ostream& os) {
    os << "Creating handler1 with size " << initial_size << std::endl;
    ResourceHandler handler1(initial_size);
    for (const auto& p : values_to_set) {
        handler1.setValue(p.first, p.second);
    }
    os << "handler1 array: " << handler1.printArray() << std::endl;

    os << "Creating handler2 as a copy of handler1 (deep copy)" << std::endl;
    ResourceHandler handler2 = handler1; // Calls copy constructor
    os << "handler2 array: " << handler2.printArray() << std::endl;

    os << "Modifying handler1..." << std::endl;
    handler1.setValue(0, 99);
    os << "handler1 array after modification: " << handler1.printArray() << std::endl;
    os << "handler2 array (should be unchanged due to deep copy): " << handler2.printArray() << std::endl;

    os << "Creating handler3 and assigning handler1 to it (deep copy)" << std::endl;
    ResourceHandler handler3(2); // Create with a different size first
    handler3.setValue(0, 5);
    handler3.setValue(1, 10);
    os << "handler3 initial array: " << handler3.printArray() << std::endl;
    handler3 = handler1; // Calls copy assignment operator
    os << "handler3 array after assignment from handler1: " << handler3.printArray() << std::endl;

    os << "End of test case. Destructors will be called correctly." << std::endl;
}

int main() {
    std::vector<std::pair<size_t, int>> values1 = {{0, 10}, {1, 20}, {2, 30}};
    run_test_case(3, values1, std::cout);
    return 0;
}