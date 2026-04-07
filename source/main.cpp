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
//    std::vector<int> vec = { 6, 1, 6, 8, 0, 2, 5, 2, 10, 3, 4 };
//    print_vector(vec);
//    introspective_sort<std::vector<int>::iterator>(vec.begin(), vec.end(), std::less<int>());
//    print_vector(vec);

    std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    print_vector(vec);
//    heap_up(1, vec);
//    make_heap(vec.size(), vec);
    void make_heap<std::vector<int>, >(vec.begin(), vec.end(), std::less<int>());
//    std::make_heap(vec.begin(), vec.end());
    print_vector(vec);
    return 0;
}
