#include <iostream>
#include <chrono>
#include <thread>
#include <string>

class Timer {
private:
    std::chrono::high_resolution_clock::time_point _startTime;
    std::chrono::nanoseconds _totalElapsedDuration;
    bool _isRunning;

public:
    Timer() : _totalElapsedDuration(0), _isRunning(false) {}

    // SEMANTIC ERROR: Returning Timer by value instead of Timer&
    // This breaks method chaining as operations will be performed on temporary copies.
    Timer start() { // Should be Timer& start()
        if (!_isRunning) {
            _startTime = std::chrono::high_resolution_clock::now();
            _isRunning = true;
        }
        return *this; // Returns a copy
    }

    // SEMANTIC ERROR: Returning Timer by value instead of Timer&
    Timer stop() { // Should be Timer& stop()
        if (_isRunning) {
            _totalElapsedDuration += std::chrono::high_resolution_clock::now() - _startTime;
            _isRunning = false;
        }
        return *this; // Returns a copy
    }

    // SEMANTIC ERROR: Returning Timer by value instead of Timer&
    Timer reset() { // Should be Timer& reset()
        _totalElapsedDuration = std::chrono::nanoseconds(0);
        _isRunning = false;
        return *this; // Returns a copy
    }

    long long getElapsedTimeMs() const {
        std::chrono::nanoseconds currentDuration = _totalElapsedDuration;
        if (_isRunning) {
            currentDuration += std::chrono::high_resolution_clock::now() - _startTime;
        }
        return std::chrono::duration_cast<std::chrono::milliseconds>(currentDuration).count();
    }
};

int main() {
    Timer timer;
    std::cout << "Initial time: " << timer.getElapsedTimeMs() << "ms\n"; // Expected: 0

    // Test 1: Basic start/stop (works as no chaining is involved)
    timer.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    timer.stop();
    std::cout << "After 100ms run: " << timer.getElapsedTimeMs() << "ms\n"; // Expected: ~100. Actual: ~100.

    // Test 2: Reset and run again (works as no chaining is involved)
    timer.reset().start();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    timer.stop();
    std::cout << "After reset and 50ms run: " << timer.getElapsedTimeMs() << "ms\n"; // Expected: ~50. Actual: ~50.

    // Test 3: Chaining - this will expose the semantic error.
    // The chained calls (reset, start, stop) will operate on temporary copies,
    // not the original 'timer' object.
    Timer timer_chain_test;
    timer_chain_test.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(75));
    timer_chain_test.stop(); // Original timer_chain_test now has ~75ms accumulated.
    
    // This chain operates on a copy of 'timer_chain_test', then a copy of that copy, etc.
    // The original 'timer_chain_test' object is NOT reset, started, or stopped by this chain.
    timer_chain_test.reset().start().stop(); 
    std::cout << "Timer (after chained reset().start().stop()): " << timer_chain_test.getElapsedTimeMs() << "ms\n"; // Expected: ~0 (if chain worked). Actual: ~75 (original timer state unchanged).

    // Test 4: Another chaining scenario
    Timer timer2;
    timer2.start(); // timer2 starts
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    // The stop() call returns a copy. The reset() call operates on that copy.
    // The original timer2 is still running and not reset.
    timer2.stop().reset(); 
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // timer2 continues running
    // Calling getElapsedTimeMs() on the original timer2
    std::cout << "Timer2 after stop().reset() (expected ~50 if reset, actual ~100 if not): " << timer2.getElapsedTimeMs() << "ms\n"; // Expected: ~50 (if reset worked). Actual: ~100.

    return 0;
}