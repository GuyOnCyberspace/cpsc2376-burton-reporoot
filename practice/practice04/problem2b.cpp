#include <iostream>
#include <string>

// Template function to find the maximum of three values
template <typename T>
T findMax(T a, T b, T c) {
    return std::max(std::max(a, b), c);
}

int main() {
    int choice;
    std::cout << "Compare (1) Numbers or (2) Strings? ";
    std::cin >> choice;
    std::cin.ignore(); // Ignore newline left in buffer
    
    if (choice == 1) {
        double num1, num2, num3;
        std::cout << "Enter first value: ";
        std::cin >> num1;
        std::cout << "Enter second value: ";
        std::cin >> num2;
        std::cout << "Enter third value: ";
        std::cin >> num3;
        std::cout << "Max value: " << findMax(num1, num2, num3) << "\n";
    } else if (choice == 2) {
        std::string str1, str2, str3;
        std::cout << "Enter first value: ";
        std::getline(std::cin, str1);
        std::cout << "Enter second value: ";
        std::getline(std::cin, str2);
        std::cout << "Enter third value: ";
        std::getline(std::cin, str3);
        std::cout << "Max value: " << findMax(str1, str2, str3) << "\n";
    } else {
        std::cout << "Invalid choice!\n";
    }
    
    return 0;
}
