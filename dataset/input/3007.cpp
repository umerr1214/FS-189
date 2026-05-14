#include <iostream>
#include <numeric> // For std::iota in fillArray (though not used in final version)

class Resource {
private:
    int* m_array;
    int m_size;

public:
    // Constructor
    Resource(int size) : m_size(size), m_array(nullptr) {
        if (m_size <= 0) {
            std::cout << "Warning: Array size must be positive. Setting size to 1." << std::endl;
            m_size = 1; // Default to 1 to avoid nullptr dereference in methods
        }
        m_array = new int[m_size];
        std::cout << "Resource created with size " << m_size << ". Memory allocated at " << static_cast<void*>(m_array) << std::endl;
    }

    // Destructor
    ~Resource() {
        if (m_array) { 
            std::cout << "Resource of size " << m_size << " at " << static_cast<void*>(m_array) << " being destroyed. Memory deallocated." << std::endl;
            delete[] m_array;
            m_array = nullptr; // Good practice to nullify after delete
            m_size = 0;
        } else {
            std::cout << "Resource destructor called, but m_array was already null or never allocated." << std::endl;
        }
    }

    // fillArray method
    void fillArray() {
        if (!m_array) {
            std::cout << "Error: Array not allocated. Cannot fill." << std::endl;
            return;
        }
        // Fill with simple sequence 0, 1, 2, ...
        for (int i = 0; i < m_size; ++i) {
            m_array[i] = i;
        }
        std::cout << "Array filled with sequence." << std::endl;
    }

    // displayArray method
    void displayArray() const {
        if (!m_array) {
            std::cout << "Error: Array not allocated. Cannot display." << std::endl;
            return;
        }
        std::cout << "Array contents (" << m_size << " elements): [";
        for (int i = 0; i < m_size; ++i) {
            std::cout << m_array[i] << (i == m_size - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }

    // Public getter for m_array (for demonstration of shallow copy effect)
    // In a real class, direct access like this would typically be avoided.
    int* getArrayPointerForDemo() { return m_array; }
};

void demonstrateResourceCopy() {
    std::cout << "\n--- Demonstrating Robustness Issue (Shallow Copy) ---" << std::endl;
    Resource original(3); // Resource 1
    original.fillArray();
    original.displayArray();

    std::cout << "Creating a copy 'copied' from 'original'..." << std::endl;
    Resource copied = original; // Default copy constructor (shallow copy)
    copied.displayArray();

    std::cout << "Modifying 'copied' array..." << std::endl;
    // This will modify the same underlying memory as 'original' due to shallow copy
    if (copied.getArrayPointerForDemo()) { 
        copied.getArrayPointerForDemo()[0] = 99;
    }
    copied.displayArray();
    original.displayArray(); // Shows 'original' also changed

    std::cout << "Exiting demonstrateResourceCopy function scope." << std::endl;
    // When 'copied' goes out of scope, its destructor is called, freeing the memory.
    // When 'original' goes out of scope, its destructor is called, attempting to free the SAME memory again (double-free).
} // Destructors for 'copied' and 'original' are called here.

int main() {
    std::cout << "Starting program..." << std::endl;

    // Basic usage (works fine)
    Resource r1(5);
    r1.fillArray();
    r1.displayArray();

    // Demonstrate the robustness issue
    demonstrateResourceCopy();

    std::cout << "Program finished. Expecting potential crash due to double-free." << std::endl;
    return 0;
}