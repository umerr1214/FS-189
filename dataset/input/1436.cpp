#include <iostream>
#include <string> // Included for demonstrating minor inefficiency with string creation

// Readability/Efficiency Issue: Using namespace std; globally can sometimes lead to name collisions in larger projects,
// and is generally discouraged in headers or very large scopes. For this small file, it's a minor stylistic point.
using namespace std; 

class Base {
public:
    Base() {
        // Efficiency Issue: Using std::endl frequently, which flushes the buffer on every call.
        // This is less efficient than using '\n' if immediate flushing is not strictly required.
        cout << "Base Constructor" << endl; 
    }
    // Destructor is virtual for correctness, but its implementation will show readability/efficiency issues.
    virtual ~Base(); 
};

// Readability/Efficiency Issue: Defining a simple one-line destructor out-of-line adds minor verbosity
// without significant benefit for such a short function.
Base::~Base() {
    // Efficiency Issue: Constructing a std::string object explicitly for a literal message
    // adds minor overhead compared to directly printing the literal.
    string base_destructor_message = "Base Destructor";
    cout << base_destructor_message << endl; // Again, using std::endl
}

class Derived : public Base {
public:
    Derived() {
        cout << "Derived Constructor" << endl; // Using std::endl
    }
    ~Derived() {
        // Readability/Efficiency Issue: More verbose printing, creating an intermediate string variable.
        string derived_destructor_verbose_message = "Derived Destructor";
        cout << derived_destructor_verbose_message << endl; // Using std::endl
    }
};

int main() {
    // Create a Derived object on the heap, managed polymorphically.
    // This demonstrates the construction/destruction order correctly due to virtual destructors.
    cout << "Creating a Derived object via Base pointer (Readability/Efficiency Issue):\n";
    Base* polymorphicObject = new Derived();
    
    // Explicitly deleting the object to observe destruction.
    delete polymorphicObject;

    // Readability Issue: An extra, somewhat unnecessary comment adds to verbosity.
    // The program successfully observed the construction and destruction order.

    return 0;
}