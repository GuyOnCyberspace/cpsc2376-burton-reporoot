#include <iostream>
#include <string>

// Function to generate a greeting
void greet(std::string name = "Guest", std::string prefix = "Hello") {
    std::cout << prefix << ", " << name << "!\n";
}

int main() {
    int choice;
    std::string name, prefix;
    
    std::cout << "1. Default Greeting\n";
    std::cout << "2. Greet by Name\n";
    std::cout << "3. Custom Greeting\n";
    std::cout << "Choose an option: ";
    std::cin >> choice;
    std::cin.ignore(); // Ignore newline left in buffer
    
    switch (choice) {
        case 1:
            greet();
            break;
        case 2:
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            greet(name);
            break;
        case 3:
            std::cout << "Enter greeting prefix: ";
            std::getline(std::cin, prefix);
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            greet(name, prefix);
            break;
        default:
            std::cout << "Invalid choice!\n";
    }
    
    return 0;
}
