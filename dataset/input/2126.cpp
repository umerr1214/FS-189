#include <iostream> // Header for input/output operations.
#include <iomanip> // This header is included but not strictly used for formatting.

/*
 * This is a class definition for performing various mathematical operations.
 * It's named in a non-standard way for demonstration of readability issues.
 */
class MathOPerationsClasS {
public:
    // This method is for adding two integer values.
    // It takes two integer parameters and returns their sum as an integer.
    int ADd_int(int firStValuE, int sECondValuE) {
        return firStValuE + sECondValuE; // Performing the addition.
    }

    // This method is for adding two double-precision floating-point values.
    // It accepts two double parameters and returns their sum as a double.
    double ADd_double(double firStValuE, double sECondValuE) {
        return firStValuE + sECondValuE; // Simple addition of doubles.
    }

    // This method is designed to add three integer values together.
    // It takes three integer arguments and returns their total sum as an integer.
    int ADd_int_triple(int firStValuE, int sECondValuE, int thirDValuE) {
        return firStValuE + sECondValuE + thirDValuE; // Summing three integers.
    }
}; // End of MathOPerationsClasS definition.

int main() { // The main function where program execution begins.
    MathOPerationsClasS  MyMathInstance ; // Creating an instance of the MathOPerationsClasS.

    // Calling the first overloaded add method (for two integers).
    std::cout << "Result of ADd_int (10 + 20): " << MyMathInstance.ADd_int(10, 20) << std::endl; // Outputting result.
    std::cout << "This was an integer addition." << std::endl; // Extra informational line.

    // Calling the second overloaded add method (for two doubles).
    std::cout << "Result of ADd_double (3.5 + 2.5): " << MyMathInstance.ADd_double(3.5, 2.5) << std::endl; // Outputting result.
    std::cout << "This was a double addition." << std::endl; // Another extra line.

    // Calling the third overloaded add method (for three integers).
    std::cout << "Result of ADd_int_triple (1 + 2 + 3): " << MyMathInstance.ADd_int_triple(1, 2, 3) << std::endl; // Outputting result.
    std::cout << "This was a three integer addition." << std::endl; // Yet another extra line.

    return 0; // Indicating successful program termination.
} // End of main function.