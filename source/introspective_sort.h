#include <algorithm>
#include <vector>


//void heap_up(int i, std::vector<int>& arr) {
//    while (arr[i] < arr[(i - 1) / 2]) {
//        std::swap(arr[i], arr[(i - 1) / 2]);
//        i = (i - 1) / 2;
//    }
//}
//
//void make_heap(int first, int second, std::vector<int>& arr) {
//    for (int i = 1; i < second - first; ++i) {
//        heap_up(i, arr);
//    }
//}
template<class RandomIt, class Compare>
void heapify(RandomIt i, int n, RandomIt first, RandomIt second) {

    auto largest = i;

    auto l = 2 * largest + 1;
    auto r = 2 * largest + 2;

    if (l < n && *l > *largest) {
        largest = l;
    }

    if (r < n && *r > *largest) {
        largest = r;
    }

    if (largest != i) {
        std::swap(*largest, *i);

        heapify(largest, n, first, second);
    }
}

template<class RandomIt, class Compare>
void make_heap(RandomIt first, RandomIt second, Compare comp) {
    auto n = second - first;
    for (auto i = first + (n / 2) - 1; i != second; --i) {
        heapify(i, n, first, second);
    }
}

template<class RandomIt, class Compare>
void insertion_sort(RandomIt first, RandomIt second, Compare comp) {
    for (auto i = std::next(first); i != second; i = std::next(i)) {
        auto j = i;
        while (j != first && comp(*j, *(j - 1))) {
            std::swap(*j, *(j - 1));
            j = std::prev(j);
        }
    }
}

template<class RandomIt, class Compare>
void heapsort(RandomIt first, RandomIt second, Compare comp) {
    std::make_heap(first, second, comp);
    for (auto i = second; i != first; --i) {
        std::swap(*first, *(i - 1));
        std::make_heap(first, i - 1);
    }
}


template<class RandomIt, class Compare>
RandomIt partision(RandomIt first, RandomIt second, Compare comp) {
    auto n = second - first;
    if (n == 0)
        return first;
    auto pivot = *second;

    auto i = first - 1;

    for (auto j = first; j != second; ++j) {
        if (comp(*j, pivot)) {
            i += 1;
            if (j != i) {
                std::swap(*i, *j);
            }
        }
    }
    std::swap(*(i + 1), *second);
    return i + 1;
}


//template<class RandomIt>
//void qsort(RandomIt first, RandomIt second) {
//    if (first < second) {
//        auto p = partision(first, second);
//        qsort(first, p - 1);
//        qsort(p + 1, second);
//    }
//}


template<class RandomIt, class Compare>
void introspective_sort_recursive(RandomIt first, RandomIt second, Compare comp, int max_depth, int iteration) {
    size_t n = second - first;
    if (n <= 16)
        insertion_sort(first, second, comp);
    else if (max_depth == 0)
        heapsort(first, second, comp);
    else {
        if (iteration == 0)
            second -= 1;
        auto p = partision(first, second, comp);
        introspective_sort_recursive(first, p - 1, comp, max_depth - 1, iteration + 1);
        introspective_sort_recursive(p + 1, second, comp, max_depth - 1, iteration + 1);
    }
}

template<class RandomIt, class Compare>
void introspective_sort(RandomIt first, RandomIt second, Compare comp) {
    introspective_sort_recursive<RandomIt, Compare>(first, second, comp, 2 * std::log2(second - first), 0);
}