#include <iostream>

using namespace std; // Readability issue: polluting global namespace

class Base {
public:
    void show(int x) { // Poor parameter name
        cout << "Base::show(int) called. Value: " << x << endl; // Excessive use of endl
    }
};

class Derived : public Base {
public:
    // This hides Base::show(int)
    void show(int y) { // Poor parameter name
        cout << "Derived::show(int) called. Value: " << y << endl;
    }

    // This overloads show
    void show(double z) { // Poor parameter name
        cout << "Derived::show(double) called. Value: " << z << endl;
    }
};

int main() {
    cout << "--- Hiding and Overloading Demo (Readability/Efficiency Issue) ---" << endl; // Verbose intro and excessive endl

    Base b_obj_one; // Inconsistent variable naming style
    Derived d_obj_two; // Inconsistent variable naming style

    // Base object calls
    cout << "\nBase obj calls:" << endl;
    b_obj_one.show(11); // Lack of specific comments explaining the call's outcome

    // Derived object calls
    cout << "\nDerived obj calls:" << endl;
    d_obj_two.show(22); // Hiding scenario, but not clearly explained
    d_obj_two.show(22.5); // Overloading scenario, not clearly explained
    d_obj_two.Base::show(23); // Explicit call to hidden base method, but output is not distinct enough

    // Pointers
    Base* ptr1 = &b_obj_one; // Generic pointer names
    Derived* ptr2 = &d_obj_two;
    Base* ptr3 = &d_obj_two; // Base pointer to Derived object

    cout << "\nPointers:" << endl;
    ptr1->show(33); // Base ptr to Base obj
    ptr2->show(44); // Derived ptr to Derived obj (int)
    ptr2->show(44.5); // Derived ptr to Derived obj (double)
    ptr3->show(55); // Base ptr to Derived obj (hiding effect)

    cout << "\n--- End of Demo ---" << endl;
    cout << "This code demonstrates method hiding and overloading but has several readability issues:" << endl;
    cout << "- Uses 'using namespace std;' which is generally discouraged in production code." << endl;
    cout << "- Inconsistent and uninformative variable names (e.g., b_obj_one, d_obj_two, ptr1, ptr2, ptr3)." << endl;
    cout << "- Poor parameter names (x, y, z) in 'show' methods." << endl;
    cout << "- Overly verbose output statements using 'endl' instead of '\\n', potentially impacting efficiency." << endl;
    cout << "- Lack of specific comments or distinct output messages explaining *why* certain methods are called in each scenario, making it hard to follow the demonstration of hiding vs. overloading." << endl;

    return 0;
}