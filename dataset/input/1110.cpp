#include <iostream>
#include <string>
#include <vector>

// Abstract base class
class Printable {
public:
    virtual void print() const = 0;
    virtual ~Printable() = default;
};

// Concrete class Document - SEMANTIC ERROR: Does not override print(), making it abstract
class Document : public Printable {
private:
    std::string title;
public:
    Document(const std::string& t) : title(t) {}
    // The print() method is missing, making Document an abstract class
    // void print() const override {
    //     std::cout << "Printing Document: " << title << std::endl;
    // }
};

// Concrete class Image
class Image : public Printable {
private:
    std::string filename;
public:
    Image(const std::string& fn) : filename(fn) {}
    void print() const override {
        std::cout << "Printing Image: " << filename << std::endl;
    }
};

int main() {
    // Semantic error: Cannot instantiate an abstract class 'Document'
    Document doc("Meeting Minutes"); // This line will cause a compile-time semantic error

    Image img("sunset.jpg");

    // The following lines would also cause issues if compilation passed,
    // as doc is of an abstract type.
    // doc.print();
    img.print();

    std::vector<Printable*> items;
    // items.push_back(new Document("Project Proposal")); // Would also cause a semantic error
    items.push_back(new Image("mountains.png"));

    for (const auto& item : items) {
        item->print();
    }

    for (const auto& item : items) {
        delete item;
    }

    return 0;
}