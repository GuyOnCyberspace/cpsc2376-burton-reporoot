#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> numbers;
    int num;

    std::cout << "Enter integers (type '0' to end):\n";
    while (std::cin >> num && num != 0) {
        numbers.push_back(num);
    }

    // Calculating the sum using std::accumulate
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    // Calculating the product using std::accumulate
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());

    std::cout << "Sum of all elements: " << sum << std::endl;
    std::cout << "Product of all elements: " << product << std::endl;

    return 0;
}
