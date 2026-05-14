#include <iostream>
#include <string>
#include <iomanip>

class BankAcc { // Readability Issue: Obscure class name
private:
    double _bal; // Readability Issue: Obscure variable name for balance

public:
    BankAcc(double initial_amount = 0.0) : _bal(initial_amount) {}

    void depo(double val_to_add) { // Readability Issue: Obscure method and parameter names
        // Readability Issue: Inconsistent formatting, unnecessary 'else if' for zero check
        if (val_to_add < 0) {
            std::cout << "Error: Cannot deposit negative value." << std::endl;
            return;
        } else if (val_to_add == 0) { // Readability Issue: This check could be combined with the main 'if' or handled more concisely
            std::cout << "Info: Depositing zero amount, no change." << std::endl;
            return;
        }
        _bal += val_to_add;
        std::cout << "Deposit processed." << std::endl;
    }

    void withd(double amt_to_sub) { // Readability Issue: Obscure method and parameter names
        // Readability Issue: Poor formatting, conditional statements on one line
        if (amt_to_sub < 0) { std::cout << "Error: Cannot withdraw negative value." << std::endl; return; }
        if (amt_to_sub == 0) { // Readability Issue: This check could be combined with the main 'if' or handled more concisely
            std::cout << "Info: Withdrawing zero amount, no change." << std::endl;
            return;
        }
        if (_bal >= amt_to_sub) { _bal -= amt_to_sub; std::cout << "Withdrawal processed." << std::endl; }
        else { std::cout << "Error: Insufficient funds." << std::endl; }
    }

    double get_current_balance() const { // Readability Issue: Obscure method name
        return _bal;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed << std::setprecision(2);

    BankAcc my_account(100.0); // Readability Issue: Obscure object name
    std::cout << "Initial balance: " << my_account.get_current_balance() << std::endl;

    std::cout << "\n--- Deposit Tests ---" << std::endl;
    std::cout << "Depositing 50.0..." << std::endl;
    my_account.depo(50.0);
    std::cout << "Current balance: " << my_account.get_current_balance() << std::endl;

    std::cout << "Attempting to deposit -20.0..." << std::endl;
    my_account.depo(-20.0);
    std::cout << "Current balance: " << my_account.get_current_balance() << std::endl;

    std::cout << "Attempting to deposit 0.0..." << std::endl;
    my_account.depo(0.0);
    std::cout << "Current balance: " << my_account.get_current_balance() << std::endl;

    std::cout << "\n--- Withdraw Tests ---" << std::endl;
    std::cout << "Withdrawing 30.0..." << std::endl;
    my_account.withd(30.0);
    std::cout << "Current balance: " << my_account.get_current_balance() << std::endl;

    std::cout << "Attempting to withdraw 150.0 (overdraft)..." << std::endl;
    my_account.withd(150.0);
    std::cout << "Current balance: " << my_account.get_current_balance() << std::endl;

    std::cout << "Attempting to withdraw -10.0..." << std::endl;
    my_account.withd(-10.0);
    std::cout << "Current balance: " << my_account.get_current_balance() << std::endl;

    std::cout << "Attempting to withdraw 0.0..." << std::endl;
    my_account.withd(0.0);
    std::cout << "Current balance: " << my_account.get_current_balance() << std::endl;

    std::cout << "Withdrawing 120.0 (to zero)..." << std::endl;
    my_account.withd(120.0);
    std::cout << "Current balance: " << my_account.get_current_balance() << std::endl;

    std::cout << "Attempting to withdraw 1.0 from zero..." << std::endl;
    my_account.withd(1.0);
    std::cout << "Current balance: " << my_account.get_current_balance() << std::endl;

    std::cout << "\nFinal balance: " << my_account.get_current_balance() << std::endl;

    return 0;
}