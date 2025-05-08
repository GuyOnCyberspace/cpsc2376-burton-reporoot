#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <sstream>

// Abstract Shape Class
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual method
    virtual ~Shape() = default;
};

// Circle class
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

// Square class
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

// Rectangle class
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

// ShapeFactory to create shapes based on the type
class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& shapeType, std::vector<double> dimensions) {
        if (shapeType == "circle" && dimensions.size() == 1) {
            return std::make_unique<Circle>(dimensions[0]);
        } else if (shapeType == "square" && dimensions.size() == 1) {
            return std::make_unique<Square>(dimensions[0]);
        } else if (shapeType == "rectangle" && dimensions.size() == 2) {
            return std::make_unique<Rectangle>(dimensions[0], dimensions[1]);
        } else {
            return nullptr;  // Invalid shape or dimensions
        }
    }
};

int main() {
    std::ifstream file("shapes.txt");
    std::string line;
    double totalArea = 0;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string shapeType;
        ss >> shapeType;

        std::vector<double> dimensions;
        double dimension;
        while (ss >> dimension) {
            dimensions.push_back(dimension);
        }

        auto shape = ShapeFactory::createShape(shapeType, dimensions);
        if (shape) {
            totalArea += shape->area();
        }
    }

    std::cout << "Total Area of all Shapes: " << totalArea << std::endl;
    return 0;
}
