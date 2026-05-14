#include <iostream>
#include <sstream>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    // Semantic Error: operator+ is declared const, but attempts to modify 'this' object,
    // and returns a reference to 'this' instead of a new object.
    ComplexNumber& operator+(const ComplexNumber& other) const {
        // This line would cause a compilation error because 'this' is const in a const member function
        // real += other.real;
        // imaginary += other.imaginary;
        // To make it compile but still demonstrate the semantic issue of modifying 'this' in a const context,
        // and returning a reference to 'this' which is not the standard for binary '+',
        // we'll comment out the direct modification and return a temporary, but the signature itself is problematic.
        // A more direct semantic error for const violation is hard to demonstrate without a mutable member or cast.
        // Let's change the return type to void and try to return *this to force a compilation error.
        // Or, let's keep the return type ComplexNumber& and make it *not* const, but then it's not a semantic error
        // for const-correctness but for expected operator behavior.

        // The semantic error here is that a binary operator+ should return a NEW object by value,
        // not a reference to one of its operands (like *this).
        // If the return type is ComplexNumber&, it implies modification of one of the operands,
        // which is not standard for operator+.
        // Also, attempting to modify 'real' or 'imaginary' here would violate 'const'.
        // Let's make it return a reference to a local or modify 'this' in a const method.

        // This attempts to modify 'this' (implicitly via member access) in a const method, which is a semantic error.
        // The compiler will flag this.
        // real += other.real; // Error: cannot assign to 'this->real' because it is const-qualified
        // imaginary += other.imaginary; // Error: cannot assign to 'this->imaginary' because it is const-qualified

        // To make it compile and still be a semantic error about returning a reference to a temporary,
        // or modifying 'this' with a non-const operator, let's change the return type and remove const.
        // But the prompt wants the *current* operator signature to lead to a semantic error.

        // The most direct semantic error with this signature is trying to modify 'this'.
        // If I make it compile, the semantic error is harder to see.
        // Let's make it try to modify 'this' and cause a compile error due to const-correctness violation.
        // The current implementation attempts to return a reference to *this, but the method is const.
        // This is a semantic violation because a const method should not return a non-const reference to its internal state
        // if that state could then be modified, or because it implies modification in the first place.
        // More directly, if I uncomment the modification lines, it will fail to compile.
        // Let's make the function non-const and return *this, which is a semantic error for operator+ (should return by value).

        // Semantic error: Returning a reference to `*this` from `operator+` which implies modifying `this`
        // or allowing external modification, and is not how binary `+` typically works (should return a new object by value).
        // Even if `this` were not `const`, returning `*this` is generally wrong for `operator+`.
        // The `const` keyword on the method makes it an even stronger semantic violation if modification were attempted.
        // Let's assume the intent was to modify 'this' and return it, which is wrong for binary '+'.
        // Forcing a compile error is better for 'semantic error' if it's a constraint violation.
        // Let's make it return `*this` directly, but the `const` on the method means `*this` is `const ComplexNumber`,
        // and returning `ComplexNumber&` would require a `const_cast` or similar, which is bad practice.
        // The most direct semantic error is trying to modify `this` within a `const` member function.

        // This line will cause a compilation error due to `this` being const.
        // It's a semantic error: trying to modify object state in a const method.
        // This is a clear violation of const-correctness, which is a semantic rule.
        // real = real + other.real;
        // imaginary = imaginary + other.imaginary;
        // return *this;

        // To make it compile and still be a semantic error (returning reference to temporary or wrong behavior)
        // is harder. Let's make it a const-correctness violation that prevents compilation.
        // The return type 'ComplexNumber&' is also semantically problematic for operator+.

        // Let's make the function return `void` and try to return a `ComplexNumber`, which is a type mismatch.
        // That's more of a syntax/type error.

        // Okay, the best semantic error for `const` violation:
        // The method is `const`, but the return type `ComplexNumber&` implies it *could* modify the object
        // if the caller assigned to the result. More directly, if it were to actually modify `this`
        // (which it would if it were `operator+=`), the `const` would be violated.
        // The most straightforward semantic error is trying to return a non-const reference to a temporary or `*this`
        // when the method is `const`.

        // Let's try to return a new ComplexNumber object, but accidentally return a reference to a temporary.
        // This will compile but lead to undefined behavior, which is a semantic error.
        ComplexNumber temp(real + other.real, imaginary + other.imaginary);
        return temp; // Semantic error: Returning a reference to a local variable 'temp'
    }
};

void run_test(double r1, double i1, double r2, double i2) {
    ComplexNumber c1(r1, i1);
    ComplexNumber c2(r2, i2);
    ComplexNumber c3 = c1 + c2; // c3 will reference a destroyed temporary

    std::ostringstream oss;
    // Accessing c3.getReal() and c3.getImaginary() here will be undefined behavior
    // because c3 references a temporary that has been destroyed.
    // However, for test purposes, it might still print some garbage or 0.0,
    // but the error is the return by reference to a local.
    oss << c3.getReal() << " " << c3.getImaginary();
    std::cout << oss.str() << std::endl;
}

int main() {
    run_test(1.0, 2.0, 3.0, 4.0);
    run_test(5.0, -1.0, 2.5, 3.0);
    run_test(-10.0, 0.0, 5.0, -5.0);
    return 0;
}