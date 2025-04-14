#include <iostream>
#include <string>

int main() {
    float redPotion{0.0f};
    float bluePotion{0.0f};
    float* flask{nullptr};

    std::string choice;

    while (true) {
        std::cout << "Which potion to add liquid to? (Red / Blue / Done): ";
        std::cin >> choice;

        if (choice == "Done" || choice == "done") {
            break;
        }

        if (choice == "Red" || choice == "red") {
            flask = &redPotion;
        } else if (choice == "Blue" || choice == "blue") {
            flask = &bluePotion;
        } else {
            std::cout << "Invalid potion type. Try again.\n";
            continue;
        }

        float amount;
        std::cout << "How many milliliters to add? ";
        std::cin >> amount;

        if (amount < 0) {
            std::cout << "Cannot add a negative amount.\n";
            continue;
        }

        *flask += amount;

        std::cout << "Red Potion: " << redPotion << " mL\n";
        std::cout << "Blue Potion: " << bluePotion << " mL\n";
    }

    std::cout << "Potion brewing complete!\n";
    return 0;
}
