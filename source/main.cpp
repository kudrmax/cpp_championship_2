#include <iostream>
#include <algorithm>
#include <vector>

void print_vector(const std::vector<int>& vec) {
    for (const auto& n: vec) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
}

template<typename It>
void introspective_sort(It first, It second) {
    auto max_depth = 2 * std::log(second - first);
    introspective_sort_recursive(first, second, max_depth);

}

template<typename It>
void introspective_sort_recursive(It first, It second, int max_depth) {
    size_t n = second - first;
    if (n <= 16)
        insertion_sort(first, second);
    else if (max_depth == 0)
        heapsort(first, second);
    else {
        // qsort
    }
}

template<typename It>
void insertion_sort(It first, It second) {
    size_t n = second - first;
    for (auto i = std::next(first); i != second; i = std::next(i)) {
        auto j = i;
        while (j != first && *j < *(j - 1)) {
            std::swap(*j, *(j - 1));
            j = std::prev(j);
        }
    }
}

template<typename It>
void heapsort(It first, It second) {
    std::make_heap(first, second);
    for (auto i = second; i != first; --i) {
        std::swap(*first, *(i - 1));
        std::make_heap(first, i - 1); // @todo написать свой make_heap
    }
}


void heapsort(int first, int second, std::vector<int>& arr) {
    std::make_heap(arr.begin(), arr.end());
    auto n = second - first;
    for (int i = n - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        std::make_heap(arr.begin(), arr.begin() + i); // @todo написать свой make_heap
    }
}

int main() {
    std::vector<int> vec = { 6, 1, 6, 8, 0, 2, 5, 2, 10, 3, 4 };
    print_vector(vec);
//    insertion_sort<std::vector<int>::iterator>(vec.begin(), vec.end());
//    insertion_sort(0, vec.size(), vec);
//    heapsort(0, vec.size(), vec);
//    heapsort<std::vector<int>::iterator>(vec.begin(), vec.end());
    print_vector(vec);

    return 0;
}
