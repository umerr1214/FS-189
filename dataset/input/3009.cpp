#include <iostream>
#include <algorithm> // For std::copy, std::swap
#include <numeric>   // For std::iota (optional, good for filling sequences)
#include <stdexcept> // For std::bad_alloc or std::invalid_argument

class Resource {
private:
    int* m_array;
    int m_size;

public:
    // Constructor
    explicit Resource(int size) : m_array(nullptr), m_size(0) {
        if (size <= 0) {
            throw std::invalid_argument("Array size must be positive.");
        }
        m_array = new int[size]{}; // Allocate and zero-initialize
        m_size = size;
        std::cout << "Resource created with size " << m_size << ". Memory allocated at " << static_cast<void*>(m_array) << std::endl;
    }

    // Destructor
    ~Resource() {
        if (m_array) {
            std::cout << "Resource of size " << m_size << " at " << static_cast<void*>(m_array) << " being destroyed. Memory deallocated." << std::endl;
            delete[] m_array;
            m_array = nullptr; // Good practice to nullify after delete
            m_size = 0;
        }
    }

    // Copy Constructor (Deep Copy)
    Resource(const Resource& other) : m_array(nullptr), m_size(0) {
        if (other.m_array) {
            m_array = new int[other.m_size];
            std::copy(other.m_array, other.m_array + other.m_size, m_array);
            m_size = other.m_size;
        }
        std::cout << "Resource copy constructed (deep copy) from " << static_cast<void*>(other.m_array) 
                  << " to " << static_cast<void*>(m_array) << " with size " << m_size << std::endl;
    }

    // Copy Assignment Operator (Deep Copy - using copy-and-swap idiom)
    Resource& operator=(Resource other) { // 'other' is passed by value, triggering copy constructor
        std::swap(m_array, other.m_array);
        std::swap(m_size, other.m_size);
        std::cout << "Resource copy assigned (copy-and-swap). New object has size " << m_size << std::endl;
        return *this;
    }

    // Move Constructor
    Resource(Resource&& other) noexcept : m_array(other.m_array), m_size(other.m_size) {
        other.m_array = nullptr; // Steal the resource
        other.m_size = 0;
        std::cout << "Resource move constructed. Stole resource from " << static_cast<void*>(other.m_array) 
                  << " to " << static_cast<void*>(m_array) << " with size " << m_size << std::endl;
    }

    // Move Assignment Operator
    Resource& operator=(Resource&& other) noexcept {
        if (this != &other) { // Self-assignment check
            delete[] m_array; // Release current resource
            m_array = other.m_array; // Steal resource
            m_size = other.m_size;

            other.m_array = nullptr; // Nullify 'other'
            other.m_size = 0;
        }
        std::cout << "Resource move assigned. New object has size " << m_size << std::endl;
        return *this;
    }

    // fillArray method
    void fillArray(int start_val = 0, int increment = 1) {
        if (!m_array) {
            std::cerr << "Error: Array not allocated. Cannot fill." << std::endl;
            return;
        }
        for (int i = 0; i < m_size; ++i) {
            m_array[i] = start_val + i * increment;
        }
        std::cout << "Array filled with custom sequence (start=" << start_val << ", inc=" << increment << ")." << std::endl;
    }

    // displayArray method (const correct)
    void displayArray() const {
        if (!m_array) {
            std::cout << "Error: Array not allocated. Cannot display." << std::endl;
            return;
        }
        std::cout << "Array contents (size " << m_size << ", at " << static_cast<void*>(m_array) << "): [";
        for (int i = 0; i < m_size; ++i) {
            std::cout << m_array[i] << (i == m_size - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }

    // Getter for size (const correct)
    int getSize() const {
        return m_size;
    }
};

// Function to demonstrate copy/move constructor in return value optimization context
Resource createAndReturnCopy(Resource res) { // res is copy-constructed from argument
    std::cout << "Inside createAndReturnCopy function." << std::endl;
    res.fillArray(100, 1);
    res.displayArray();
    std::cout << "Returning copy from createAndReturnCopy." << std::endl;
    return res; // Return by value, triggers move constructor (RVO/NRVO optimization might occur)
}

int main() {
    std::cout << "--- Starting Program: Correct Resource Management ---" << std::endl;

    try {
        // 1. Basic Lifecycle
        std::cout << "\n--- 1. Basic Lifecycle ---" << std::endl;
        Resource r1(5);
        r1.fillArray();
        r1.displayArray();

        // 2. Invalid size handling
        std::cout << "\n--- 2. Invalid Size Handling ---" << std::endl;
        try {
            Resource r_invalid(0);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Caught expected error: " << e.what() << std::endl;
        }

        // 3. Copy Constructor
        std::cout << "\n--- 3. Copy Constructor ---" << std::endl;
        Resource r2 = r1; // Calls copy constructor
        r2.fillArray(10, 2);
        r1.displayArray(); // Original unchanged
        r2.displayArray(); // Copy changed

        // 4. Copy Assignment Operator
        std::cout << "\n--- 4. Copy Assignment Operator ---" << std::endl;
        Resource r3(4);
        r3.fillArray(50, 5);
        r3.displayArray();
        r3 = r1; // Calls copy assignment operator
        r3.displayArray(); // r3 now has r1's content
        r1.displayArray(); // Original r1 unchanged

        // 5. Move Constructor
        std::cout << "\n--- 5. Move Constructor (Return Value Optimization might apply) ---" << std::endl;
        Resource r4(2);
        r4.fillArray(200, 1);
        r4.displayArray();
        Resource r5 = std::move(r4); // Explicit move constructor
        r5.displayArray();
        // r4 is now in a valid but unspecified state (m_array is nullptr, m_size is 0)
        std::cout << "r4 after move: size=" << r4.getSize() << std::endl;
        r4.displayArray(); // Should print error as m_array is nullptr

        // 6. Move Assignment Operator
        std::cout << "\n--- 6. Move Assignment Operator ---" << std::endl;
        Resource r6(3);
        r6.fillArray(30, 3);
        r6.displayArray();
        Resource r7(6);
        r7.fillArray(60, 6);
        r7.displayArray();
        
        r7 = std::move(r6); // Explicit move assignment
        r7.displayArray();
        std::cout << "r6 after move assignment: size=" << r6.getSize() << std::endl;
        r6.displayArray(); // Should print error as m_array is nullptr

        // 7. Demonstration of copy/move in function calls
        std::cout << "\n--- 7. Function Call Semantics ---" << std::endl;
        Resource r_temp(2);
        r_temp.fillArray(77, 7);
        r_temp.displayArray();
        Resource r_returned = createAndReturnCopy(r_temp); // r_temp is copied, then returned value is moved
        r_returned.displayArray();
        r_temp.displayArray(); // Original r_temp is unchanged

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }

    std::cout << "\n--- Program Finished ---" << std::endl;
    return 0;
}