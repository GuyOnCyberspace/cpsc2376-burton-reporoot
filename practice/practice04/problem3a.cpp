#include <iostream>
#include <list>
#include <string>

void showTasks(const std::list<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
    } else {
        int index = 1;
        for (const auto& task : tasks) {
            std::cout << index++ << ". " << task << "\n";
        }
    }
}

int main() {
    std::list<std::string> tasks;
    int choice;
    
    do {
        std::cout << "\n1. Add Task\n";
        std::cout << "2. Remove Task\n";
        std::cout << "3. Show Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline left in buffer
        
        if (choice == 1) {
            std::string task;
            std::cout << "Enter task: ";
            std::getline(std::cin, task);
            tasks.push_back(task);
            std::cout << "Task added!\n";
        } else if (choice == 2) {
            int taskNum;
            showTasks(tasks);
            if (!tasks.empty()) {
                std::cout << "Enter task number to remove: ";
                std::cin >> taskNum;
                std::cin.ignore();
                if (taskNum > 0 && taskNum <= tasks.size()) {
                    auto it = tasks.begin();
                    std::advance(it, taskNum - 1);
                    tasks.erase(it);
                    std::cout << "Task removed!\n";
                } else {
                    std::cout << "Invalid task number!\n";
                }
            }
        } else if (choice == 3) {
            showTasks(tasks);
        } else if (choice != 4) {
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    
    return 0;
}
