#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr
#include <cmath> // Not strictly needed, but common for math ops

// Abstract base class with a poor name
class S {
public:
    // Pure virtual method with a poor name
    virtual double cA() const = 0;
    virtual ~S() = default;
};

// Derived class Circle with a poor name
class C : public S {
private:
    double r_; // Poor variable name
public:
    C(double r) : r_(r) {}

    // Implements calculateArea with a poor name
    double cA() const override {
        double p = 3.14159; // Magic number for PI, defined locally and not a constant
        return p * r_ * r_;
    }
};

// Derived class Rectangle with a poor name
class R : public S {
private:
    double w_; // Poor variable name
    double h_; // Poor variable name
public:
    R(double w, double h) : w_(w), h_(h) {}

    // Implements calculateArea with a poor name
    double cA() const override {
        return w_ * h_;
    }
};

int main() {
    std::vector<std::unique_ptr<S>> v; // Poor variable name for vector of shapes

    v.push_back(std::make_unique<C>(5.0));
    v.push_back(std::make_unique<R>(4.0, 6.0));
    v.push_back(std::make_unique<C>(0.0));
    v.push_back(std::make_unique<R>(10.0, 0.0));

    for (const auto& s : v) { // Poor loop variable name
        std::cout << "Area: " << s->cA() << std::endl;
    }

    return 0;
}