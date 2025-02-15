#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const string FILE_NAME = "account_balance.txt";

// Function to read balance from file
double readBalanceFromFile() {
    ifstream file(FILE_NAME);
    double balance;
    if (file) {
        file >> balance;
    } else {
        balance = 100.00; // Initialize with $100 if file does not exist
        ofstream outFile(FILE_NAME);
        outFile << fixed << setprecision(2) << balance;
        outFile.close();
    }
    return balance;
}

// Function to write balance to file
void writeBalanceToFile(double balance) {
    ofstream file(FILE_NAME);
    if (!file) {
        cerr << "Error: Unable to write to file." << endl;
        exit(1);
    }
    file << fixed << setprecision(2) << balance;
}

// Function to display balance
void checkBalance(double balance) {
    cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;
}

// Function to handle deposit
double deposit(double balance) {
    double amount;
    cout << "Enter deposit amount: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Error: Deposit amount must be positive." << endl;
    } else {
        balance += amount;
        writeBalanceToFile(balance);
        cout << "Deposit successful. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
    }
    return balance;
}

// Function to handle withdrawal
double withdraw(double balance) {
    double amount;
    cout << "Enter withdrawal amount: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Error: Withdrawal amount must be positive." << endl;
    } else if (amount > balance) {
        cout << "Error: Insufficient funds. Your balance is $" << fixed << setprecision(2) << balance << "." << endl;
    } else {
        balance -= amount;
        writeBalanceToFile(balance);
        cout << "Withdrawal successful. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
    }
    return balance;
}

int main() {
    double balance = readBalanceFromFile();
    cout << "Welcome to Your Bank Account!" << endl;
    checkBalance(balance);

    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Error: Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = deposit(balance);
                break;
            case 3:
                balance = withdraw(balance);
                break;
            case 4:
                cout << "Thank you for using Your Bank Account. Goodbye!" << endl;
                break;
            default:
                cout << "Error: Invalid choice. Please select a valid option." << endl;
        }
    } while (choice != 4);
    
    return 0;
}
