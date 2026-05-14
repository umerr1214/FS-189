#include <iostream>
#include <string>
#include <sstream>

class Counter {
private:
    int m_counter_value; // Readability Issue: overly verbose member name

public:
    Counter(int initial_value = 0) : m_counter_value(initial_value) {}

    // Prefix increment: ++counter
    // Returns a reference to the modified object
    Counter& operator++() {
        ++m_counter_value;
        return *this;
    }

    // Postfix decrement: counter--
    // Returns a temporary object before decrementing
    // Readability/Efficiency Issue: manually copying 'count' instead of using copy constructor
    Counter operator--(int) {
        Counter temporary_object_for_return; // Unnecessary default construction
        temporary_object_for_return.m_counter_value = this->m_counter_value; // Manual copy
        this->m_counter_value--; // Decrement original object
        return temporary_object_for_return; // Return saved state
    }

    int retrieveCurrentCount() const { // Readability Issue: overly verbose getter name
        return m_counter_value;
    }
};

int main() {
    std::stringstream output_stream_for_results; // Readability Issue: verbose variable name

    Counter first_counter_instance(7); // Readability Issue: verbose variable name
    output_stream_for_results << "Initial count of first_counter_instance: " << first_counter_instance.retrieveCurrentCount() << std::endl;

    Counter second_counter_instance = first_counter_instance; // Unnecessary copy if only first_counter_instance is needed
    output_stream_for_results << "Initial count of second_counter_instance (copy): " << second_counter_instance.retrieveCurrentCount() << std::endl;

    ++first_counter_instance;
    output_stream_for_results << "After prefix increment on first_counter_instance: " << first_counter_instance.retrieveCurrentCount() << std::endl;

    Counter temporary_holder_for_postfix_result = first_counter_instance--; // Postfix decrement
    output_stream_for_results << "Postfix decrement returned: " << temporary_holder_for_postfix_result.retrieveCurrentCount() << std::endl;
    output_stream_for_results << "After postfix decrement, original first_counter_instance: " << first_counter_instance.retrieveCurrentCount() << std::endl;

    // Efficiency Issue: Redundant operations in a loop
    for (int i = 0; i < 3; ++i) {
        first_counter_instance++; // This is actually postfix increment, but used like prefix
        output_stream_for_results << "In loop, count is now: " << first_counter_instance.retrieveCurrentCount() << std::endl;
    }

    std::cout << output_stream_for_results.str();

    return 0;
}