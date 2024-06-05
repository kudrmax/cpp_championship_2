#include <algorithm>


template<typename It, typename Compare>
void insertion_sort(It first, It second, Compare comp) {
    size_t n = second - first;
    for (auto i = std::next(first); i != second; i = std::next(i)) {
        auto j = i;
        while (j != first && comp(*j, *(j - 1))) {
            std::swap(*j, *(j - 1));
            j = std::prev(j);
        }
    }
}

template<typename It, typename Compare>
void heapsort(It first, It second, Compare comp) {
    std::make_heap(first, second, comp);
    for (auto i = second; i != first; --i) {
        std::swap(*first, *(i - 1));
        std::make_heap(first, i - 1);
    }
}


template<typename It, typename Compare>
It partision(It first, It second, Compare comp) {
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


//template<typename It>
//void qsort(It first, It second) {
//    if (first < second) {
//        auto p = partision(first, second);
//        qsort(first, p - 1);
//        qsort(p + 1, second);
//    }
//}


template<typename It, typename Compare>
void introspective_sort_recursive(It first, It second, Compare comp, int max_depth, int iteration) {
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

template<typename It, typename Compare>
void introspective_sort(It first, It second, Compare comp) {
    introspective_sort_recursive<It, Compare>(first, second, comp, 2 * std::log2(second - first), 0);
}