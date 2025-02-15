#include <iostream>
#include <vector>

// Function prototypes
void printVector(const std::vector<int>& vec);
void doubleVector(std::vector<int>& vec);
int calculateSum(const std::vector<int>& vec);
void printMultiples(const std::vector<int>& vec, int value);

int main() {
    std::vector<int> vec;
    int choice, num;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add an item to the vector\n";
        std::cout << "2. Print the vector\n";
        std::cout << "3. Double the vector\n";
        std::cout << "4. Find the sum of the vector\n";
        std::cout << "5. Print multiples of a value\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter a number to add: ";
                std::cin >> num;
                vec.push_back(num);
                break;
            case 2:
                printVector(vec);
                break;
            case 3:
                doubleVector(vec);
                std::cout << "Vector doubled!\n";
                break;
            case 4:
                std::cout << "Sum of the vector: " << calculateSum(vec) << "\n";
                break;
            case 5:
                std::cout << "Enter a number to find multiples of: ";
                std::cin >> num;
                printMultiples(vec, num);
                break;
            case 6:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

// Function definitions

// Function to print all elements of the vector
void printVector(const std::vector<int>& vec) {
    std::cout << "Vector elements: ";
    for (const int& element : vec) {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

// Function to double the values in the vector
void doubleVector(std::vector<int>& vec) {
    for (int& element : vec) {
        element *= 2;
    }
}

// Function to calculate the sum of the vector elements
int calculateSum(const std::vector<int>& vec) {
    int sum = 0;
    for (const int& element : vec) {
        sum += element;
    }
    return sum;
}

// Function to print elements of the vector that are multiples of a given number
void printMultiples(const std::vector<int>& vec, int value) {
    std::cout << "Multiples of " << value << ": ";
    bool found = false;
    for (const int& element : vec) {
        if (element % value == 0) {
            std::cout << element << " ";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No multiples found.\n";
    } else {
        std::cout << "\n";
    }
}
