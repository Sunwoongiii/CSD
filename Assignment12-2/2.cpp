#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <cmath>
#include <algorithm>

template <typename T>
void print_stats(const T& container) {
    if (container.empty()) {
        std::cout << "Container is empty." << std::endl;
        return;
    }

    double sum = 0;
    double min_val = *std::min_element(container.begin(), container.end());
    double max_val = *std::max_element(container.begin(), container.end());
    std::vector<typename T::value_type> sorted_container(container.begin(), container.end());
    std::sort(sorted_container.begin(), sorted_container.end());

    double median = 0;
    if (sorted_container.size() % 2 == 0) {
        median = (sorted_container[sorted_container.size() / 2 - 1] + sorted_container[sorted_container.size() / 2]) / 2.0;
    } else {
        median = sorted_container[sorted_container.size() / 2];
    }

    for (const auto& num : container) {
        sum += num;
    }
    double average = sum / container.size();

    double variance_sum = 0;
    for (const auto& num : container) {
        variance_sum += std::pow(num - average, 2);
    }
    double variance = variance_sum / container.size();
    double std_dev = std::sqrt(variance);

    std::cout << "Minimum: " << min_val << std::endl;
    std::cout << "Maximum: " << max_val << std::endl;
    std::cout << "Median: " << median << std::endl;
    std::cout << "Average: " << average << std::endl;
    std::cout << "Variance: " << variance << std::endl;
    std::cout << "Standard Deviation: " << std_dev << std::endl;
}

int main() {
    std::vector<int> vec = {5, 3, 9, 1, 6};
    print_stats(vec);

    std::list<double> lst = {2.5, 3.5, 1.5, 4.5};
    print_stats(lst);

    std::deque<int> deq = {7, 2, 8, 3, 5};
    print_stats(deq);

    std::array<int, 4> arr = {1, 4, 2, 3};
    print_stats(arr);

    std::forward_list<int> flist = {11, 7, 13, 9};
    print_stats(flist);

    return 0;
}
