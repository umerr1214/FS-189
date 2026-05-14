#include <iostream>
#include <string>

class Vector2D {
public:
    double x;
    double y;

    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Overload the + operator with a SEMANTIC ERROR
    // Returns a reference to a local temporary object, leading to a dangling reference.
    Vector2D& operator+(const Vector2D& other) const { // Should return Vector2D by value
        Vector2D result(x + other.x, y + other.y);
        return result; // Returning a reference to a local variable 'result'
                       // 'result' is destroyed when the function returns,
                       // making the returned reference dangling.
    }
};

void printVector(const Vector2D& v, const std::string& name) {
    std::cout << name << " = (" << v.x << ", " << v.y << ")" << std::endl;
}

int main() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);
    // This line involves the semantic error. v3 will be initialized with a dangling reference.
    Vector2D v3 = v1 + v2;
    printVector(v3, "v3"); // Output will be undefined due to dangling reference

    Vector2D v4(-0.5, 10.0);
    Vector2D v5(1.5, -3.0);
    Vector2D v6 = v4 + v5;
    printVector(v6, "v6"); // Output will be undefined due to dangling reference

    return 0;
}