#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers;
    int num, threshold;

    std::cout << "Enter integers (type '0' to end):\n";
    while (std::cin >> num && num != 0) {
        numbers.push_back(num);
    }

    std::cout << "Enter threshold value: ";
    std::cin >> threshold;

    // Counting elements greater than the threshold using std::count_if and a lambda
    int count_above_threshold = std::count_if(numbers.begin(), numbers.end(), [threshold](int n) {
        return n > threshold;
    });

    std::cout << "Number of elements greater than " << threshold << ": " << count_above_threshold << std::endl;

    // Removing elements below the threshold using std::remove_if and a lambda
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [threshold](int n) {
        return n < threshold;
    }), numbers.end());

    // Printing the modified list
    std::cout << "Modified list (values >= threshold): ";
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
