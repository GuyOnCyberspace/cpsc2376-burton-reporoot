#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int num;
    
    std::cout << "Enter integers (type '0' to end):\n";
    while (std::cin >> num && num != 0) {
        numbers.push_back(num);
    }
    
    // Printing the numbers using iterators
    std::cout << "Numbers entered: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Summing only even numbers using an iterator
    int even_sum = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it % 2 == 0) {
            even_sum += *it;
        }
    }
    
    std::cout << "Sum of even numbers: " << even_sum << std::endl;
    
    return 0;
}
