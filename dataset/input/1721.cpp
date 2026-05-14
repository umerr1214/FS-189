#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Base Logger class
class Logger {
public:
    virtual void log(std::string message) = 0;
    virtual ~Logger() {}
};

// Derived ConsoleLogger class
class ConsoleLogger : public Logger {
public:
    void log(std::string message) override {
        std::cout << "Console Log: " << message << std::endl;
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
            // LOGICAL ERROR: Always writes a fixed message instead of the input 'message'
            file << "File Log: This is a fixed log message." << std::endl; 
            file.close();
        } else {
            std::cerr << "Error: Unable to open file " << filename << std::endl;
        }
    }
};