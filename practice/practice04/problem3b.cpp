#include <iostream>
#include <deque>
#include <string>

void showContent(const std::deque<std::string>& edits) {
    if (edits.empty()) {
        std::cout << "Content is empty.\n";
    } else {
        for (const auto& edit : edits) {
            std::cout << edit << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::deque<std::string> edits;
    int choice;
    
    do {
        std::cout << "\n1. Add Text\n";
        std::cout << "2. Undo Last Edit\n";
        std::cout << "3. Show Content\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline left in buffer
        
        if (choice == 1) {
            std::string text;
            std::cout << "Enter text: ";
            std::getline(std::cin, text);
            edits.push_back(text);
        } else if (choice == 2) {
            if (!edits.empty()) {
                edits.pop_back();
                std::cout << "Undo successful!\n";
            } else {
                std::cout << "Nothing to undo!\n";
            }
        } else if (choice == 3) {
            showContent(edits);
        } else if (choice != 4) {
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    
    return 0;
}
