#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Required for std::fixed and std::setprecision operations

class BankAccount
{
    private:
        // Member variable to store the unique identification number for the bank account
        std::string m_account_identification_number_string;
        // Member variable to store the full name of the primary owner of this bank account
        std::string m_account_holder_full_name_string;
        // Member variable to store the current monetary balance of the bank account in double precision floating point format
        double m_current_account_balance_value_double;

    public:
        // Public constructor method for initializing a new BankAccount object instance
        BankAccount(std::string p_account_number_param, std::string p_owner_name_param, double p_initial_balance_param)
        : m_account_identification_number_string(p_account_number_param),
          m_account_holder_full_name_string(p_owner_name_param),
          m_current_account_balance_value_double(p_initial_balance_param)
        {
            // This is a constructor. It initializes the private members using an initializer list.
            // A check is performed to ensure the starting balance is not below zero.
            if (this->m_current_account_balance_value_double < 0.0) {
                this->m_current_account_balance_value_double = 0.0; // Set to zero if negative
            }
        }

        // Public method to facilitate the deposit of monetary funds into the account
        void deposit(double p_deposit_amount_to_add_double)
        {
            // It is important to ensure that the amount being deposited is a positive value.
            if (p_deposit_amount_to_add_double > 0.0)
            {
                // If the amount is positive, the current balance is incremented by the deposit amount.
                this->m_current_account_balance_value_double = this->m_current_account_balance_value_double + p_deposit_amount_to_add_double;
            }
            else
            {
                // If the deposit amount is not positive, no action is taken. This else block is for clarity.
                // No error is reported, the operation simply does not proceed.
            }
        }

        // Public method to facilitate the withdrawal of monetary funds from the account
        void withdraw(double p_withdrawal_amount_to_subtract_double)
        {
            // The first condition checks if the requested withdrawal amount is a positive number.
            if (p_withdrawal_amount_to_subtract_double > 0.0)
            {
                // The second condition checks if performing the withdrawal would result in a negative balance.
                if ((this->m_current_account_balance_value_double - p_withdrawal_amount_to_subtract_double) >= 0.0)
                {
                    // If both conditions are met, the withdrawal is processed by decrementing the balance.
                    this->m_current_account_balance_value_double = this->m_current_account_balance_value_double - p_withdrawal_amount_to_subtract_double;
                }
                else
                {
                    // This else block handles cases where there are insufficient funds.
                    // No action is taken and no error is explicitly returned.
                }
            }
            else
            {
                // This else block handles cases where the withdrawal amount is not positive.
                // Again, no action is taken and no error is explicitly returned.
            }
        }

        // Public constant method to retrieve the current balance of the bank account
        double getBalance() const
        {
            // This method simply returns the stored value of the current account balance.
            return m_current_account_balance_value_double;
        }
};

int main() {
    BankAccount myAccountObject("987654321", "Jane Smith", 500.0);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Initial account balance: $" << myAccountObject.getBalance() << std::endl;

    myAccountObject.deposit(150.0);
    std::cout << "Balance after depositing $150.00: $" << myAccountObject.getBalance() << std::endl;

    myAccountObject.withdraw(200.0);
    std::cout << "Balance after withdrawing $200.00: $" << myAccountObject.getBalance() << std::endl;

    myAccountObject.deposit(0.0); // Should do nothing
    std::cout << "Balance after depositing $0.00: $" << myAccountObject.getBalance() << std::endl;

    myAccountObject.withdraw(-50.0); // Should do nothing
    std::cout << "Balance after withdrawing $-50.00: $" << myAccountObject.getBalance() << std::endl;

    myAccountObject.withdraw(1000.0); // Attempt to overdraw
    std::cout << "Balance after attempting to withdraw $1000.00: $" << myAccountObject.getBalance() << std::endl;

    myAccountObject.withdraw(50.0);
    std::cout << "Balance after withdrawing $50.00: $" << myAccountObject.getBalance() << std::endl;

    return 0;
}