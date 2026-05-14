#include <iostream>

void swap(int& a, int& b) {
    // This arithmetic swap implementation is not robust.
    // It fails if 'a' and 'b' refer to the same variable (aliasing).
    // For example, if swap(x, x) is called, x will become 0.
    // It also has potential for integer overflow if (a + b) exceeds INT_MAX
    // or falls below INT_MIN, leading to undefined behavior.
    a = a + b;
    b = a - b;
    a = a - b;
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

    int val = 15;
    std::cout << "Initial: val=" << val << std::endl;
    std::cout << "Demonstrating robustness issue with aliasing: swap(val, val)" << std::endl;
    swap(val, val); // This call will incorrectly set val to 0
    std::cout << "After swap(val, val): val=" << val << std::endl << std::endl;

    // Example of potential overflow (though results in UB)
    // int large_a = 2000000000; // Close to INT_MAX
    // int large_b = 2000000000;
    // std::cout << "Initial: large_a=" << large_a << ", large_b=" << large_b << std::endl;
    // swap(large_a, large_b); // a + b would overflow
    // std::cout << "After swap(large_a, large_b): large_a=" << large_a << ", large_b=" << large_b << std::endl << std::endl;

    return 0;
}