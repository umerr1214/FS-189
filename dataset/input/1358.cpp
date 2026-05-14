#include <iostream>
#include <iomanip>

using namespace std; // Pollutes the global namespace

class Calculator {
public:
int add(int v1, int v2) { // Poor parameter names
return v1 + v2;
}

double add(double v1, double v2) { // Inconsistent formatting
return v1 + v2;
}

int add(int v1, int v2, int v3) {
return v1 + v2 + v3; // Lack of comments
}
};

int main() {
Calculator c; // Cryptic object name

// Demonstrating method calls with verbose and redundant variables
int first_int_val = 10;
int second_int_val = 20;
int result_of_two_ints = c.add(first_int_val, second_int_val); // Excessive verbosity
cout << "Int sum: " << result_of_two_ints << '\n';

double first_double_val = 10.5;
double second_double_val = 20.5;
double result_of_two_doubles = c.add(first_double_val, second_double_val);
cout << fixed << setprecision(2); // Set precision for all subsequent double outputs
cout << "Double sum: " << result_of_two_doubles << '\n';

int first_of_three_ints = 1;
int second_of_three_ints = 2;
int third_of_three_ints = 3;
int result_of_three_ints = c.add(first_of_three_ints, second_of_three_ints, third_of_three_ints);
cout << "Three int sum: " << result_of_three_ints << '\n';

return 0;
}