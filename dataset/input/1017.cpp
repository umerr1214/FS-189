#include <iostream>
#include <string>
#include <cstring> // For strlen, strcpy

// Base class
class Shape {
public:
    Shape() { std::cout << "Shape constructor called.\n"; }
    virtual ~Shape() { std::cout << "Shape destructor called.\n"; } // Correctly virtual

    virtual void draw() const { std::cout << "Drawing a generic shape.\n"; }
};

// Derived class
class Circle : public Shape {
private:
    std::string name;
    char* description; // Dynamically allocated member
public:
    Circle(const std::string& n = "Default Circle", const char* desc = "A round object") : name(n) {
        std::cout << "Circle constructor called (" << name << ").\n";
        description = new char[strlen(desc) + 1];
        strcpy(description, desc);
    }

    // Semantic Error: Forgetting to delete[] 'description' in the destructor
    ~Circle() override {
        std::cout << "Circle destructor called (" << name << ") - Description: " << description << ".\n";
        // delete[] description; // This line is intentionally missing for the semantic error (memory leak)
    }

    void draw() const override { std::cout << "Drawing a circle named " << name << " with description: " << description << ".\n"; }
};

int main() {
    std::cout << "--- Demonstrating problem (non-virtual destructor) ---\n";
    // To demonstrate the problem, we temporarily use a non-virtual destructor setup
    // This is a common pattern to show 'before' and 'after' in a single file
    class NonVirtualShape {
    public:
        NonVirtualShape() { std::cout << "NonVirtualShape constructor called.\n"; }
        ~NonVirtualShape() { std::cout << "NonVirtualShape destructor called.\n"; } // Non-virtual
        virtual void draw() const { std::cout << "Drawing a non-virtual shape.\n"; }
    };

    class NonVirtualCircle : public NonVirtualShape {
    private:
        std::string nv_name;
    public:
        NonVirtualCircle(const std::string& n = "NV Circle") : nv_name(n) { std::cout << "NonVirtualCircle constructor called (" << nv_name << ").\n"; }
        ~NonVirtualCircle() { std::cout << "NonVirtualCircle destructor called (" << nv_name << ").\n"; }
        void draw() const override { std::cout << "Drawing a non-virtual circle named " << nv_name << ".\n"; }
    };

    NonVirtualShape* nvs = new NonVirtualCircle("Partial Destruction Example");
    nvs->draw();
    delete nvs; // Only NonVirtualShape destructor called, NonVirtualCircle's is skipped
    std::cout << "--- End of problem demonstration ---\n";

    std::cout << "\n--- Demonstrating fix (virtual destructor) ---\n";
    // The base class 'Shape' has a virtual destructor.
    // The derived class 'Circle' has a semantic error (memory leak of 'description').
    Shape* s_fixed = new Circle("Correctly Deleted Circle", "It's a sphere on a 2D plane.");
    s_fixed->draw();
    delete s_fixed; // Both Circle and Shape destructors will be called due to virtual destructor.
                    // However, the 'description' member of Circle will not be freed, leading to a memory leak.
    std::cout << "--- End of fix demonstration (with semantic error) ---\n";

    // To prevent a real memory leak in the test environment (if applicable) and for comparison,
    // let's create a temporary scope to show the fix without the semantic error.
    std::cout << "\n--- Demonstrating fix (virtual destructor) without semantic error (for comparison) ---\n";
    class FixedCircle : public Shape {
    private:
        std::string name;
        char* description_fixed;
    public:
        FixedCircle(const std::string& n = "Truly Fixed Circle", const char* desc = "Perfectly round") : name(n) {
            std::cout << "FixedCircle constructor called (" << name << ").\n";
            description_fixed = new char[strlen(desc) + 1];
            strcpy(description_fixed, desc);
        }
        ~FixedCircle() override {
            std::cout << "FixedCircle destructor called (" << name << ") - Description: " << description_fixed << ".\n";
            delete[] description_fixed; // Correctly freeing memory
        }
        void draw() const override { std::cout << "Drawing a fixed circle named " << name << " with description: " << description_fixed << ".\n"; }
    };
    Shape* s_truly_fixed = new FixedCircle("Truly Fixed Example", "No leaks here!");
    s_truly_fixed->draw();
    delete s_truly_fixed;
    std::cout << "--- End of truly fixed demonstration ---\n";

    return 0;
}