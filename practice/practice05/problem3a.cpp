#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> numbers;
    int num;

    std::cout << "Enter integers (type '0' to end):\n";
    while (std::cin >> num && num != 0) {
        numbers.push_back(num);
    }

    // Printing the squares using std::for_each and a lambda function
    std::cout << "Squared numbers: ";
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n * n << " ";
    });
    std::cout << std::endl;

    // Summing the squares using std::accumulate and a lambda function
    int sum_of_squares = std::accumulate(numbers.begin(), numbers.end(), 0, [](int sum, int n) {
        return sum + n * n;
    });

    std::cout << "Sum of squares: " << sum_of_squares << std::endl;

    return 0;
}
