#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

using namespace std;

// Function to get user input for a fraction
Fraction getFractionInput() {
    int num, den;
    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> den;

    try {
        return Fraction(num, den);
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << ". Please enter a valid fraction.\n";
        return getFractionInput(); // Retry input
    }
}

int main() {
    Fraction currentFraction(0, 1); // Initially 0/1
    int choice;

    do {
        // Display current fraction
        cout << "\nCurrent Fraction: " << currentFraction << endl;
        cout << "Options:\n";
        cout << "1. Enter a fraction manually\n";
        cout << "2. Add a fraction\n";
        cout << "3. Subtract a fraction\n";
        cout << "4. Multiply by a fraction\n";
        cout << "5. Divide by a fraction\n";
        cout << "6. Display as Mixed Fraction\n";
        cout << "7. Clear Fraction\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                currentFraction = getFractionInput();
                break;
            }
            case 2: {
                Fraction other = getFractionInput();
                currentFraction = currentFraction + other;
                break;
            }
            case 3: {
                Fraction other = getFractionInput();
                currentFraction = currentFraction - other;
                break;
            }
            case 4: {
                Fraction other = getFractionInput();
                currentFraction = currentFraction * other;
                break;
            }
            case 5: {
                Fraction other = getFractionInput();
                try {
                    currentFraction = currentFraction / other;
                } catch (const invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 6: {
                MixedFraction mixed(currentFraction);
                cout << "Mixed Fraction: " << mixed << endl;
                break;
            }
            case 7: {
                currentFraction = Fraction(0, 1);
                cout << "Fraction reset to 0/1.\n";
                break;
            }
            case 8:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 8);

    return 0;
}
