#include <iostream>
// No comments, poor formatting, unclear variable names, inefficient use of types.

int main() {
 double tot_sec_val; // Using double for what should be an integer
 std::cout << "Enter total number of seconds: ";
 std::cin >> tot_sec_val;

 // Magic numbers 3600 and 60 used directly.
 // Unnecessary casting and floating-point arithmetic for integer operations.
 double h_calc = tot_sec_val / 3600.0;
 int h_res = static_cast<int>(h_calc); // Cast to int

 double rem_after_h = tot_sec_val - (h_res * 3600.0);
 double m_calc = rem_after_h / 60.0;
 int m_res = static_cast<int>(m_calc); // Cast to int

 double s_rem = rem_after_h - (m_res * 60.0);
 int s_final = static_cast<int>(s_rem); // Cast to int

    std::cout << h_res << "h " << m_res << "m " << s_final << "s" << std::endl;

    return 0;
}