#include <iostream>
#include <string>
#include <sstream>
#include <vector> // Using vector for test case input

class ResourceHandler {
public:
    int* m_data;
    int m_size;

    // Constructor: Allocates memory for an integer array of specified size
    ResourceHandler(int size) : m_size(size), m_data(nullptr) {
        if (m_size > 0) {
            m_data = new int[m_size];
            // Initialize array elements to 0 for consistency in output
            for (int i = 0; i < m_size; ++i) {
                m_data[i] = 0;
            }
        } else {
            m_size = 0; // Ensure size is non-negative
        }
    }

    // Destructor: Deallocates the dynamically allocated memory
    ~ResourceHandler() {
        if (m_data != nullptr) {
            delete[] m_data;
            m_data = nullptr; // Good practice to nullify after deletion
        }
    }

    // Method to set a value at a specific index
    void setValue(int index, int value) {
        if (index >= 0 && index < m_size) {
            m_data[index] = value;
        }
    }

    // Method to get a value at a specific index
    int getValue(int index) const {
        if (index >= 0 && index < m_size) {
            return m_data[index];
        }
        return -1; // Indicate error or out of bounds
    }

    // Method to print the array contents
    std::string printArray() const {
        std::ostringstream oss;
        oss << "[";
        for (int i = 0; i < m_size; ++i) {
            oss << m_data[i];
            if (i < m_size - 1) {
                oss << ", ";
            }
        }
        oss << "]";
        return oss.str();
    }

    // No custom copy constructor or copy assignment operator defined.
    // The compiler-generated default ones will perform shallow copies,
    // leading to double-free issues when objects are copied and then destroyed.
};

void run_test_case(int initial_size, const std::vector<std::pair<int, int>>& values_to_set, std::ostream& os) {
    os << "Creating handler1 with size " << initial_size << std::endl;
    ResourceHandler handler1(initial_size);
    for (const auto& p : values_to_set) {
        handler1.setValue(p.first, p.second);
    }
    os << "handler1 array: " << handler1.printArray() << std::endl;

    os << "Creating handler2 as a copy of handler1 (shallow copy)" << std::endl;
    ResourceHandler handler2 = handler1; // Calls default copy constructor
    os << "handler2 array: " << handler2.printArray() << std::endl;

    os << "Modifying handler1..." << std::endl;
    handler1.setValue(0, 99);
    os << "handler1 array after modification: " << handler1.printArray() << std::endl;
    os << "handler2 array (should also reflect change due to shallow copy): " << handler2.printArray() << std::endl;

    os << "handler1 and handler2 now point to the same memory." << std::endl;
    os << "When handler1 is destroyed, it will deallocate the memory." << std::endl;
    os << "When handler2 is destroyed, it will attempt to deallocate the same memory again (double-free)." << std::endl;
    os << "End of test case. Destructors will be called." << std::endl;
}

int main() {
    std::vector<std::pair<int, int>> values1 = {{0, 10}, {1, 20}, {2, 30}};
    run_test_case(3, values1, std::cout);
    return 0;
}