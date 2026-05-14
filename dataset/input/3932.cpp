#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse

// Function to reverse the digits of an integer.
// This version uses string conversion, which is generally less efficient
// than direct arithmetic operations for integer reversal.
// It also uses slightly less descriptive variable names, impacting readability.
int reverseNumber(int n_input) { // Poor variable name
    if (n_input == 0) {
        return 0;
    }

    std::string s_val = std::to_string(n_input); // Convert int to string (less efficient)
    bool neg_flag = false; // Poor variable name
    if (s_val[0] == '-') {
        neg_flag = true;
        s_val.erase(0, 1); // Remove the negative sign for reversal
    }

    std::reverse(s_val.begin(), s_val.end()); // Reverse the string

    // Note: std::stoi will throw std::out_of_range if the reversed string
    // represents a number outside the range of 'int'. For the purpose of
    // demonstrating efficiency/readability issues, we assume valid inputs
    // that don't cause `stoi` to throw.
    int final_res = std::stoi(s_val); // Convert string back to int (less efficient)

    if (neg_flag) {
        return -final_res;
    } else {
        return final_res;
    }
}

int main() {
    int usr_in; // Poor variable name
    // For automated testing, input is read from stdin without a prompt.
    std::cin >> usr_in;
    int rev_out = reverseNumber(usr_in); // Poor variable name
    std::cout << rev_out << std::endl;
    return 0;
}