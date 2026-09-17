//
// Created by Артемий on 18/09/2026.
//

#include "J.h"

void J::pyramid_sort(Heap& heap) {
    while (heap.limit > 1) {
        heap.pop_front();
    }
}

void J::solve() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) std::cin >> arr[i];

    Heap heap(arr);
    pyramid_sort(heap);

    for (auto& el : heap.arr) std::cout << el << ' ';
    std::cout << std::endl;
}
