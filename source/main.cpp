#include <iostream>
#include <vector>
#include "introspective_sort.h"

void print_vector(const std::vector<int>& vec) {
    for (const auto& n: vec) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec = { 6, 1, 6, 8, 0, 2, 5, 2, 10, 3, 4 };
    print_vector(vec);
    introspective_sort<std::vector<int>::iterator>(vec.begin(), vec.end(), std::less<int>());
    print_vector(vec);
    return 0;
}
