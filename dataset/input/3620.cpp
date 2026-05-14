#include <iostream>

void swap(int& a, int& b) {
    // This is an XOR swap. It avoids a temporary variable (sometimes perceived as an efficiency gain)
    // and is robust to aliasing (a == b). However, it is generally considered less readable and
    // harder to understand than using a temporary variable.
    // Modern compilers often optimize the temporary variable approach equally well or better,
    // making the 'efficiency' gain negligible or even a detriment in some architectures.
    a ^= b;
    b ^= a;
    a ^= b;
}

int main() {
    int x = 5, y = 10;
    std::cout << "Initial: x=" << x << ", y=" << y << std::endl;
    swap(x, y);
    std::cout << "After swap(x, y): x=" << x << ", y=" << y << std::endl << std::endl;

    int p = -3, q = -7;
    std::cout << "Initial: p=" << p << ", q=" << q << std::endl;
    swap(p, q);
    std::cout << "After swap(p, q): p=" << p << ", q=" << q << std::endl << std::endl;

    int m = 20, n = -5;
    std::cout << "Initial: m=" << m << ", n=" << n << std::endl;
    swap(m, n);
    std::cout << "After swap(m, n): m=" << m << ", n=" << n << std::endl << std::endl;

    int r = 0, s = 8;
    std::cout << "Initial: r=" << r << ", s=" << s << std::endl;
    swap(r, s);
    std::cout << "After swap(r, s): r=" << r << ", s=" << s << std::endl << std::endl;

    int val = 7;
    std::cout << "Initial: val=" << val << std::endl;
    std::cout << "Testing with aliasing: swap(val, val)" << std::endl;
    swap(val, val); // XOR swap handles aliasing correctly (value remains unchanged)
    std::cout << "After swap(val, val): val=" << val << std::endl << std::endl;

    return 0;
}