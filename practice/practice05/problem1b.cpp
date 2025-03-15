#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int num;

    std::cout << "Enter integers (type '0' to end):\n";
    while (std::cin >> num && num != 0) {
        numbers.push_back(num);
    }

    // Printing the numbers in reverse order using iterators
    std::cout << "Numbers in reverse order: ";
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
