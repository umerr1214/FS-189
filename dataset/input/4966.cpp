#include <iostream>
#include <cmath>

void normalizeAngle(double& angle) {
    angle = fmod(angle, 360.0);
    if (angle < 0) {
        angle += 360.0;
    }
}

int main() {
    double a = 400.0;
    normalizeAngle(a);
    std::cout << a << std::endl // Missing semicolon here
    return 0;
}