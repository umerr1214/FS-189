#include <iostream>
#include <chrono>
#include <thread> // For std::this_thread::sleep_for

// Readability / Efficiency Issue:
// 1. Uses `long long` to store time points and durations as milliseconds,
//    requiring frequent manual conversions using `std::chrono::duration_cast`.
//    This is less type-safe, less readable, and potentially less efficient
//    than directly using `std::chrono::time_point` and `std::chrono::duration` objects.
// 2. Variable names like `_sT`, `_aD`, `_rF` are overly abbreviated and reduce readability.
// 3. The logic, while functionally correct, is more verbose due to manual millisecond handling.
class Timer {
private:
    long long _sT; // Stores start time in milliseconds since epoch
    long long _aD; // Stores accumulated duration in milliseconds
    bool _rF;      // Running Flag

public:
    Timer() : _sT(0), _aD(0), _rF(false) {}

    Timer& start() {
        if (!_rF) {
            _sT = std::chrono::duration_cast<std::chrono::milliseconds>(
                      std::chrono::steady_clock::now().time_since_epoch()
                  ).count();
            _rF = true;
        }
        return *this;
    }

    Timer& stop() {
        if (_rF) {
            long long currentTimeMs = std::chrono::duration_cast<std::chrono::milliseconds>(
                                          std::chrono::steady_clock::now().time_since_epoch()
                                      ).count();
            _aD += (currentTimeMs - _sT);
            _rF = false;
        }
        return *this;
    }

    Timer& reset() {
        _aD = 0;
        _rF = false;
        _sT = 0; // Reset start time too, though not strictly necessary if _rF is false
        return *this;
    }

    long long getElapsedTime() const {
        long long currentTotalMs = _aD;
        if (_rF) {
            long long currentTimeMs = std::chrono::duration_cast<std::chrono::milliseconds>(
                                          std::chrono::steady_clock::now().time_since_epoch()
                                      ).count();
            currentTotalMs += (currentTimeMs - _sT);
        }
        return currentTotalMs;
    }
};

int main() {
    Timer t;
    std::cout << "Timer created.\n";

    t.start();
    std::cout << "Timer started. Current elapsed: " << t.getElapsedTime() << " ms\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "After 100ms. Current elapsed: " << t.getElapsedTime() << " ms\n";
    t.stop();
    std::cout << "Timer stopped. Total elapsed: " << t.getElapsedTime() << " ms\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "After 50ms. Total elapsed (should be same): " << t.getElapsedTime() << " ms\n";

    t.reset();
    std::cout << "Timer reset. Total elapsed: " << t.getElapsedTime() << " ms\n";

    // Chaining example
    t.start().reset().stop();
    std::cout << "Chaining start().reset().stop(). Total elapsed: " << t.getElapsedTime() << " ms\n";

    t.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    t.stop();
    std::cout << "Timer started for 200ms. Total elapsed: " << t.getElapsedTime() << " ms\n";

    t.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Timer started for 50ms. Current elapsed: " << t.getElapsedTime() << " ms\n";
    t.stop();
    std::cout << "Timer stopped. Total elapsed: " << t.getElapsedTime() << " ms\n";

    return 0;
}