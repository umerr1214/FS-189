#include <iostream>
#include <cmath> // For sqrt

class Point {
private:
    int x;
    int y;

public:
    void setCoordinates(int _x, int _y) {
        x = _x;
        y = _y;
    }

    // Semantic error: getDistanceToOrigin returns an int, truncating the double result of sqrt.
    // Euclidean distance is typically a double, losing precision when cast to int.
    int getDistanceToOrigin() {
        return static_cast<int>(std::sqrt(x * x + y * y)); // Implicit cast from double to int, truncating
    }
};

int main() {
    Point p1;
    p1.setCoordinates(3, 4);
    std::cout << "Distance for (3,4): " << p1.getDistanceToOrigin() << std::endl;

    Point p2;
    p2.setCoordinates(1, 1);
    std::cout << "Distance for (1,1): " << p2.getDistanceToOrigin() << std::endl;

    return 0;
}