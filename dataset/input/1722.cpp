#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Base Logger class
class Logger {
public:
    virtual void log(std::string message) = 0;
    // SEMANTIC ERROR: Missing virtual destructor.
    // If derived objects are deleted via a base class pointer,
    // the derived class destructor will not be called, leading to resource leaks.
    // The correct implementation should be 'virtual ~Logger() {}'.
    ~Logger() {} // Non-virtual destructor
};

// Derived ConsoleLogger class
class ConsoleLogger : public Logger {
public:
    void log(std::string message) override {
        std::cout << "Console Log: " << message << std::endl;
    }
    ~ConsoleLogger() {
        // In a real scenario, this would be called if Logger had a virtual destructor.
        // std::cout << "ConsoleLogger destructor called." << std::endl; 
    }
};

// Derived FileLogger class
class FileLogger : public Logger {
private:
    std::string filename;
public:
    FileLogger(std::string fname) : filename(fname) {}

    void log(std::string message) override {
        std::ofstream file(filename, std::ios::app); // Append mode
        if (file.is_open()) {
            file << "File Log: " << message << std::endl;
            file.close();
        } else {
            std::cerr << "Error: Unable to open file " << filename << std::endl;
        }
    }

    ~FileLogger() {
        // This destructor will NOT be called if a FileLogger object is deleted
        // via a Logger* pointer due to the missing 'virtual' keyword in Logger's destructor.
        // std::cout << "FileLogger destructor called." << std::endl;
    }
};