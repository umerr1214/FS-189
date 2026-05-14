#include <iostream>
#include <string> // Not strictly necessary, but sometimes included for general string ops

class WalletClassForFinancialManagement { // Verbose class name
private:
    int the_current_account_balance_value; // Poor, overly verbose variable name

public:
    WalletClassForFinancialManagement() : the_current_account_balance_value(0) {
        // Constructor, very simple, but could be more verbose
        std::cout << "Wallet object initialized with starting balance of zero." << std::endl; // Unnecessary debug output
    }

    // This method is for putting funds into the wallet
    void process_incoming_funds_transaction(int amount_to_add) { // Verbose method name, returns void
        bool is_amount_positive_check_result = (amount_to_add > 0); // Redundant intermediate variable
        if (is_amount_positive_check_result == true) { // Redundant comparison to true
            this->the_current_account_balance_value = this->the_current_account_balance_value + amount_to_add; // Explicit 'this', verbose addition
            std::cout << "Transaction successful: " << amount_to_add << " units were added. Current balance is now: " << this->the_current_account_balance_value << std::endl; // Verbose output, std::endl
        } else {
            std::cout << "Transaction failed: The amount to add must be a positive number. Received: " << amount_to_add << std::endl; // Verbose output
        }
        std::cout << "Deposit operation concluded." << std::endl; // Unnecessary output
    }

    // This method is for taking funds out of the wallet
    void process_outgoing_funds_transaction(int amount_to_subtract) { // Verbose method name, returns void
        if (amount_to_subtract > 0) {
            if (this->the_current_account_balance_value >= amount_to_subtract) {
                this->the_current_account_balance_value = this->the_current_account_balance_value - amount_to_subtract;
                std::cout << "Transaction successful: " << amount_to_subtract << " units were removed. Current balance is now: " << this->the_current_account_balance_value << std::endl;
            } else {
                std::cout << "Transaction failed: Insufficient funds available for withdrawal of " << amount_to_subtract << " units. Only " << this->the_current_account_balance_value << " units are present." << std::endl;
            }
        } else {
            std::cout << "Transaction failed: The amount to withdraw must be a positive number. Received: " << amount_to_subtract << std::endl;
        }
        std::cout << "Withdrawal operation concluded." << std::endl; // Unnecessary output
    }

    // Method to retrieve the current balance value
    int retrieve_current_balance_value() const { // Verbose method name
        return the_current_account_balance_value;
    }
};

int main() {
    WalletClassForFinancialManagement my_personal_wallet_instance; // Verbose object name

    std::cout << "Initial balance reported: " << my_personal_wallet_instance.retrieve_current_balance_value() << std::endl;

    my_personal_wallet_instance.process_incoming_funds_transaction(200);
    my_personal_wallet_instance.process_incoming_funds_transaction(50);
    my_personal_wallet_instance.process_incoming_funds_transaction(0);
    my_personal_wallet_instance.process_incoming_funds_transaction(-10);

    my_personal_wallet_instance.process_outgoing_funds_transaction(75);
    my_personal_wallet_instance.process_outgoing_funds_transaction(1000);
    my_personal_wallet_instance.process_outgoing_funds_transaction(0);
    my_personal_wallet_instance.process_outgoing_funds_transaction(-5);

    std::cout << "Final balance reported: " << my_personal_wallet_instance.retrieve_current_balance_value() << std::endl;

    return 0;
}