#include <iostream>

class Base {
public:
    void show(int val) {
        std::cout << "Base::show(int): " << val << std::endl;
    }
};

class Derived : public Base {
public:
    void show(double val) {
        std::cout << "Derived::show(double): " << val << std::endl;
    }

    void show(int val) { // Non-virtual, hides Base::show(int)
        std::cout << "Derived::show(int): " << val << std::endl;
    }
};

int main() {
    Base b;
    Derived d;

    Base* b_ptr = &d; // Base pointer to Derived object
    Derived* d_ptr = &d; // Derived pointer to Derived object

    std::cout << "--- Calling with Base object ---" << std::endl;
    b.show(10); // Calls Base::show(int)

    std::cout << "\n--- Calling with Derived object ---" << std::endl;
    d.show(20);    // Calls Derived::show(int)
    d.show(30.5);  // Calls Derived::show(double)
    d.Base::show(40); // Explicitly call hidden Base::show(int)

    std::cout << "\n--- Calling with Base pointer to Derived object ---" << std::endl;
    b_ptr->show(50); // Calls Base::show(int) due to static binding (method hiding)
    b_ptr->show(60.5); // Semantic Error: Base class has no 'show(double)' method.
                       // The compiler will look for show(double) in Base, not Derived,
                       // because b_ptr is of type Base*.

    std::cout << "\n--- Calling with Derived pointer to Derived object ---" << std::endl;
    d_ptr->show(70);    // Calls Derived::show(int)
    d_ptr->show(80.5);  // Calls Derived::show(double)
    d_ptr->Base::show(90); // Explicitly call hidden Base::show(int)

    return 0;
}