#include <iostream>
#include <memory> // For std::unique_ptr, demonstrating modern C++ practices

// --- Scenario 1: Non-virtual destructor (Illustrates Memory Leak) ---
// This set of classes demonstrates the problem.
class BaseNonVirtual {
public:
    BaseNonVirtual() {
        std::cout << "  BaseNonVirtual constructor called.\n";
    }
    // NON-VIRTUAL destructor - This is the cause of the memory leak.
    ~BaseNonVirtual() {
        std::cout << "  BaseNonVirtual destructor called.\n";
    }
    // A virtual function to show that polymorphism works for other methods.
    virtual void displayInfo() const {
        std::cout << "  BaseNonVirtual information.\n";
    }
};

class DerivedLeak : public BaseNonVirtual {
private:
    int* m_leakData;
    static const int LEAK_DATA_SIZE = 1000; // Allocating 1000 ints, 4000 bytes

public:
    DerivedLeak() : m_leakData(new int[LEAK_DATA_SIZE]) {
        std::cout << "  DerivedLeak constructor called. Allocated " << LEAK_DATA_SIZE * sizeof(int) << " bytes.\n";
        for (int i = 0; i < LEAK_DATA_SIZE; ++i) {
            m_leakData[i] = i; // Initialize data
        }
    }
    // This destructor will NOT be called if an object is deleted via a BaseNonVirtual* pointer.
    ~DerivedLeak() override { // 'override' is good practice, but this destructor won't be polymorphically invoked.
        std::cout << "  DerivedLeak destructor called. Deallocating m_leakData.\n";
        delete[] m_leakData;
        m_leakData = nullptr;
    }
    void displayInfo() const override {
        std::cout << "  DerivedLeak information. First data element: " << m_leakData[0] << ".\n";
    }
};

// --- Scenario 2: Virtual destructor (Correct Cleanup) ---
// This set of classes demonstrates the solution.
class BaseVirtual {
public:
    BaseVirtual() {
        std::cout << "  BaseVirtual constructor called.\n";
    }
    // VIRTUAL destructor - Ensures DerivedCorrect's destructor is called when deleting through a base pointer.
    virtual ~BaseVirtual() {
        std::cout << "  BaseVirtual destructor called.\n";
    }
    virtual void displayInfo() const {
        std::cout << "  BaseVirtual information.\n";
    }
};

class DerivedCorrect : public BaseVirtual {
private:
    double* m_correctData;
    static const int CORRECT_DATA_SIZE = 500; // Allocating 500 doubles, 4000 bytes

public:
    DerivedCorrect() : m_correctData(new double[CORRECT_DATA_SIZE]) {
        std::cout << "  DerivedCorrect constructor called. Allocated " << CORRECT_DATA_SIZE * sizeof(double) << " bytes.\n";
        for (int i = 0; i < CORRECT_DATA_SIZE; ++i) {
            m_correctData[i] = static_cast<double>(i) / 2.0; // Initialize data
        }
    }
    // This destructor WILL be called due to the virtual destructor in BaseVirtual.
    ~DerivedCorrect() override {
        std::cout << "  DerivedCorrect destructor called. Deallocating m_correctData.\n";
        delete[] m_correctData;
        m_correctData = nullptr;
    }
    void displayInfo() const override {
        std::cout << "  DerivedCorrect information. First data element: " << m_correctData[0] << ".\n";
    }
};


int main() {
    std::cout << "--- Demonstration of Virtual Destructor Necessity ---\n\n";

    // Scenario 1: Non-virtual destructor leading to memory leak
    std::cout << "Scenario 1: Using BaseNonVirtual (non-virtual destructor)\n";
    BaseNonVirtual* leakPtr = new DerivedLeak(); // Create DerivedLeak object, pointed to by BaseNonVirtual*
    leakPtr->displayInfo(); // Polymorphism works for virtual methods
    std::cout << "  Deleting BaseNonVirtual pointer...\n";
    delete leakPtr; // This calls BaseNonVirtual::~BaseNonVirtual(), NOT DerivedLeak::~DerivedLeak()
    leakPtr = nullptr; // Good practice to nullify pointer after delete
    std::cout << "  RESULT: DerivedLeak's destructor was NOT called. Memory leak occurred.\n";
    std::cout << "  " << LEAK_DATA_SIZE * sizeof(int) << " bytes were leaked.\n\n";

    // Scenario 2: Virtual destructor for correct cleanup
    std::cout << "Scenario 2: Using BaseVirtual (virtual destructor)\n";
    // Using std::unique_ptr for robust, modern C++ memory management.
    // std::unique_ptr automatically calls delete on its managed raw pointer when it goes out of scope.
    std::unique_ptr<BaseVirtual> correctPtr = std::make_unique<DerivedCorrect>(); // Create DerivedCorrect object, managed by unique_ptr
    correctPtr->displayInfo(); // Polymorphism works as expected
    
    std::cout << "  unique_ptr going out of scope, deleting BaseVirtual pointer...\n";
    // When correctPtr goes out of scope, it calls delete on its raw pointer.
    // Because BaseVirtual's destructor is virtual, DerivedCorrect's destructor will be called first, then BaseVirtual's.
    // No explicit delete is needed here for unique_ptr.
    // The scope ends at the return 0; statement, triggering destruction.
    std::cout << "  RESULT: DerivedCorrect's destructor WAS called. All resources freed correctly.\n";
    std::cout << "  " << CORRECT_DATA_SIZE * sizeof(double) << " bytes were correctly deallocated.\n\n";

    std::cout << "--- End of Demonstration ---\n";

    return 0; // unique_ptr `correctPtr` is destroyed here, triggering correct cleanup.
}