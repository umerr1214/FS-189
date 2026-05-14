#include <iostream>
#include <limits>    // For std::numeric_limits
#include <string>
#include <sstream>
#include <iomanip>   // For std::fixed, std::setprecision
#include <cmath>     // For std::fabs (used in helper, not in getAbsoluteValue itself)
#include <type_traits> // For std::is_integral_v, etc.

// Function template with a robustness issue:
// For the smallest negative integer (e.g., INT_MIN), negating it results in overflow,
// leading to undefined behavior or an incorrect positive value (often the original negative value itself on 2's complement systems).
template <typename T>
T getAbsoluteValue(T val) {
    if (val < static_cast<T>(0)) {
        return -val; // Robustness issue: Potential overflow for INT_MIN, LLONG_MIN
    }
    return val;
}

// Helper to format numeric values to string for consistent output
template <typename T>
std::string format_output(T value) {
    std::ostringstream oss;
    if constexpr (std::is_integral_v<T>) {
        oss << value;
    } else { // floating point
        // Use scientific notation for very large/small numbers to maintain precision
        if (std::fabs(value) >= 1e15 || (std::fabs(value) > 0 && std::fabs(value) < 1e-6)) {
            oss << std::scientific << std::setprecision(std::numeric_limits<T>::max_digits10 - 1) << value;
        } else {
            oss << std::fixed << std::setprecision(std::numeric_limits<T>::max_digits10 - 1) << value;
        }
    }
    std::string s = oss.str();
    // Remove trailing zeros and decimal point if it's an integer-like float
    if (s.find('.') != std::string::npos) {
        s.erase(s.find_last_not_of('0') + 1, std::string::npos);
        if (s.back() == '.') {
            s.pop_back();
        }
    }
    return s;
}

int main() {
    std::cout << "[";

    bool first_item = true;

    // Test int
    int i_vals[] = {5, -10, 0, std::numeric_limits<int>::max(), std::numeric_limits<int>::min()};
    for (size_t i = 0; i < sizeof(i_vals)/sizeof(i_vals[0]); ++i) {
        if (!first_item) std::cout << ",";
        std::cout << "\"" << format_output(getAbsoluteValue(i_vals[i])) << "\"";
        first_item = false;
    }

    // Test float
    float f_vals[] = {3.14f, -2.5f, 0.0f, std::numeric_limits<float>::max()};
    for (size_t i = 0; i < sizeof(f_vals)/sizeof(f_vals[0]); ++i) {
        if (!first_item) std::cout << ",";
        std::cout << "\"" << format_output(getAbsoluteValue(f_vals[i])) << "\"";
        first_item = false;
    }

    // Test double
    double d_vals[] = {123.456, -98.765, 0.0, std::numeric_limits<double>::max()};
    for (size_t i = 0; i < sizeof(d_vals)/sizeof(d_vals[0]); ++i) {
        if (!first_item) std::cout << ",";
        std::cout << "\"" << format_output(getAbsoluteValue(d_vals[i])) << "\"";
        first_item = false;
    }

    // Test long long
    long long ll_vals[] = {10000000000LL, -20000000000LL, 0LL, std::numeric_limits<long long>::max(), std::numeric_limits<long long>::min()};
    for (size_t i = 0; i < sizeof(ll_vals)/sizeof(ll_vals[0]); ++i) {
        if (!first_item) std::cout << ",";
        std::cout << "\"" << format_output(getAbsoluteValue(ll_vals[i])) << "\"";
        first_item = false;
    }

    std::cout << "]";

    return 0;
}