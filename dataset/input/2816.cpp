#include <iostream>
#include <string>
#include <sstream> // For stringstream, demonstrating verbosity

class Engine {
private:
    int power;
    std::string type;

public:
    // Constructor
    Engine(int p, const std::string& t) : power(p), type(t) {
        // A simple constructor, but imagine if it also printed a message,
        // adding to the overall verbosity later.
    }

    // Method to start the engine, prints a message
    void startEngine() {
        std::cout << "--- Engine starting sequence initiated ---" << std::endl;
        std::cout << "Engine Type: " << type << std::endl;
        std::cout << "Engine Power: " << power << " HP" << std::endl;
        std::cout << "Engine components checked. All systems nominal." << std::endl;
        std::cout << "Engine is now running." << std::endl;
        std::cout << "--- Engine starting sequence completed ---" << std::endl;
    }

    // Getters, used redundantly by Car::start()
    int getPower() const { return power; }
    std::string getType() const { return type; }
};

class Car {
private:
    std::string make;
    std::string model;
    Engine carEngine; // Composition

public:
    // Car constructor
    Car(const std::string& mk, const std::string& md, int enginePower, const std::string& engineType)
        : make(mk), model(md), carEngine(enginePower, engineType) {
        // Initializing car and engine
    }

    // Readability / Efficiency Issue: The start() method is overly verbose and duplicates information.
    void start() {
        // Redundant introductory message
        std::cout << "\n<<< Initiating vehicle startup procedure >>>" << std::endl;
        std::cout << "Vehicle: " << make << " " << model << std::endl;
        std::cout << "Checking pre-start conditions..." << std::endl;
        std::cout << "All systems report ready for engine engagement." << std::endl;

        // Calls the engine's startEngine method as required
        carEngine.startEngine();

        // Redundant closing message that repeats engine info
        std::cout << make << " " << model << " has now successfully started." << std::endl;
        // The following lines are redundant as the Engine::startEngine() already provides this detail.
        // It's also inefficient to fetch this information again just for printing.
        std::stringstream ss;
        ss << "Powered by a " << carEngine.getType() << " engine with " << carEngine.getPower() << " horsepower.";
        std::cout << ss.str() << std::endl;
        std::cout << "<<< Vehicle startup procedure concluded >>>" << std::endl;
    }
};

int main() {
    Car myCar("Tesla", "Model 3", 283, "Electric");
    myCar.start();

    std::cout << "\n----------------------------------------\n" << std::endl;

    Car anotherCar("Ford", "Mustang", 450, "V8 Gasoline");
    anotherCar.start();

    return 0;
}