#include <iostream>
#include <vector> // Using vector for a slightly different resource allocation

// Base class with a VIRTUAL destructor (correctness is present)
class A_Base_Class_Entity { // Unclear and overly verbose class name
public:
    A_Base_Class_Entity() {
        std::cout << "  A_Base_Class_Entity::constructor has been invoked.\n";
    }
    // Virtual destructor - technically correct, no leak here
    virtual ~A_Base_Class_Entity() {
        std::cout << "  A_Base_Class_Entity::destructor has been invoked.\n";
    }
    virtual void process_data() const {
        std::cout << "  A_Base_Class_Entity processing some generic data.\n";
    }
};

// Derived class
class X_Derived_Class_Object : public A_Base_Class_Entity { // Unclear and overly verbose class name
private:
    std::vector<int>* v_data_ptr; // Using raw pointer to std::vector, which is unnecessarily complex and less safe than std::vector<int> v_data;
    static const int VEC_SIZE = 50000; // Moderate size, still correct

public:
    X_Derived_Class_Object() : v_data_ptr(new std::vector<int>(VEC_SIZE)) {
        std::cout << "    X_Derived_Class_Object::constructor has been invoked. "
                  << "Allocated a std::vector of size " << VEC_SIZE << " on heap via raw pointer.\n";
        // Initialize vector (optional, for demo)
        for (int i = 0; i < VEC_SIZE; ++i) {
            (*v_data_ptr)[i] = i;
        }
    }

    ~X_Derived_Class_Object() override { // Using 'override' is good practice, but overall code style is messy
        std::cout << "    X_Derived_Class_Object::destructor has been invoked. "
                  << "Deallocating std::vector pointed to by v_data_ptr.\n";
        delete v_data_ptr;
        v_data_ptr = nullptr;
    }

    void process_data() const override {
        std::cout << "    X_Derived_Class_Object processing specific data, first element: " << (*v_data_ptr)[0] << ".\n";
    }
};

// A helper function that adds unnecessary complexity for a simple concept demonstration
void execute_cleanup_cycle(int cycle_identifier) {
    std::cout << "\n--- Execution Cycle Number " << cycle_identifier << " Initiated ---\n";
    A_Base_Class_Entity* temp_base_pointer = new X_Derived_Class_Object(); // Unclear variable name
    temp_base_pointer->process_data();
    std::cout << "  Commencing object deletion sequence for temp_base_pointer...\n";
    delete temp_base_pointer;
    temp_base_pointer = nullptr;
    std::cout << "  Object deletion sequence for cycle " << cycle_identifier << " Concluded.\n";
}

int main() {
    std::cout << "Program Start: Demonstrating virtual destructor necessity with readability/efficiency issues.\n";

    // Unnecessary loop for demonstration; makes output verbose and somewhat inefficient for a single concept demo
    for (int i = 0; i < 3; ++i) {
        execute_cleanup_cycle(i + 1);
    }

    std::cout << "\nProgram End: All allocated objects have been correctly processed and deallocated.\n";
    std::cout << "Observation: The code functions correctly, but its structure and naming conventions introduce readability and minor efficiency concerns.\n";

    return 0;
}