#include <iostream>
#include <algorithm>
#include <vector>

void print_vector(const std::vector<int>& vec) {
    for (const auto& n: vec) {
        std::cout << n;
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
    for (auto it_pivot = std::next(first); it_pivot != second; it_pivot = std::next(it_pivot)) {
        auto it = std::prev(it_pivot);
        while (*it_pivot > *it)
            it = std::prev(it);
        std::swap(*it_pivot, *it);
    }
}

void insertion_sort(int first, int second, std::vector<int>& vec) {
    size_t n = second - first;
    for (int i = 1; i < n; ++i) {
        auto j = i;
        while (j > 0 && vec[j] < vec[j - 1]) {
            std::swap(vec[j], vec[j - 1]);
            j -= 1;
        }
    }


//    for (int i_pivot = 1; i_pivot < n; ++i_pivot) {
//        auto i = i_pivot - 1;
//        while (i >= 0 && vec[i] > vec[i_pivot])
//            i -= 1;
//        std::swap(vec[i], vec[i_pivot]);
//    }
//    for (auto it_pivot = std::next(first); it_pivot != second; it_pivot = std::next(it_pivot)) {
//        auto it = std::prev(it_pivot);
//        while (*it_pivot > *it)
//            it = std::prev(it);
//        std::swap(*it_pivot, *it);
//    }
    print_vector(vec);
}


template<typename It>
void heapsort(It first, It second);


int main() {
//    std::cout <<  << std::endl;
    std::vector<int> vec = { 1, 2, 6, 5, 4 };
    print_vector(vec);
//    insertion_sort<std::vector<int>::iterator>(vec.begin(), vec.end());
    insertion_sort(0, vec.size(), vec);
    print_vector(vec);

    return 0;
}
