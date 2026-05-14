#include <iostream>
#include <string> // Unnecessary for this code, but included for 'readability' issue.

// Base class MyClass
class MyClass {
public:
    int mc_p_mem; // Cryptic variable name
protected:
    int mc_prot_mem; // Cryptic variable name
private:
    int mc_priv_mem; // Cryptic variable name

public:
    MyClass(int p1, int p2, int p3) : mc_p_mem(p1), mc_prot_mem(p2), mc_priv_mem(p3) { // Long line, inconsistent spacing
        std::cout << "Base constructor done." << std::endl; // Generic comment, std::endl
    }

    void show_mc_data() { // Cryptic method name, missing const
        std::cout << "  MC Public: " << mc_p_mem << std::endl; // Excessive std::endl
        std::cout << "  MC Private (via getter): " << get_mc_priv() << std::endl; // Excessive std::endl
    }

    int get_mc_priv() { return mc_priv_mem; } // Missing const, long line, cryptic method name
};

// Derived class DerivedClass
class DerivedClass : public MyClass {
public:
    int dc_p_mem; // Cryptic variable name

    DerivedClass(int bp1, int bp2, int bp3, int dp1) : MyClass(bp1, bp2, bp3), dc_p_mem(dp1) { // Long line, inconsistent spacing
        std::cout << "Derived constructor done." << std::endl; // Generic comment, std::endl
    }

    void show_dc_access() { // Cryptic method name, missing const
        std::cout << "\n--- DC Access ---" << std::endl; // Excessive std::endl
        std::cout << "  Can get mc_p_mem: " << mc_p_mem << std::endl; // Excessive std::endl
        std::cout << "  Can get mc_prot_mem: " << mc_prot_mem << std::endl; // Excessive std::endl
        // std::cout << "  Cannot get mc_priv_mem: " << mc_priv_mem << std::endl; // Compile error
        printf("  Cannot directly get mc_priv_mem (compile-time error).\n"); // Mixing printf and cout
        std::cout << "  DC's own public: " << dc_p_mem << std::endl; // Excessive std::endl
    }
};

int main() {
    std::cout << "Readability/Efficiency Issue Example: Access Specifiers\n"; // Missing std::endl here, inconsistent with others

    MyClass mc_obj(11, 22, 33); // Cryptic object name
    std::cout << "\n*** MC Obj Access from main ***\n"; // Inconsistent newlines
    std::cout << "  Public: " << mc_obj.mc_p_mem << std::endl; // Excessive std::endl
    // std::cout << "  Protected: " << mc_obj.mc_prot_mem << std::endl; // Compile error
    printf("  Protected and Private members are inaccessible directly.\n"); // Mixing printf and cout
    // std::cout << "  Private: " << mc_obj.mc_priv_mem << std::endl; // Compile error
    std::cout << "  Private (via getter): " << mc_obj.get_mc_priv() << std::endl; // Excessive std::endl
    mc_obj.show_mc_data(); // Missing const qualifier in method declaration

    DerivedClass dc_obj(111, 222, 333, 444); // Cryptic object name
    dc_obj.show_mc_data(); // Missing const qualifier
    dc_obj.show_dc_access(); // Missing const qualifier

    std::cout << "\n*** DC Obj Access from main ***" << std::endl; // Excessive std::endl
    std::cout << "  Inherited Public: " << dc_obj.mc_p_mem << std::endl; // Excessive std::endl
    std::cout << "  Derived Public: " << dc_obj.dc_p_mem << std::endl; // Excessive std::endl
    // std::cout << "  Inherited Protected: " << dc_obj.mc_prot_mem << std::endl; // Compile error
    printf("  Inherited Protected and Private are inaccessible directly.\n"); // Mixing printf and cout

    return 0;
}