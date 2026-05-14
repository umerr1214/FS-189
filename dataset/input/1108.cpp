#include <iostream>
#include <string>
#include <vector>

// Abstract base class
class Printable {
public:
    virtual void print() const = 0;
    virtual ~Printable() = default;
};

// Concrete class Document
class Document : public Printable {
private:
    std::string title;
public:
    Document(const std::string& t) : title(t) {}
    void print() const override {
        std::cout << "Printing Document: " << title << std::endl;
    }
};

// Concrete class Image - SYNTAX ERROR: Missing semicolon after class definition
class Image : public Printable {
private:
    std::string filename;
public:
    Image(const std::string& fn) : filename(fn) {}
    void print() const override {
        std::cout << "Printing Image: " << filename << std::endl;
    }
} // ERROR: Missing semicolon here

int main() {
    Document doc("Meeting Minutes");
    Image img("sunset.jpg");

    doc.print();
    img.print();

    std::vector<Printable*> items;
    items.push_back(new Document("Project Proposal"));
    items.push_back(new Image("mountains.png"));

    for (const auto& item : items) {
        item->print();
    }

    for (const auto& item : items) {
        delete item;
    }

    return 0;
}