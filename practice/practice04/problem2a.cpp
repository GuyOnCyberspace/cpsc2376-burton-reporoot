#include <iostream>
#include <iomanip>

// Template function to perform calculations
template <typename T>
T calculate(T a, T b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : throw std::runtime_error("Division by zero!");
        default: throw std::invalid_argument("Invalid operator");
    }
}

int main() {
    std::cout << "Enter first number: ";
    std::string input1, input2;
    std::cin >> input1;
    
    std::cout << "Enter second number: ";
    std::cin >> input2;
    
    std::cout << "Enter operation (+, -, *, /): ";
    char op;
    std::cin >> op;
    
    // Determine the type based on user input
    if (input1.find('.') != std::string::npos || input2.find('.') != std::string::npos) {
        double num1 = std::stod(input1);
        double num2 = std::stod(input2);
        std::cout << "Result: " << std::fixed << std::setprecision(2) << calculate(num1, num2, op) << "\n";
    } else {
        int num1 = std::stoi(input1);
        int num2 = std::stoi(input2);
        std::cout << "Result: " << calculate(num1, num2, op) << "\n";
    }
    
    return 0;
}
