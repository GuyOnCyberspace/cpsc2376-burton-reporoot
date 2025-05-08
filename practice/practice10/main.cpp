#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>

// Base class
class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

// Rectangle derived class
class Rectangle : public Shape {
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
};

// Circle derived class
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return M_PI * radius * radius;
    }
};

// Function to print all areas
void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    std::cout << std::fixed << std::setprecision(4);
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->getArea() << std::endl;
    }
}

int main() {
    std::ifstream infile("shapes.txt");
    if (!infile) {
        std::cerr << "Error: Could not open shapes.txt" << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string shapeType;
        iss >> shapeType;

        if (shapeType == "rectangle") {
            double w, h;
            if (iss >> w >> h) {
                shapes.push_back(std::make_unique<Rectangle>(w, h));
            }
        } else if (shapeType == "circle") {
            double r;
            if (iss >> r) {
                shapes.push_back(std::make_unique<Circle>(r));
            }
        }
    }

    printAllAreas(shapes);
    return 0;
}
