#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    double _b; // Readability Issue: Poor naming for balance

public:
    BankAccount(double initial = 0.0) {
        _b = initial;
    }

    bool deposit(double amt) { // Readability Issue: Poor parameter name. Efficiency Issue: Returns bool but often ignored.
        if (amt > 0.0) {
            _b = _b + amt;
            return true;
        } else {
            // No specific message for invalid deposit amount
            return false;
        }
    }

    bool withdraw(double w_amt) { // Readability Issue: Poor parameter name. Efficiency Issue: Returns bool but often ignored.
        if (w_amt > 0.0) {
            if (_b >= w_amt) { // Correct overdraft check
                _b = _b - w_amt;
                return true;
            } else {
                // No specific message for overdraft
                return false;
            }
        } else {
            return false;
        }
    }

    double getBalance() { // Readability Issue: Missing const-correctness
        return _b;
    }
};

int main() {
    // This main function is just a placeholder for compilation.
    // The actual test driver is in the JSON file.
    BankAccount account(0.0);
    account.deposit(100.0);
    account.withdraw(50.0);
    std::cout << std::fixed << std::setprecision(2) << account.getBalance() << std::endl;
    return 0;
}