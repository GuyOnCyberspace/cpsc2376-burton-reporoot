#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers;
    int num;

    std::cout << "Enter integers (type '0' to end):\n";
    while (std::cin >> num && num != 0) {
        numbers.push_back(num);
    }

    // Finding the largest element using std::max_element
    auto max_it = std::max_element(numbers.begin(), numbers.end());
    auto min_it = std::min_element(numbers.begin(), numbers.end());

    std::cout << "Largest element: " << *max_it << std::endl;
    std::cout << "Smallest element: " << *min_it << std::endl;

    return 0;
}
