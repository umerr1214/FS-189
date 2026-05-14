#include <iostream>

class Vector2D {
private:
    double x;
    double y;

public:
    // Constructor
    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Getters for components (const-correct)
    double getX() const { return x; }
    double getY() const { return y; }

    // Overload the + operator as a member function (const-correct)
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(this->x + other.x, this->y + other.y);
    }

    // Method to print the vector (const-correct)
    void print() const {
        std::cout.precision(2);
        std::cout << std::fixed << x << " " << y << std::endl;
    }
};

int main() {
    double x1, y1, x2, y2;

    // Read first vector components
    if (!(std::cin >> x1 >> y1)) {
        return 1; // Input error
    }
    Vector2D v1(x1, y1);

    // Read second vector components
    if (!(std::cin >> x2 >> y2)) {
        return 1; // Input error
    }
    Vector2D v2(x2, y2);

    // Perform vector addition using the overloaded operator
    Vector2D v3 = v1 + v2;

    // Print the resulting vector
    v3.print();

    return 0;
}