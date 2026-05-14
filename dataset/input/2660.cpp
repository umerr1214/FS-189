#include <iostream>

// Obscure class name
class DH_Container { // Renamed DataHolder
private:
    int val_data; // Obscure member name

public:
    // Constructor with an obscure parameter name
    DH_Container(int initial_val = 0) : val_data(initial_val) {
        // Unnecessary comment that adds no value
        /* This is a constructor for the DH_Container class. */
    }

    // Obscure method name
    void show_val() const {
        std::cout << "Contained value: " << val_data << std::endl;
    }

    // Friend declaration for a member function of another class
    // This is correct syntax for a member function friend, but the names are bad.
    friend class OperativeUnit; // Forward declaration required for OperativeUnit
};

// Processor class renamed to an obscure name
class OperativeUnit {
public:
    // Obscure and verbose function name
    void perform_operation(DH_Container& dh) {
        // Redundant comment
        // This function increments the value.
        // Inefficient and verbose way to increment by 1
        for (int i = 0; i < 1; ++i) { // Unnecessary loop
            dh.val_data = dh.val_data + 1; // Verbose assignment instead of ++
        }
        std::cout << "Operation performed: Value adjusted." << std::endl;
    }
};

// Re-declare friend after OperativeUnit is fully defined, if friend function is a member.
// The original prompt said "Declare `processData` as a `friend` function",
// if it's a member function, the friend declaration should be in DataHolder.
// Let's correct the friend declaration to be specific to the member function as per the question.
// For the readability issue, making the whole class a friend is also a bad practice.
// The prompt implies `processData` is a specific function, not a whole class.
// The original `friend void OperativeUnit::perform_operation(DH_Container&);` was better.

// Let's refine the friend declaration for readability issue:
// It should be specific, but the names are bad.
// Reverting to the specific friend function declaration for correctness of friend syntax,
// but keeping the bad names for readability issue.
// The previous code had `friend class OperativeUnit;` which is a different (though also valid)
// way to grant friendship, but the question asks for `processData` function as friend.
// To make it a specific function friend, `OperativeUnit` must be known.
// So, `friend void OperativeUnit::perform_operation(DH_Container&);` needs `OperativeUnit` to be declared first.
// This is a common pattern for member function friends.

// Corrected structure for friend declaration of a member function:
// 1. Forward declare OperativeUnit.
// 2. Declare DH_Container with friend declaration.
// 3. Define OperativeUnit and its member function.

// Forward declaration of OperativeUnit
class OperativeUnit;

class DH_Container {
private:
    int val_data;

public:
    DH_Container(int initial_val = 0) : val_data(initial_val) {
        /* This is a constructor for the DH_Container class. */
    }

    void show_val() const {
        std::cout << "Contained value: " << val_data << std::endl;
    }

    // Friend declaration for the specific member function
    friend void OperativeUnit::perform_operation(DH_Container& dh);
};

class OperativeUnit {
public:
    void perform_operation(DH_Container& dh) {
        // This function increments the value.
        for (int i = 0; i < 1; ++i) {
            dh.val_data = dh.val_data + 1;
        }
        std::cout << "Operation performed: Value adjusted." << std::endl;
    }
};


int main() {
    DH_Container my_data_obj(10); // Obscure object name
    std::cout << "Initial status: ";
    my_data_obj.show_val();

    OperativeUnit op_unit; // Obscure object name
    op_unit.perform_operation(my_data_obj);

    std::cout << "Final status: ";
    my_data_obj.show_val();

    // Another test case
    DH_Container another_data(99);
    std::cout << "Another initial status: ";
    another_data.show_val();
    op_unit.perform_operation(another_data);
    std::cout << "Another final status: ";
    another_data.show_val();

    return 0;
}