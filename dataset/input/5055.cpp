#include <iostream>
#include <limits>    // For std::numeric_limits
#include <string>
#include <sstream>
#include <iomanip>   // For std::fixed, std::setprecision
#include <cmath>     // For std::abs, std::fabs
#include <type_traits> // For std::is_integral_v, etc.

// Correct, robust, and readable function template:
// Uses std::abs from <cmath>, which is overloaded for various numeric types
// and handles edge cases like INT_MIN correctly and efficiently.
template <typename T>
T getAbsoluteValue(T val) {
    return std::abs(val);
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